#ifndef HeatCntrl_H
#define HeatCntrl_H
 
#include "tempMeasurement.h"
class HeatCntrl{
	public:
	int heatID;
	int heaterType;
	double temp;
	tempMeasurement* tempSensor;


	HeatCntrl();

	int activateHeater();
	double getTemp();

}; 
#endif /* HeatCntrl_H */
