#include "tempMeasurement.h"

tempMeasurement::tempMeasurement(){




}


double tempMeasurement::measureHeat(){
	unsigned char buf[3];
	i2cTool irSensor= new i2cTool();
	if(irSensor.readBytes(IR_TEMP_DEV_ADDR,IR_TEMP_OBJ_1,3, &buf)!=3)
		return -1;
	double tempk = double((int(buf[1])<<8)|buf[0]) * .02
	return tempk;
}
double tempMeasurement::avgData(){
	


}
