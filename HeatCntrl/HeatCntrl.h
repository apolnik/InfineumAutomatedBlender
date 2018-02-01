#ifndef HeatCntrl_H
#define HeatCntrl_H
 
#include "tempMeasurement.h"
class HeatCntrl{
private:
	int setPWM(double dutycyc, void* rise, void* fall);
	void measureStats();
public:
	int heatID;
	int heaterType;
	double temp;
	double duty;
	tempMeasurement* IRtempSensor;
	tempMeasurement* CtempSensor;


	HeatCntrl(int heat);

	int activateHeater();
	int setDesiredTemp(double temp, double hold_time);
	double getTemp();
	int testHeatCntrl(int iterations, int fd);
}; 
#endif /* HeatCntrl_H */
