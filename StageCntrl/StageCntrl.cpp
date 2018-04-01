#include "StageCntrl.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include "arduinoComm.h"
#include "ValveCntrl.h"
#include "PumpCntrl.h"
#include "DC_Motor.h"
#include "HeatCntrl.h"
pthread_mutex_t fluid_tran;
pthread_mutex_t barrier;

pthread_cond_t cond_barrier;
StageCntrl::StageCntrl(bparam_t* batches, int numBatches){
	c_batches = batches;
	num_batches = numBatches;
}
int stage;
int max_numStages;
typedef struct heatParam{
	StageCntrl* ptr;
	int batchnum;
}heatParam_t;
void* DC_Thread_Helper(void* arg){
	
	StageCntrl * ptr = (StageCntrl*) arg;
	ptr->DC_mixCntrl(NULL);

}
void* heat_Thread_Helper(void* arg){
	
	heatParam_t* carg = (heatParam_t*)arg;
	StageCntrl * ptr = (StageCntrl*) (carg->ptr);
	int batchnum = (int)( carg->batchnum);
	ptr->heatThread((void*)(&batchnum));


}
int StageCntrl::startThreads(){
	pthread_t batches[num_batches];
	int batch_index[num_batches+1];
	pthread_t mix_thread;

	for(int i = 0; i<num_batches; i++){
		batch_index[i]=i;
		heatParam_t* threadParam;
		threadParam->ptr = this;
		threadParam->batchnum = i;
		pthread_create(&batches[i],NULL,heat_Thread_Helper,threadParam);
	}
	pthread_create(&mix_thread,NULL, DC_Thread_Helper,this);
	for(int i = 0; i<num_batches; i++){

		pthread_join(batches[i],NULL);

	}
	pthread_join(mix_thread,NULL);

}
StageCntrl::~StageCntrl(){


}
//The purpose of using threads here is that there
//are some aspects of control that need to be done concurrently.
//...mainly heat control. The other stuff is done sequentially
void* StageCntrl::DC_mixCntrl(void*){
	int batchnum =0;
	int file = openArduino();
	sendArduino("m1",file);
	for(int i =0; i<100; i++){
		sendArduino("mu",file);
		usleep(100000);
	}
	int duration=0;
	int pad=0;
	if(stage == 0){
		duration = c_batches[batchnum].stg1.mixtime;
	}
	else if(stage == 1){
		duration = c_batches[batchnum].stg2.mixtime;
	}
	else if(stage == 2){
		duration = c_batches[batchnum].stg3.mixtime;
	}
	else if(stage == 3){
		duration = c_batches[batchnum].stg4.mixtime;
	}
	else if(stage == 4){
		duration = c_batches[batchnum].stg5.mixtime;
	}
	struct timeval tv;
	gettimeofday(&tv,NULL);
	int targetTime = tv.tv_sec+(int)duration;
	while(1){
		gettimeofday(&tv,NULL);
		if(tv.tv_sec > targetTime)
			break;
	}
	for(int i =0; i<100; i++){
		sendArduino("md",file);
		usleep(100000);
	}
	sendArduino("m0",file);
	closeArduino(file);

}
long readWeight(){
	int file = openArduino();
	sendArduino("d",file);
	char recvbuf[256];
	recvArduino(recvbuf,file);
	int char_count=0;
	int reading_count=0;
	int readings[4];
	long reading_sum=0;
	while(reading_count<4){

		if(recvbuf[char_count]=='b'){
			reading_count++;
		}
		else{
			readings[reading_count]*=10;
			readings[reading_count]+=recvbuf[char_count];

		}
		char_count++;


	}

	for(int ii=0; ii<3; ii++){
		reading_sum+=readings[ii];

	}
	return reading_sum;

}
int StageCntrl::executeBatch(){
	int stagecnt = (c_batches[0]).numStages;
	int i = 0;
	ValveCntrl valve1(VALVE_1);
	ValveCntrl valve2(VALVE_2);
	ValveCntrl valve3(VALVE_3);
	ValveCntrl valve4(VALVE_4);
	ValveCntrl valve5(VALVE_5);
	PumpCntrl pump1(PERI_PWM1,PERI12_DIR,SYRINGE1);
	PumpCntrl pump2(PERI_PWM2,PERI12_DIR,SYRINGE2);
	PumpCntrl pump3(PERISTALLTIC120,0,SYRINGE3);
	PumpCntrl pump4(PERISTALLTIC120_2,0,SYRINGE4);
	PumpCntrl pump5(PERISTALLTIC120_3,0,SYRINGE5);
	for(i=0;i<stagecnt; i++){
		for(int j=0; j<num_batches; j++){
			stage=i;

			ValveCntrl *valve_ptr;
			PumpCntrl *pump_ptr;
		//Fluid transfer for each batch
			int position = 0;
			double fluid_amount =0;

			if(i==0){
				fluid_amount = c_batches[j].stg1.fluidAmnt;
				valve_ptr = &valve1;
				pump_ptr = &pump1;
			}
			else if(i==1){
				fluid_amount = c_batches[j].stg2.fluidAmnt;
				valve_ptr = &valve2;
				pump_ptr = &pump2;
			}
			else if(i==2){
				fluid_amount = c_batches[j].stg3.fluidAmnt;
				valve_ptr = &valve3;
				pump_ptr = &pump3;
			}
			else if(i==3){
				fluid_amount = c_batches[j].stg4.fluidAmnt;
				valve_ptr = &valve4;
				pump_ptr = &pump4;
			}
			else if(i==4){
				fluid_amount = c_batches[j].stg5.fluidAmnt;
				valve_ptr = &valve5;
				pump_ptr = &pump5;
			}
			if(j==0){
				position = BEAKER1_POS;
				
			}
			else if(j==1){
				position = BEAKER2_POS;
			}
			else if(j==2){
				position = BEAKER3_POS;
			}
			else if(j==3){
				position = BEAKER4_POS;
			}
#if BETA_DEMO
			if(i==0)//make i==0 || i==1 but we only have one syringe pump rn
			{
				//
				valve_ptr->moveValve(position);
				pump_ptr->fillsyringePump(fluid_amount);
				valve_ptr->openValve();
				pump_ptr->dispenseSyringePump(fluid_amount);
				valve_ptr->closeValve();	
			}
			else{
				valve_ptr->moveValve(position);
				
				long old_weight=readWeight();
				while(1){
					valve_ptr->openValve();
					pump_ptr->activatePump();
					usleep(PUMP_QUANTA);
					pump_ptr->deactivatePump();
					valve_ptr->closeValve();
					usleep(SETTLING_TIME);
					//Measure weight...
					
					long new_weight=readWeight();
					if(fluid_amount*LOAD_CELL_CONV<(new_weight-old_weight))
						break;

				}
			}
#else
			valve_ptr->moveValve(position);
			pump_ptr->fillsyringePump(fluid_amount);
			valve_ptr->openValve();
			pump_ptr->dispenseSyringePump(fluid_amount);
			valve_ptr->closeValve();	
#endif			
			//Done with Fluid transfer
	
		}
		valve5.moveValve(GARBAGE);
		//Heating and stirring
		startThreads();


		//Done with stage
	}
}
void* StageCntrl::heatThread(void* args){
	int batchnum = *((int*)args);
	//We use "stage" to determine what stage we are at
	int duration=0;
	double targetTemp=0;
	int pad=0;
	if(stage == 0){
		duration = c_batches[batchnum].stg1.heattime;
		targetTemp = c_batches[batchnum].stg1.targetTemp;
	}
	else if(stage == 1){
		duration = c_batches[batchnum].stg2.heattime;
		targetTemp = c_batches[batchnum].stg2.targetTemp;
	}
	else if(stage == 2){
		duration = c_batches[batchnum].stg3.heattime;
		targetTemp = c_batches[batchnum].stg3.targetTemp;
	}
	else if(stage == 3){
		duration = c_batches[batchnum].stg4.heattime;
		targetTemp = c_batches[batchnum].stg4.targetTemp;
	}
	else if(stage == 4){
		duration = c_batches[batchnum].stg5.heattime;
		targetTemp = c_batches[batchnum].stg5.targetTemp;
	}
	if(batchnum==0){
		pad = HEATPAD1_PIN;
	}
	else if(batchnum==1){
		pad = HEATPAD2_PIN;
	}
	else if(batchnum==2){
		pad = HEATPAD3_PIN;
	}
	else if(batchnum==3){
		pad = HEATPAD4_PIN;
	}

	HeatCntrl* h = new HeatCntrl(pad);
	h->setDesiredTemp(targetTemp,(double)duration);



}
