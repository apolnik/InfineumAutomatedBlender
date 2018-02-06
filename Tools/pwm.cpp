#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int setPeriod(int pin, unsigned int period_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/period",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",period_ns);
	return write(fd,buffer,5);
}	
int getPeriod(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/period",pin);
	int fd = open(buffer, O_RDONLY);
	read(fd,buffer,5);
	return atoi(buffer);
}
int setDutyCyc(int pin, unsigned duty_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/duty",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",duty_ns);
	return write(fd,buffer,5);

}
double getDutyCyc(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/duty",pin);
	int fd = open(buffer, O_RDONLY);
	read(fd,buffer,5);
	return ((double)atoi(buffer))/100.0;
}
int setPolarity(int pin, int polarity){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/polarity",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",polarity);
	return write(fd,buffer,5);
}
int start_running_pwm(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/run",pin);
	int fd = open(buffer, O_WRONLY);
	return write(fd,"0",2);

}
int stop_pwm(int pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%d/run",pin);
	int fd = open(buffer, O_WRONLY);
	return write(fd,"0",2);

}	
