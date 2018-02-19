#ifndef PumpCntrl_H
#define PumpCntrl_H
 


#include "DC_Motor.h"
class PumpCntrl{
	public:
	int pumpID;
	int dir;
	int dir_pin
	DC_Motor* pump;
	PumpCntrl(int pumpid_,int pump_dir);
	~PumpCntrl();
	int deactivatePump();	
	int activatePump();
	int changeDir(int dir_);
}; 
#endif /* PumpCntrl_H */
