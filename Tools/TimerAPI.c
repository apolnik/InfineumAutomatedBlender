// Header Files
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
typedef sem_t RTOS_SEM;
/*****************************************************
 * Global Variables
 *****************************************************
 */
// Timer Pool Global Variables
INT8U FreeTmrCount = 0;
RTOS_TMR *FreeTmrListPtr = NULL;

// Tick Counter
INT32U RTOSTmrTickCtr = 0;

// Hash Table
HASH_OBJ hash_table[HASH_TABLE_SIZE];

// Thread variable for Timer Task
pthread_t thread;

// Semaphore for Signaling the Timer Task
sem_t time_task_sem;

// Mutex for Protecting Hash Table
pthread_mutex_t hash_table_mutex;

// Mutex for Protecting Timer Pool
pthread_mutex_t timer_pool_mutex;

void RTOSSemPost(RTOS_SEM *timerSemPtr){
	sem_post(&timerSemPtr);

}
void RTOSSemPend(RTOS_SEM *timerSemPtr){
	sem_wait(&time_task_sem);
}
void RTOSSemCreate(RTOS_SEM *timerSemPtr){
	sem_init(&timerSemPtr,0,1);

}

/*****************************************************
 * Timer API Functions
 *****************************************************
 */

// Function to create a Timer
RTOS_TMR* RTOSTmrCreate(INT32U delay, INT32U period, INT8U option, RTOS_TMR_CALLBACK callback, void *callback_arg, INT8	*name, INT8U *err)
{
	RTOS_TMR *timer_obj = NULL;
	//fprintf(stdout, "Checking for errors... \n");
	// Check the input Arguments for ERROR
	if(delay<0 && option == RTOS_TMR_ONE_SHOT){
		*err=RTOS_ERR_TMR_INVALID_DLY;
		return NULL;
	}
	else if(period<0 && option == RTOS_TMR_PERIODIC){
		*err=RTOS_ERR_TMR_INVALID_PERIOD;
		return NULL;
	}
	else if(option !=RTOS_TMR_PERIODIC && option !=RTOS_TMR_ONE_SHOT){
		*err=RTOS_ERR_TMR_INVALID_OPT;
		return NULL;
	}
	else{
		*err = RTOS_ERR_NONE;

	}
	//fprintf(stdout, "No errors found! \n");
	// Allocate a New Timer Obj
	timer_obj = alloc_timer_obj();
	
	if(timer_obj == NULL) {
		// Timers are not available
		*err = RTOS_ERR_TMR_NON_AVAIL;
		return NULL;
	}
	//fprintf(stdout, "Timer allocated from free pool \n");
	// Fill up the Timer Object
	timer_obj->RTOSTmrType = RTOS_TMR_TYPE;
	timer_obj->RTOSTmrCallback = callback;
	timer_obj->RTOSTmrCallbackArg = callback_arg;
	if(option == RTOS_TMR_PERIODIC) 
		timer_obj->RTOSTmrMatch = RTOSTmrTickCtr+period;
	else if(option == RTOS_TMR_ONE_SHOT)
		timer_obj->RTOSTmrMatch = RTOSTmrTickCtr+delay;
	timer_obj->RTOSTmrDelay = delay;
	timer_obj->RTOSTmrPeriod = period;
	timer_obj->RTOSTmrName = name;
	timer_obj->RTOSTmrOpt = option;
	timer_obj->RTOSTmrState = RTOS_TMR_STATE_STOPPED;


	
	
	//Return timer
	*err = RTOS_SUCCESS;

	return timer_obj;
}

// Function to Delete a Timer
INT8U RTOSTmrDel(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking
	if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		return RTOS_FALSE;
	}
	
	else if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState == 0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		return RTOS_FALSE;
	}
	else if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		return RTOS_FALSE;
	}
	else{
		*perr = RTOS_ERR_NONE;
	}
	// Free Timer Object according to its State
	ptmr->RTOSTmrState = RTOS_TMR_STATE_UNUSED;
	remove_hash_entry(ptmr);
	FreeTmrCount++;
	RTOS_TMR* temp = FreeTmrListPtr;
	if(temp == NULL){
		FreeTmrListPtr = ptmr;
		return RTOS_TRUE;
	}
	while(temp->RTOSTmrNext != NULL){
		temp=temp->RTOSTmrNext;
	}
	temp->RTOSTmrNext = ptmr;
	ptmr->RTOSTmrNext = NULL;
	ptmr->RTOSTmrPrev = temp;
	*perr = RTOS_SUCCESS;
	return RTOS_TRUE;
}

