#ifndef tempMeasurement_H
#define tempMeasurement_H
 
#include "i2cTool.h"
#include "SysParam.h"

class tempMeasurement{
	public:
	static tempMeasurement* tmp1;
	static tempMeasurement* tmp2;
	static tempMeasurement* tmp3;
	static tempMeasurement* tmp4;
	int tempsensorID;
	double* data;
	double temp;

	tempMeasurement(int sensor);
	
	double measureHeat();
	double avgData();

}; 
#endif /* tempMeasurement_H */
