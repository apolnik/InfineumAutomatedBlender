#ifndef DC_Motor_H
#define DC_Motor_H

#include "Actuator.h"
#define ON 1
#define OFF 0
class DC_Motor : public Actuator{

	public:
	bool stirrer;
	int position;
	double speed;
	double torque;
	double power;
	int on_off;
	DC_Motor();

	double getSpeed();
	int setSpeed();

}; 
#endif /* DC_Motor_H */
