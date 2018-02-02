#include "gpioTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


int setPin(int pinNum, char val){
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);

	fd = open(buf, O_WRONLY);
	if(fd<0){
		return -1;

	}
	else{
		char v[1];
		v[0]=val+'0';
		write(fd,v,1);

	}
	close(fd);

	return 0;
}
int getPin(int pinNum, int* ret_val){
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);

	fd = open(buf, O_RDONLY);
	if(fd<0){
		return -1;

	}
	else{
		read(fd,&ch,1);
		if(ch =='0')
			*ret_val = 0;
		else
			*ret_val = 1;
	}
	close(fd);
	return 0;

}
int setPinDir(int pinNum, int dir){//output=1,input=0
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/direction", pinNum);

	fd = open(buf, O_WRONLY);
	if(fd<0){
		return -1;

	}
	else{
		if(dir == 0){
			write(fd,"in",3);

		}
		else
			write(fd,"out",4);


	}
	close(fd);

	return 0;
}
int exportPin(int pinNum){
	int fd;
	char buf[MAX_BUF];
	char ch;
	int len = snprintf(buf, sizeof(buf), "%d", pinNum);
	//write(fd, buf, len);
	//close(fd);

	fd = open("/sys/class/gpio/export", O_WRONLY);

	if(fd<0){
		return -1;

	}
	else{
		//len = snprintf(buf, sizeof(buf), "%i", pinNum);
		write(fd, buf, len);


	}	
	close(fd);
	return 0;
}
int unexportPin(int pinNum){
	int fd;
	char buf[MAX_BUF];
	char ch;
	int len = snprintf(buf, sizeof(buf), "%d", pinNum);
	//write(fd, buf, len);
	//close(fd);

	fd = open("/sys/class/gpio/unexport", O_WRONLY);

	if(fd<0){
		return -1;

	}
	else{
		//len = snprintf(buf, sizeof(buf), "%d", pinNum);
		write(fd, buf, len);


	}	
	close(fd);
	return 0;
}
