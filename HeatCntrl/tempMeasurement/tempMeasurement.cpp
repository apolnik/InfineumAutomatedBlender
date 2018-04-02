#include "tempMeasurement.h"
tempMeasurement* tempMeasurement::tmp1=NULL;
tempMeasurement* tempMeasurement::tmp2=NULL;
tempMeasurement* tempMeasurement::tmp3=NULL;
tempMeasurement* tempMeasurement::tmp4=NULL;
tempMeasurement::tempMeasurement(int sensor){
	tempsensorID=sensor;
	data = new double[5];
	for(int i =0; i < 5; i++)
		data[i] = 0;
	
}


double tempMeasurement::measureHeat(){
	i2cTool Sensor;
	char buf[256];
	char sensorAddr;
	if(tempsensorID == IRTEMP1_PIN || tempsensorID == IRTEMP2_PIN || 
		tempsensorID == IRTEMP3_PIN ||tempsensorID == IRTEMP4_PIN){
		sensorAddr = IR_TEMP_DEV_ADDR;
		Sensor.setAddress(I2C_MULTI_ADDR);
		switch(tempsensorID){
			char g[16]; 
			g[0]=1;
			g[1]=0;
			case IRTEMP1_PIN:
				write(Sensor.i2cFile,&g,2);
				break;
			case IRTEMP2_PIN:
				g[0]=2;
				write(Sensor.i2cFile,&g,2);
				break;
			case IRTEMP3_PIN:
				g[0]=4;
				write(Sensor.i2cFile,&g,2);
				break;
			case IRTEMP4_PIN:
				g[0]=8;
				write(Sensor.i2cFile,&g,2);
				break;
			default:
				break;

		}

	}
	else
		sensorAddr = C_TEMP_DEV_ADDR;
	
	int result=0;
	char regAddr = IR_TEMP_OBJ_1;
	if(sensorAddr == C_TEMP_DEV_ADDR){
		//change regAddr to the correct contact reg addr.
		regAddr=MCP9808_REG_AMBIENT_TEMP;
	}
	else{
		if(result = Sensor.smbusReadWord(sensorAddr,regAddr)){
			//printf("Failed to read temp address\n");

			//return -1;
		}
	}
	//printf("%i %i\n",(int)buf[0],(int)buf[1]);
	
	
	
	double tempk;
	if(regAddr == MCP9808_REG_AMBIENT_TEMP){
		Sensor.readBytes(C_TEMP_DEV_ADDR,MCP9808_REG_AMBIENT_TEMP,3,buf);
		tempk = double((buf[0] & 0x1F)*16 + buf[1]/16)+273.15;
	}
	else
		tempk =double(result)*.02;// double((int(buf[1])<<8)|buf[0]) * .02;
	
	return tempk;
}
double tempMeasurement::avgData(){



}
