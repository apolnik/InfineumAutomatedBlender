#include "DC_Motor.h"
#include "SysParam.h"
#include "gpioTool.h"
#include "pwm.h"
#define ARDUINO 1
DC_Motor::DC_Motor(int motorID){
	position = motorID;
	on_off = OFF;
	#if ARDUINO
	#else
		if(motorID==DCMOT1_DIR_PIN){
			char* pwm_pin_ = DCMOT1_PWM_PIN;
			pwm_pin = pwm_pin_;
			exportPin(motorID);
			setPinDir(motorID,1);
			stop_pwm(DCMOT1_PWM_PIN);
			setPolarity(DCMOT1_PWM_PIN,0);
			setPin(motorID,1);
			setPeriod(DCMOT1_PWM_PIN,DEFAULT_PERIOD_DC);
			setDutyCyc(DCMOT1_PWM_PIN,DEFAULT_DUTY_DC);
			CurrentSen::stirrer_sen=new CurrentSen(STIRRER_CUR_SENSOR);
		}
		else if(motorID == DCMOT2_DIR_PIN){
			char* pwm_pin_ = DCMOT2_PWM_PIN;
			pwm_pin = pwm_pin_;
			exportPin(motorID);
			setPinDir(motorID,1);
			stop_pwm(DCMOT2_PWM_PIN);
			setPolarity(DCMOT2_PWM_PIN,0);
			setPin(motorID,1);
			setPeriod(DCMOT2_PWM_PIN,DEFAULT_PERIOD_DC);
			setDutyCyc(DCMOT2_PWM_PIN,DEFAULT_DUTY_DC);
		}
		else if(motorID == DCMOT3_DIR_PIN){
			char* pwm_pin_ = DCMOT3_PWM_PIN;
			pwm_pin = pwm_pin_;
			exportPin(motorID);
			setPinDir(motorID,1);
			stop_pwm(DCMOT3_PWM_PIN);
			setPolarity(DCMOT3_PWM_PIN,0);
			setPin(motorID,1);
			setPeriod(DCMOT3_PWM_PIN,DEFAULT_PERIOD_DC);
			setDutyCyc(DCMOT3_PWM_PIN,DEFAULT_DUTY_DC);
		}
		else if(motorID == DCMOT4_DIR_PIN){
			char* pwm_pin_ = DCMOT4_PWM_PIN;
			pwm_pin = pwm_pin_;
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
	#endif
}


double DC_Motor::getSpeed(){





}
int DC_Motor::setSpeed(){






}
int DC_Motor::toggleState(){//toggles whether the motor is on or off.
	#if ARDUINO
		int fd = openArduino();
		if(on_off == OFF)
			{
				sendArduino("m1",file);
				for(int i =0; i<100; i++){
					sendArduino("mu",file);
					usleep(100000);
				}
				

			}
		else
			{
				for(int i =0; i<100; i++){
					sendArduino("md",file);
					usleep(100000);
				}
				sendArduino("m0",file);
			}
		closeArduino(fd);
	#else
		if(on_off == OFF)
			start_running_pwm(pwm_pin);
		else
			stop_pwm(pwm_pin);		
	#endif
}
