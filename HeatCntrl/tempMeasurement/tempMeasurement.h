#ifndef tempMeasurement_H
#define tempMeasurement_H
 
#include "i2cTool.h"
#include "SysParam.h"

class tempMeasurement{
	public:
	int tempsensorID;
	double* data;
	double temp;

	tempMeasurement(int sensor);
	
	double measureHeat();
	double avgData();

}; 
#endif /* tempMeasurement_H */
