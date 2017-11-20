#ifndef Stepper_H
#define Stepper_H
#include "Actuator.h" 

class Stepper: public Actuator{
	public:
	int position;
	int useType;

	Stepper();
	
	int getPosition();
	int controlPosition();
	int returnToStartPos();

}; 
#endif /* Stepper_H */
