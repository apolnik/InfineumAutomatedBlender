#ifndef FluidTranCntrl_H
#define FluidTranCntrl_H
#include "ValveCntrl.h"
#include "PumpCntrl.h"
#include "HeatCntrl.h"
#include "tempMeasurement.h"
#include "weightMeasurement.h" 

class FluidTranCntrl{
	public:
	
	int fluidid;
	ValveCntrl* valves;
	PumpCntrl* pumps;
	HeatCntrl* lineHeat;	
	tempMeasurement* tempSensors;
	weightMeasurement* scales;

	FluidTranCntrl();

	double getTemp();
	int setTemp();
	int activateTransfer();
	double getWeightTransferred();

}; 
#endif /* FluidTranCntrl_H */
