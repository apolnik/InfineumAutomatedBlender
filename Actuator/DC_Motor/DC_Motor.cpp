#include "DC_Motor.h"
#include "SysParam.h"
#include "gpioTool.h"
#include "pwm.h"
DC_Motor::DC_Motor(int motorID){
	position = motorID;
	on_off = OFF;
	if(motorID==DCMOT1_DIR_PIN){
		exportPin(motorID);
		setPinDir(motorID,1);
		stop_pwm(DCMOT1_PWM_PIN);
		setPolarity(DCMOT1_PWM_PIN,0);
		setPin(motorID,1);
		setPeriod(DCMOT1_PWM_PIN,DEFAULT_PERIOD_DC);
		setDutyCyc(DCMOT1_PWM_PIN,DEFAULT_DUTY_DC);
	}
	else if(motorID == DCMOT2_DIR_PIN){
		exportPin(motorID);
		setPinDir(motorID,1);
		stop_pwm(DCMOT2_PWM_PIN);
		setPolarity(DCMOT2_PWM_PIN,0);
		setPin(motorID,1);
		setPeriod(DCMOT2_PWM_PIN,DEFAULT_PERIOD_DC);
		setDutyCyc(DCMOT2_PWM_PIN,DEFAULT_DUTY_DC);
	}
	else if(motorID == DCMOT3_DIR_PIN){
		exportPin(motorID);
		setPinDir(motorID,1);
		stop_pwm(DCMOT3_PWM_PIN);
		setPolarity(DCMOT3_PWM_PIN,0);
		setPin(motorID,1);
		setPeriod(DCMOT3_PWM_PIN,DEFAULT_PERIOD_DC);
		setDutyCyc(DCMOT3_PWM_PIN,DEFAULT_DUTY_DC);
	}
	else if(motorID == DCMOT4_DIR_PIN){
		exportPin(motorID);
		setPinDir(motorID,1);
		stop_pwm(DCMOT4_PWM_PIN);
		setPolarity(DCMOT4_PWM_PIN,0);
		setPin(motorID,1);
		setPeriod(DCMOT4_PWM_PIN,DEFAULT_PERIOD_DC);
		setDutyCyc(DCMOT4_PWM_PIN,DEFAULT_DUTY_DC);
	}
	else{


	}

}


double DC_Motor::getSpeed(){





}
int DC_Motor::setSpeed(){






}
int DC_Motor::toggleState(){//toggles whether the motor is on or off.
	if(on_off == OFF)
		start_running_pwm(position);
	else
		stop_pwm(position);

}
