#include "gpioTool.h"
#include "HeatCntrl.h"
#include "SysParam.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include "sys/wait.h"

typedef struct{
	double Kp;
	double Ki;
	double Kd;
} PID;
HeatCntrl::HeatCntrl(int heat){
	this->headID = heat;
	this->duty = DEFAULT_DUTY_CYC;
	switch(this->heatID){
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
	exportPin(this->headID);
	setPinDir(this->headID,OUT);
}

void activateHeater(mode,heatID){
	setPin(headID,mode);
}

double HeatCntrl::getTemp(){

	return IRtempSensor->measureHeat();

}
int HeatCntrl::setDesiredTemp(double temp,double hold_time){
	int c_pid = fork();
	RTOS_TMR *fall_timer=NULL;
	RTOS_TMR *rise_timer=NULL;
	RTOS_TMR *stat_timer=NULL;
	INT8U err_val;
	//Forking because this is going to be pretty intensive.
	if (c_pid < 0) { /* error occurred */
		return -1;
	}
	else if (c_pid == 0) { /* child process */
		int waitdelay = 100;
		INT8* timer_name[1] = {"Stat"};
		stat_timer = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,measureStats,
			NULL,timer_name[0],&err_val);

		//Set Initial PWM On Heater: Default is 50%
		setPWM(DEFAULT_DUTY_CYC,rise_timer,fall_timer);
		//PID Control

	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		waitpid(c_pid,NULL,0);
	}
	RTOSTmrDel(fall_timer,&err_val);
	RTOSTmrDel(rise_timer,&err_val);
	RTOSTmrDel(stat_timer,&err_val);

}
void setFallTimer(){
	RTOS_TMR* fall = arg[0];
	INT8U err_val;
	int waitdelay = 1000/HEAT_FREQ;
	INT8* timer_name[1] = {"Fall"};
	int rise_mode=0;
	fall = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,{&rise_mode,&headID},timer_name[0],&err_val);

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
	RTOS_TMR *temp_timer = RTOSTmrCreate(waitdelay+HEAT_FREQ*dutycyc,0,
		RTOS_TMR_ONE_SHOT,setFallTimer,&fall,timer_name[1],&err_val);
	int rise_mode=1;
	rise = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,{&rise_mode,&heatID},timer_name[0],&err_val);
	RTOSTmrDel(temp_timer,&err_val);
}
int HeatCntrl::testHeatCntrl(int iterations, int fd){



}
void HeatCntrl::measureStats(){


}
PID* updateConstants(){


}
