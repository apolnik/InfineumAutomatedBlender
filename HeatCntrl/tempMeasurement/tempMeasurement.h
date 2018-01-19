#ifndef tempMeasurement_H
#define tempMeasurement_H
 
#include "i2cTool.h"


class tempMeasurement{
	public:
	int tempsensorID;
	double* data;
	double temp;

	tempMeasurement();
	
	double measureHeat();
	double avgData();

}; 
#endif /* tempMeasurement_H */
