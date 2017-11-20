#ifndef mixCntrl_H
#define mixCntrl_H
#include "Actuator.h"
#include "HeatCntrl.h"

class mixCntrl{
	public:

	int beakerID;
	int time;
	double motorSpeed;
	double temperature;
	Actuator* stirrers;
	HeatCntrl* heaters;

	mixCntrl();
	
	int setMotorSpeed();
	int setTemperature();
	int setTimer();

}; 
#endif /* mixCntrl_H */
