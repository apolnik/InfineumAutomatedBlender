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
	i2cTool Sensor;
	char regAddr = IR_TEMP_OBJ_1;
	if(sensorAddr == C_TEMP_DEV_ADDR){
		//change regAddr to the correct contact reg addr.
		regAddr=MCP9808_REG_AMBIENT_TEMP;
	}
	if(Sensor.readBytes(sensorAddr,regAddr,3, buf)!=3)
		return -1;
	double tempk;
	if(regAddr == MCP9808_REG_AMBIENT_TEMP)
		tempk = double((buf[0] & 0x1F)*16 + buf[1]/16)+273.15;
	else
		tempk = double((int(buf[1])<<8)|buf[0]) * .02;
	return tempk;
}
double tempMeasurement::avgData(){



}
