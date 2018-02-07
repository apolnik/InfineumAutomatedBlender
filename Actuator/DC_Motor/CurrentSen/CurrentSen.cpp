#include "CurrentSen.h"
#include "i2cTool.h"
CurrentSen::CurrentSen(int id){
	currentID = id;
	ina219_calValue=4096;
	short config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

    calibrate(config);

}
~CurrentSen::~CurrentSen(){

}

double CurrentSen::measureCurrent(){
	char buf[3];

	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,INA_REG_CALIBRATION);

	Sensor.readBytes(INA219_ADDRESS,INA219_REG_CURRENT,3,&buf);
	double ret_val = double((buf[0]<<8) | buf[1])/10;
	return ret_val;

}
double CurrentSen::measurePower(){
	char buf[3];

	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,INA_REG_CALIBRATION);

	Sensor.readBytes(INA219_ADDRESS,INA219_REG_POWER,3,&buf);
	double ret_val = 2* double((buf[0]<<8) | buf[1]);
	return ret_val;

}

double CurrentSen::avgData(){


	
}
int CurrentSen::calibrate(short config){
	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,INA_REG_CALIBRATION);
	return Sensor.sendBytes(config,INA219_ADDRESS,INA219_REG_CONFIG);



}