#ifndef ValveCntrl_H
#define ValveCntrl_H
 
#include "Actuator.h"


class ValveCntrl{
	public:
	Actuator* valve;
	int valveID;
	
	ValveCntrl();
	
	int openValve();
	int moveValve();
	int closeValve();
	int checkGuideUse();

}; 
#endif /* ValveCntrl_H */
