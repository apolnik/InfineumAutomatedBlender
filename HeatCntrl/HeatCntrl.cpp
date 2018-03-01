#include "gpioTool.h"
#include "HeatCntrl.h"
#include "SysParam.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "sys/wait.h"
//Make sure to make a new p_thread when using the heater otherwise
//you will probably block all the other stuff you need to do.
//make sure to kill the p_thread when done with it.
typedef struct{
	double Kp;
	double Ki;
	double Kd;
} PID;
void killPID(void *arg);
HeatCntrl::HeatCntrl(int heat){
	testing =0;
	counter =0;
	for(int i=0;i<1000;i++)
		derivatives[i]=100000;

	kill =0;
	heatID = heat;
	duty = DEFAULT_DUTY_CYC;
	switch(heatID){
		case HEATPAD1_PIN:
			IRtempSensor = new tempMeasurement(IRTEMP1_PIN);
			CtempSensor = new tempMeasurement(CTEMP1_PIN);
			break;
		case HEATPAD2_PIN:
			IRtempSensor = new tempMeasurement(IRTEMP2_PIN);
			CtempSensor = new tempMeasurement(CTEMP2_PIN);
			break;
		case HEATPAD3_PIN:
			IRtempSensor = new tempMeasurement(IRTEMP3_PIN);
			CtempSensor = new tempMeasurement(CTEMP3_PIN);
			break;
		case HEATPAD4_PIN:
			IRtempSensor = new tempMeasurement(IRTEMP4_PIN);
			CtempSensor = new tempMeasurement(CTEMP4_PIN);
			break;
		default:

			break;
	}
	exportPin(heatID);
	setPinDir(heatID,OUT);
	fall_timer=NULL;
	rise_timer=NULL;
}
struct args_timer{
		int rise_mode_t;
		int heatID_t;
	};
struct args_setup{
	RTOS_TMR* fall;
	int heatID;

};
void activateHeater(void* ptr){
	int heatID = ((args_timer*)ptr)->heatID_t;
	int mode = ((args_timer*)ptr)->rise_mode_t;
	setPin(heatID,mode);
}
void checkHeater(void* args){
	//printf("Checking Heater...\n");
	HeatCntrl* tmp = (HeatCntrl*)args;
	double temp = tmp->IRtempSensor->measureHeat();
	
	printf("Checking Heater... %.3f\n",temp);

	if(temp>tmp->target_temp)
		setPin(tmp->heatID,0);
	else
		setPin(tmp->heatID,1);

}
double HeatCntrl::getTemp(){

	return IRtempSensor->measureHeat();

}
int HeatCntrl::on_off_cntrl(void *args){
	// int c_pid = fork();
	// double* temp_targ = (double*)args[0];
	// double* hold_time = (double*)args[1];
	// if (c_pid < 0) { /* error occurred */
	// 	return -1;
	// }
	// else if (c_pid == 0) { /* child process */
	// 	int waitdelay = 100;
	// 	INT8* timer_name[2] = {"Stat","Kill"};
	// 	stat_timer = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,checkHeater,
	// 		(void*)this,timer_name[0],&err_val);
	// 		RTOSTmrStart((RTOS_TMR*)rise, &err_val);

	// }
	// else{
	// 	waitpid(c_pid,NULL,0);



	// }

}