// Function to get the Name of a Timer
INT8* RTOSTmrNameGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking
	if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		
	}
	
	else if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState == 0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		
	}
	else if(ptmr->RTOSTmrState == RTOS_TMR_STATE_UNUSED){
		*perr = RTOS_ERR_TMR_INACTIVE;
		return RTOS_FALSE;
	} 
	else if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		
	}
	else{
		*perr = RTOS_ERR_NONE;
	}
	// Return the pointer to the String
	return ptmr->RTOSTmrName;
	

}

// To Get the Number of ticks remaining in time out
INT32U RTOSTmrRemainGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking
	if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		return RTOS_FALSE;

	}
	else if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState != RTOS_TMR_STATE_RUNNING){
		*perr = RTOS_ERR_TMR_INACTIVE;
		return RTOS_FALSE;
	} 
	else if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState == 0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		return RTOS_FALSE;
	}
	else
		*perr = RTOS_ERR_NONE;
	// Return the remaining ticks
	
	INT32U remaining;
	if(ptmr->RTOSTmrMatch>=RTOSTmrTickCtr)
		remaining = ptmr->RTOSTmrMatch - RTOSTmrTickCtr;
	else
		remaining = RTOSTmrTickCtr - ptmr->RTOSTmrMatch;
	return remaining;
}

// To Get the state of the Timer
INT8U RTOSTmrStateGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking
	if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		
	}
	
	else if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState == 0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		
	}
	else if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		
	}
	else{
		*perr = RTOS_ERR_NONE;
	}
	// Return State
	return ptmr->RTOSTmrState;
}

// Function to start a Timer
INT8U RTOSTmrStart(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking
	//fprintf(stdout, "Checking for errors... \n");
	if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState == RTOS_TMR_STATE_UNUSED){
		*perr = RTOS_ERR_TMR_INACTIVE;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState == 0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		return RTOS_FALSE;
	}
	else if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		return RTOS_FALSE;
	}
	else{
		*perr = RTOS_ERR_NONE;
	}
	//fprintf(stdout, "No errors... \n");
	// Based on the Timer State, update the RTOSTmrMatch using RTOSTmrTickCtr, RTOSTmrDelay and RTOSTmrPeriod
	if(ptmr->RTOSTmrOpt == RTOS_TMR_PERIODIC) 
		ptmr->RTOSTmrMatch = RTOSTmrTickCtr+ptmr->RTOSTmrPeriod;
	else if(ptmr->RTOSTmrOpt == RTOS_TMR_ONE_SHOT)
		ptmr->RTOSTmrMatch = RTOSTmrTickCtr+ptmr->RTOSTmrDelay;
	// You may use the Hash Table to Insert the Running Timer Obj
	//fprintf(stdout, "Inserting into Hash table... \n");
	insert_hash_entry(ptmr);
	//fprintf(stdout, "Insert successful... \n");
	ptmr->RTOSTmrState = RTOS_TMR_STATE_RUNNING;
	return RTOS_TRUE;
}

// Function to Stop the Timer
INT8U RTOSTmrStop(RTOS_TMR *ptmr, INT8U opt, void *callback_arg, INT8U *perr)
{
	// ERROR Checking
	if(ptmr->RTOSTmrState > 4 || ptmr->RTOSTmrState==0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		return RTOS_FALSE;
	}
	else if(ptmr == NULL){
		*perr = RTOS_ERR_TMR_INVALID;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrType != RTOS_TMR_TYPE){
		*perr = RTOS_ERR_TMR_INVALID_TYPE;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState != RTOS_TMR_STATE_RUNNING){
		*perr = RTOS_ERR_TMR_INACTIVE;
		return RTOS_FALSE;
	} 
	else if(opt>3 || opt == 0){
		*perr = RTOS_ERR_TMR_INVALID_OPT;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState == RTOS_TMR_STATE_STOPPED){
		*perr = RTOS_ERR_TMR_STOPPED;
		return RTOS_FALSE;
	}
	else if(ptmr->RTOSTmrState>4 || ptmr->RTOSTmrState==0){
		*perr = RTOS_ERR_TMR_INVALID_STATE;
		return RTOS_FALSE;
	}
	else if(opt != 1 && ptmr->RTOSTmrCallback == NULL){
		*perr = RTOS_ERR_TMR_NO_CALLBACK;
		return RTOS_FALSE;
	}
	else{
		*perr = RTOS_ERR_NONE;
	}
	// Remove the Timer from the Hash Table List
	remove_hash_entry(ptmr);

	// Change the State to Stopped
	ptmr->RTOSTmrState = RTOS_TMR_STATE_STOPPED;
	// Call the Callback function if required
	if(opt == RTOS_TMR_OPT_CALLBACK){
		ptmr->RTOSTmrCallback(ptmr->RTOSTmrCallbackArg);
	}
	else if(opt == RTOS_TMR_OPT_CALLBACK_ARG){
		ptmr->RTOSTmrCallback(callback_arg);
	}


	return RTOS_TRUE;
}

