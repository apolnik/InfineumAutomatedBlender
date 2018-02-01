#ifndef ValveCntrl_H
#define ValveCntrl_H
 
#include "Actuator.h"
#include "Stepper.h"

class ValveCntrl{
	public:
	Stepper* carriage;
	int valveID;
	
	ValveCntrl(int vavleid);
	~ValveCntrl();
	int openValve();
	int moveValve(int beaker);
	int closeValve();
	int checkGuideUse();

}; 
#endif /* ValveCntrl_H */
