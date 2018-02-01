#include "tempMeasurement.h"

tempMeasurement::tempMeasurement(int sensor){
	tempsensorID=sensor;
	data = new double[5];
	for(int i =0; i < 5; i++)
		data[i] = 0;
	
}


double tempMeasurement::measureHeat(){

	char buf[3];
	char sensorAddr;
	if(tempsensorID == IRTEMP1_PIN || tempsensorID == IRTEMP2_PIN || 
		tempsensorID == IRTEMP3_PIN ||tempsensorID == IRTEMP4_PIN)
		sensorAddr = IR_TEMP_DEV_ADDR;
	else
		sensorAddr = C_TEMP_DEV_ADDR;
	i2cTool irSensor;
	char regAddr = IR_TEMP_OBJ_1;
	if(irSensor.readBytes(sensorAddr,regAddr,3, buf)!=3)
		return -1;
	double tempk = double((int(buf[1])<<8)|buf[0]) * .02;
	return tempk;
}
double tempMeasurement::avgData(){



}