// Function called when OS Tick Interrupt Occurs which will signal the RTOSTmrTask() to update the Timers
void RTOSTmrSignal(int signum)
{
	// Received the OS Tick
	// Send the Signal to Timer Task using the Semaphore
	sem_post(&time_task_sem);

}

/*****************************************************
 * Internal Functions
 *****************************************************
 */

// Create Pool of Timers
INT8U Create_Timer_Pool(INT32U timer_count)
{
	// Create the Timer pool using Dynamic Memory Allocation
	// You can imagine of LinkedList Creation for Timer Obj
	FreeTmrCount = timer_count;
	FreeTmrListPtr =  (RTOS_TMR *)malloc(timer_count * sizeof(RTOS_TMR));
	for(int i=0; i<timer_count; i++){
		if(i<timer_count-1)
			FreeTmrListPtr[i].RTOSTmrNext = &FreeTmrListPtr[i+1];
		else
			FreeTmrListPtr[i].RTOSTmrNext = NULL;
		if(i>0)
			FreeTmrListPtr[i].RTOSTmrPrev = &FreeTmrListPtr[i-1];
		else
			FreeTmrListPtr[i].RTOSTmrPrev = NULL;
		FreeTmrListPtr[i].RTOSTmrState = RTOS_TMR_STATE_UNUSED;
		FreeTmrListPtr[i].RTOSTmrType = RTOS_TMR_TYPE;
	}
	// Mutex for Protecting Timer Pool
	pthread_mutex_init(&timer_pool_mutex,NULL);
	if(FreeTmrListPtr == NULL)
		return RTOS_MALLOC_ERR;


	return RTOS_SUCCESS;
}

// Initialize the Hash Table
void init_hash_table(void)
{
	//hash_table should be empty more or less
	for(int i=0; i< HASH_TABLE_SIZE; i++){
		hash_table[i].timer_count=0;
		hash_table[i].list_ptr = NULL;
		
	}
	// Mutex for Protecting Hash Table
	
	pthread_mutex_init(&hash_table_mutex,NULL);
}

// Insert a Timer Object in the Hash Table
void insert_hash_entry(RTOS_TMR *timer_obj)
{
	// Calculate the index using Hash Function
	//fprintf(stdout, "Calculating index for hash... \n");
	INT32U index = timer_obj->RTOSTmrMatch % HASH_TABLE_SIZE;
	// Lock the Resources
	pthread_mutex_lock(&hash_table_mutex);
	
	//fprintf(stdout, "Mutex locked for hash... \n");
	// Add the Entry
	RTOS_TMR* temp = hash_table[index].list_ptr;
	hash_table[index].timer_count+=1;
	int count =0;
	while(temp!=NULL){
		count++;
		if(temp->RTOSTmrMatch < timer_obj->RTOSTmrMatch)
			temp = temp->RTOSTmrNext;
		else
			break;	

	}
	if(temp == NULL && count == 0){
		//fprintf(stdout, "Creating hash entry...%i \n",index);
		hash_table[index].list_ptr = timer_obj;
		timer_obj->RTOSTmrNext = NULL;
		timer_obj->RTOSTmrPrev = NULL;	
	}
	else if(temp == NULL){
		temp = hash_table[index].list_ptr;
		while(temp->RTOSTmrNext!=NULL)
			temp = temp->RTOSTmrNext;
		temp->RTOSTmrNext = timer_obj;
		timer_obj->RTOSTmrNext = NULL;
		timer_obj->RTOSTmrPrev = temp;
	}
	else{
		
		if(temp == hash_table[index].list_ptr){
			
			hash_table[index].list_ptr = timer_obj;
			timer_obj->RTOSTmrNext = temp;
			temp->RTOSTmrPrev = timer_obj;
			timer_obj->RTOSTmrPrev = NULL;
		}
		else{		
			//fprintf(stdout, "Inserting hash entry... \n");
			if(temp->RTOSTmrPrev !=NULL && temp!=NULL)
				temp->RTOSTmrPrev->RTOSTmrNext = timer_obj;
			if(temp!=NULL){
				timer_obj->RTOSTmrPrev = temp->RTOSTmrPrev;
				temp->RTOSTmrPrev = timer_obj;
			}		
			timer_obj->RTOSTmrNext = temp;
			//timer_obj->RTOSTmrNext = temp->RTOSTmrNext;
		}
		
	}
	// Unlock the Resources
	pthread_mutex_unlock(&hash_table_mutex);
}

