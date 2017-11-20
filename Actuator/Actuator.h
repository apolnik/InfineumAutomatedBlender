#ifndef Actuator_H
#define Actuator_H
 

class Actuator{
	public:

	int id;
	
	Actuator();
	
	int setMotorType();
	int setSpeed();
	int controlPosition();

};
#endif /* Actuator_H */
