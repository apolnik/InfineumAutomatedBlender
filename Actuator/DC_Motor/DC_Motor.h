#ifndef DC_Motor_H
#define DC_Motor_H

#include "Actuator.h"
#define ON 1
#define OFF 0
class DC_Motor{

	public:
	bool stirrer;
	int position;
	char* pwm_pin;
	double speed;
	double torque;
	double power;
	int on_off;
	DC_Motor(int);
	int toggleState();
	double getSpeed();
	int setSpeed();

}; 
#endif /* DC_Motor_H */