// Remove the Timer Object entry from the Hash Table
void remove_hash_entry(RTOS_TMR *timer_obj)
{
	// Calculate the index using Hash Function
	INT32U index = timer_obj->RTOSTmrMatch % HASH_TABLE_SIZE;
	// Lock the Resources
	pthread_mutex_lock(&hash_table_mutex);

	// Remove the Timer Obj
	RTOS_TMR* temp = hash_table[index].list_ptr;
	hash_table[index].timer_count-=1;
	if(temp != timer_obj){
					//fprintf(stdout, "Something is off... \n");
		timer_obj->RTOSTmrPrev->RTOSTmrNext = timer_obj->RTOSTmrNext;
		timer_obj->RTOSTmrNext->RTOSTmrPrev = timer_obj->RTOSTmrPrev;
		timer_obj->RTOSTmrNext = NULL;
		timer_obj->RTOSTmrPrev = NULL;
	}
	else{
					//fprintf(stdout, "ok... \n");
		hash_table[index].list_ptr = temp->RTOSTmrNext;
		if(hash_table[index].list_ptr != NULL)
			hash_table[index].list_ptr->RTOSTmrPrev = NULL;
		timer_obj->RTOSTmrNext = NULL;
		timer_obj->RTOSTmrPrev = NULL;
	}
	// Unlock the Resources
	pthread_mutex_unlock(&hash_table_mutex);
}

// Timer Task to Manage the Running Timers
void *RTOSTmrTask(void *temp2)
{

	while(1) {
		// Wait for the signal from RTOSTmrSignal()

		sem_wait(&time_task_sem);
		
		
		

		// Once got the signal, Increment the Timer Tick Counter
		RTOSTmrTickCtr++;
		//fprintf(stdout, "TimerTask: Checking hash table... \n");
		// Check the whole List associated with the index of the Hash Table
		// Compare each obj of linked list for Timer Completion
		// If the Timer is completed, Call its Callback Function, Remove the entry from Hash table
		// If the Timer is Periodic then again insert it in the hash table
		// Change the State
		INT32U index = RTOSTmrTickCtr % HASH_TABLE_SIZE;
		RTOS_TMR* temp3 = hash_table[index].list_ptr;
				//fprintf(stdout,"%i \n",index);
				
		if(temp3!=NULL)
		while(temp3->RTOSTmrMatch == RTOSTmrTickCtr && temp3 !=NULL){
			//fprintf(stdout, "Times match... \n");
			//fprintf(stdout, temp3->RTOSTmrName);
			//fprintf(stdout, " %i \n", temp3->RTOSTmrMatch);
			temp3->RTOSTmrCallback(temp3->RTOSTmrCallbackArg);
			RTOS_TMR* temp4 = temp3->RTOSTmrNext;
			//fprintf(stdout, "Removing from hash table... \n");
			remove_hash_entry(temp3);
						//fprintf(stdout, "Successfully removed from table... \n");
			if(temp3->RTOSTmrOpt == RTOS_TMR_PERIODIC){
				temp3->RTOSTmrMatch = temp3->RTOSTmrPeriod + RTOSTmrTickCtr;
				insert_hash_entry(temp3);
			}
			else{
				temp3->RTOSTmrState = RTOS_TMR_STATE_COMPLETED;			
				
				//fprintf(stdout, "Changing State... \n");
			}
			temp3 = temp4;
			if(temp3 == NULL) break;
 
		}

		
	}
	return temp2;
}

