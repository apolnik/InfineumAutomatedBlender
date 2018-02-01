#ifndef Stepper_H
#define Stepper_H
#include "Actuator.h" 
#include "Proximity.h"
#include "SysParam.h"
#define FULLSTEP 0
#define HALFSTEP 1
#define QUARTERSTEP 2
#define EIGHTSTEP 3
#define STEPSPERREV 200
#define FORWARD 0
#define BACKWARD 1
class Stepper: public Actuator{
public:
	double position;
	int useType;
	int factor=1;
	Proximity disSensor;
	Stepper();
	~Stepper();
	int getPosition(double* ret_val);
	int controlPosition(double distance, double rpm);
	int returnToStartPos();

	static void step(void *direction);
	int setMode(int mode);
}; 
Stepper stepper_motor;
#endif /* Stepper_H */
