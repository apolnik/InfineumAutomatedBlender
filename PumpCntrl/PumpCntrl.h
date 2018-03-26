#ifndef PumpCntrl_H
#define PumpCntrl_H
 
#include "Stepper.h"

#include "DC_Motor.h"
class PumpCntrl{
	public:
	int pumpID;
	int dir;
	int dir_pin;
	DC_Motor* pump;
	Stepper* syringe;

	PumpCntrl(int pumpid_,int pump_dir, int syringeID = SYRINGE1);
	~PumpCntrl();
	int deactivatePump();	
	int activatePump();
	int changeDir(int dir_);
	int fillsyringePump(double microL);
	int dispenseSyringePump(double microL);
}; 
#endif /* PumpCntrl_H */
