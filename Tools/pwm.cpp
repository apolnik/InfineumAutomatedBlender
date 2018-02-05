#include "stdio.h"
int setPeriod(int pin, unsigned int period_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/period",pin);
	int fd = open(buffer, WR_ONLY);
	snprintf(buffer,128,"%d",period_ns);
	return write(fd,buffer,5);
}	
int getPeriod(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/period",pin);
	int fd = open(buffer, RD_ONLY);
	read(fd,buffer,5);
	return atoi(buffer);
}
int setDutyCyc(int pin, unsigned duty_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/duty",pin);
	int fd = open(buffer, WR_ONLY);
	snprintf(buffer,128,"%d",duty_ns);
	return write(fd,buffer,5);

}
double getDutyCyc(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/duty",pin);
	int fd = open(buffer, RD_ONLY);
	read(fd,buffer,5);
	return ((double)atoi(buffer))/100.0;
}
int setPolarity(int pin, int polarity){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/polarity",pin);
	int fd = open(buffer, WR_ONLY);
	snprintf(buffer,128,"%d",polarity);
	return write(fd,buffer,5);
}
int start_running(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/run",pin);
	int fd = open(buffer, WR_ONLY);
	return write(fd,"0");

}
int stop(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/run",pin);
	int fd = open(buffer, WR_ONLY);
	return write(fd,"0",2);

}	