int HeatCntrl::setDesiredTemp(double temp,double hold_time){
	int c_pid = fork();
	target_temp = temp + 273.15;
	stat_timer=NULL;
	kill_timer=NULL;
	INT8U err_val;
	//Forking because this is going to be pretty intensive.
	if (c_pid < 0) { /* error occurred */
		return -1;
	}
	else if (c_pid == 0) { /* child process */
		int waitdelay = 100;
		INT8* timer_name[2] = {"Stat","Kill"};
		stat_timer = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,checkHeater,
			(void*)this,timer_name[0],&err_val);
		kill_timer = RTOSTmrCreate(hold_time*1000,0,RTOS_TMR_ONE_SHOT,killPID,this,
				timer_name[1],&err_val);
		
		//RTOSTmrStart(stat_timer,&err_val);
		//RTOSTmrStart(kill_timer,&err_val);
		//Set Initial PWM On Heater: Default is 50%
		//setPWM(DEFAULT_DUTY_CYC,rise_timer,fall_timer);
		//PID Control
		while(1){
			checkHeater(this);
			usleep(100);
		}
		
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		waitpid(c_pid,NULL,0);
	}

}
void killPID(void *arg){
	INT8U err_val;

	HeatCntrl* handle = (HeatCntrl*) arg;
	handle->kill = 1;
	RTOSTmrDel(handle->fall_timer,&err_val);
	RTOSTmrDel(handle->rise_timer,&err_val);
	RTOSTmrDel(handle->stat_timer,&err_val);
	RTOSTmrDel(handle->kill_timer,&err_val);
	exit(0);

}
void setFallTimer(void* ptr){
	RTOS_TMR* fall = ((args_setup*)ptr)->fall;
	int heatID = ((args_setup*)ptr)->heatID;
	INT8U err_val;
	int waitdelay = 1000/HEAT_FREQ;
	INT8* timer_name[1] = {"Fall"};
	int rise_mode=0;
	struct args_timer args_fall = {rise_mode,heatID};
	fall = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,&args_fall,timer_name[0],&err_val);
	RTOSTmrStart(fall, &err_val);
}
int HeatCntrl::setPWM(double dutycyc,void*rise, void*fall){
	INT8U err_val;
	if(rise!=NULL)
		RTOSTmrDel((RTOS_TMR*)rise,&err_val);
	if(fall!=NULL)
		RTOSTmrDel((RTOS_TMR*)fall,&err_val);
	rise = fall = NULL;
	int waitdelay = 1000/HEAT_FREQ;
	INT8 *timer_name[2] = {"Rise", "Temp"};
	struct args_setup new_fall = {(RTOS_TMR*)fall,heatID};
	RTOS_TMR *temp_timer = RTOSTmrCreate(waitdelay*dutycyc,0,
		RTOS_TMR_ONE_SHOT,setFallTimer,&new_fall,timer_name[1],&err_val);
	RTOSTmrStart(temp_timer, &err_val);
	int rise_mode=1;
	struct args_timer rise_args={
		rise_mode,
		heatID
	};
	struct args_timer args_rise = {rise_mode,heatID};
	rise = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,&args_rise,timer_name[0],&err_val);
	RTOSTmrStart((RTOS_TMR*)rise, &err_val);
	RTOSTmrDel(temp_timer,&err_val);
}
int HeatCntrl::testHeatCntrl(int iterations, int fd){

	if(iterations == 0)
		return 0;
	setDesiredTemp(273+70, 10*60);
	char buffer[256];
	snprintf(buffer,128,"%d",kp_crit);

	write(fd,buffer,5);
	snprintf(buffer,128,"%d",T_crit);

	write(fd,buffer,5);

	snprintf(buffer,128,"%d",kp_crit*.2);

	write(fd,buffer,5);
	snprintf(buffer,128,"%d",T_crit/2);

	write(fd,buffer,5);
	snprintf(buffer,128,"%d",T_crit/3);

	write(fd,buffer,5);
	iterations--;
	return 0;
}
void HeatCntrl::measureStats (void* arg){
	HeatCntrl* handle = (HeatCntrl*) arg;
	handle->temp_pres = handle->IRtempSensor->measureHeat();

	handle->updatePWM();
}
PID* updateConstants(){
	

}
void HeatCntrl::updatePWM(){
	if(testing){
		kp+=.1;
		T_crit +=.1;

	}
	double err_pres = target_temp - temp_pres;
	double derivative = err_old - err_pres;
	derivatives[counter]=derivative;
	counter++;
	if(counter>999)counter=0;
	integral = integral + err_pres;
	double pwm = (kp * err_pres) + (ki * integral) + (kd * derivative);
	if(testing){
		bool crit=1;
		for(int i =0; i<1000;i++){
			if(derivatives[i]>eps_derv){
				crit=0;
			}
			
		}
		if(crit==1){
				T_crit -=1000*.1;
				kp_crit-=1000*.1;
				kill=1;
				killPID(this);
			}
	}
	if(pwm>100)
		pwm = 100;
	if(pwm<10)
		pwm=10;
	setPWM(pwm,rise_timer,fall_timer);

	temp = temp_pres;


}
