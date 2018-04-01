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
#define FORWARD 1
#define BACKWARD 0
class Stepper: public Actuator{
public:
	double position;
	int useType;
	int factor;
	Proximity disSensor;
	int inUse;
	static Stepper* stepper_motor;
	int id_;
	Stepper(int id=LINRAIL);
	~Stepper();
	int getPosition(double* ret_val);
	int controlPosition(double distance, double rpm);
	int returnToStartPos();

	void step(void *direction);
	int setMode(int mode);
}; 
#endif /* Stepper_H */
