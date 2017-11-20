#ifndef PumpCntrl_H
#define PumpCntrl_H
 
#include "Actuator.h"


class PumpCntrl{
	public:
	int pumpID;
	Actuator* pump;
	PumpCntrl();
	
	int activatePump();

}; 
#endif /* PumpCntrl_H */
