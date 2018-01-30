#ifndef ValveCntrl_H
#define ValveCntrl_H
 
#include "Actuator.h"


class ValveCntrl{
	public:
	Stepper* carriage;
	int valveID;
	
	ValveCntrl(int vavleid);
	~ValveCntrl();
	int openValve();
	int moveValve();
	int closeValve();
	int checkGuideUse();

}; 
#endif /* ValveCntrl_H */
