#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int setPeriod(char* pin, unsigned int period_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/period",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",period_ns);
	return write(fd,buffer,64);
}	
int getPeriod(char* pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/period",pin);
	int fd = open(buffer, O_RDONLY);
	read(fd,buffer,64);
	return atoi(buffer);
}
int setDutyCyc(char* pin, unsigned duty_ns){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/duty",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",duty_ns);
	return write(fd,buffer,64);

}
double getDutyCyc(char* pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/duty",pin);
	int fd = open(buffer, O_RDONLY);
	read(fd,buffer,64);
	return ((double)atoi(buffer))/100.0;
}
int setPolarity(char* pin, int polarity){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/polarity",pin);
	int fd = open(buffer, O_WRONLY);
	snprintf(buffer,128,"%d",polarity);
	return write(fd,buffer,64);
}
int start_running_pwm(char* pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/run",pin);
	int fd = open(buffer, O_WRONLY);
	return write(fd,"0",2);

}
int stop_pwm(char* pin){
	char buffer[128];
	snprintf(buffer,128,"/sys/devices/ocp.3/%s/run",pin);
	int fd = open(buffer, O_WRONLY);
	return write(fd,"0",2);

}	