// Timer Initialization Function
void RTOSTmrInit(void)
{
	INT32U timer_count = 0;
	INT8U	retVal;
	pthread_attr_t attr;

	fprintf(stdout,"\n\nPlease Enter the number of Timers required in the Pool for the OS ");
	scanf("%d", &timer_count);

	// Create Timer Pool
	retVal = Create_Timer_Pool(timer_count);

	// Check the return Value
	if(retVal!=RTOS_SUCCESS)
	{
		
		fprintf(stdout,"\n\nFailure in creating timer pool! Aborting... ");			
		return;
	}
	// Init Hash Table
	init_hash_table();

	fprintf(stdout, "\n\nHash Table Initialized Successfully\n");





	// Initialize Semaphore for Timer Task
	sem_init(&time_task_sem,0,1);
	// Initialize Mutex if any
	
	// Create any Thread if required for Timer Task
	pthread_create(&thread,NULL,RTOSTmrTask,NULL);
	fprintf(stdout,"\nRTOS Initialization Done...\n");
}

// Allocate a timer object from free timer pool
RTOS_TMR* alloc_timer_obj(void)
{


	//fprintf(stdout, "... \n");
	// Lock the Resources
	pthread_mutex_lock(&timer_pool_mutex);
	//fprintf(stdout, "\Attempting to allocate timer object... \n");
	// Check for Availability of Timers
	if(FreeTmrCount <=0){
		pthread_mutex_unlock(&timer_pool_mutex);
		return NULL;	

	}
	//fprintf(stdout, "Free timer available... \n");
	// Assign the Timer Object
	FreeTmrCount--;
	RTOS_TMR* temp= FreeTmrListPtr;
	while(temp->RTOSTmrState != RTOS_TMR_STATE_UNUSED)
		temp = temp->RTOSTmrNext;
	
	//fprintf(stdout, "Free timer found... \n");
	if(temp != FreeTmrListPtr){
		temp->RTOSTmrPrev->RTOSTmrNext = temp->RTOSTmrNext;
		temp->RTOSTmrNext->RTOSTmrPrev = temp->RTOSTmrPrev;
		temp->RTOSTmrNext = NULL;
		temp->RTOSTmrPrev = NULL;
	}
	else{
		//fprintf(stdout, "\First timer in linked list... \n");
		FreeTmrListPtr = temp->RTOSTmrNext;
		if(FreeTmrListPtr != NULL)
			FreeTmrListPtr->RTOSTmrPrev = NULL;
		
		temp->RTOSTmrNext = NULL;
		temp->RTOSTmrPrev = NULL;
	}
	
	// Unlock the Resources
	
	pthread_mutex_unlock(&timer_pool_mutex);
	//fprintf(stdout, "Returning free timer... \n");
	return temp;
}

// Free the allocated timer object and put it back into free pool
void free_timer_obj(RTOS_TMR *ptmr)
{
	// Lock the Resources
	pthread_mutex_lock(&timer_pool_mutex);
	// Clear the Timer Fields
	ptmr->RTOSTmrPeriod=0;
	ptmr->RTOSTmrDelay=0;
	ptmr->RTOSTmrOpt=0;
	ptmr->RTOSTmrName=NULL;
	ptmr->RTOSTmrCallbackArg=NULL;
	ptmr->RTOSTmrCallback=NULL;
	
	// Change the State
	ptmr->RTOSTmrState = RTOS_TMR_STATE_UNUSED;
	// Return the Timer to Free Timer Pool
	RTOS_TMR* temp = FreeTmrListPtr;
	if(temp == NULL){
		temp = ptmr;
		ptmr->RTOSTmrNext = NULL;
		ptmr->RTOSTmrPrev = NULL;
	}
	else{
		while(temp->RTOSTmrNext != NULL)
			temp = temp->RTOSTmrNext;

		temp->RTOSTmrNext = ptmr;
		ptmr->RTOSTmrPrev = temp;
		ptmr->RTOSTmrNext = NULL;
	}
	// Unlock the Resources
	pthread_mutex_unlock(&timer_pool_mutex);
}

// Function to Setup the Timer of Linux which will provide the Clock Tick Interrupt to the Timer Manager Module
void OSTickInitialize(void) {	
	timer_t timer_id;
	struct itimerspec time_value;

	// Setup the time of the OS Tick as 100 ms after 3 sec of Initial Delay
	time_value.it_interval.tv_sec = 0;
	time_value.it_interval.tv_nsec = RTOS_CFG_TMR_TASK_RATE;

	time_value.it_value.tv_sec = 0;
	time_value.it_value.tv_nsec = RTOS_CFG_TMR_TASK_RATE;

	// Change the Action of SIGALRM to call a function RTOSTmrSignal()
	signal(SIGALRM, &RTOSTmrSignal);

	// Create the Timer Object
	timer_create(CLOCK_REALTIME, NULL, &timer_id);

	// Start the Timer
	timer_settime(timer_id, 0, &time_value, NULL);
}

