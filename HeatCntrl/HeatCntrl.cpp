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

void setFallTimer(void* ptr){
	RTOS_TMR* fall = ((args_setup*)ptr)->fall;
	int heatID = ((args_setup*)ptr)->heatID;
	INT8U err_val;
	int waitdelay = 1000/HEAT_FREQ;
	INT8* timer_name[1] = {"Fall"};
	int rise_mode=0;
	struct args_timer args_fall = {rise_mode,heatID};
	fall = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,&args_fall,timer_name[0],&err_val);

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
	RTOS_TMR *temp_timer = RTOSTmrCreate(waitdelay+HEAT_FREQ*dutycyc,0,
		RTOS_TMR_ONE_SHOT,setFallTimer,&new_fall,timer_name[1],&err_val);
	int rise_mode=1;
	struct args_timer rise_args={
		rise_mode,
		heatID
	};
	struct args_timer args_rise = {rise_mode,heatID};
	rise = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,activateHeater,&args_rise,timer_name[0],&err_val);
	RTOSTmrDel(temp_timer,&err_val);
}
int HeatCntrl::testHeatCntrl(int iterations, int fd){



}
void HeatCntrl::measureStats (void* arg){


}
PID* updateConstants(){


}
