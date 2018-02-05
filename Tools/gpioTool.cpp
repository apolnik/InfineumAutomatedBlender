#include "gpioTool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>

int setPin(int pinNum, char val){
	int fd;
	char buf[MAX_BUF];
	char ch;
	std::fstream fs;
	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);
	fs.open(buf);
    fs << (val+'0');

	//fd = open(buf, O_WRONLY);
	//if(fd<0){
	//	return -1;

	//}
	//else{
	//	char v[1];
	//	v[0]=val+'0';
	//	write(fd,v,1);

	//}
	//close(fd);
	fs.close();

	return 0;
}
int getPin(int pinNum, int* ret_val){
	int fd;
	char buf[MAX_BUF];
	char ch;
	std::fstream fs;
	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);
	fs.open(buf);
	fs >> ch;
	//fd = open(buf, O_RDONLY);
	//if(fd<0){
	//	return -1;

	//}
	//else{
	//	read(fd,&ch,1);
		if(ch =='0')
			*ret_val = 0;
		else
			*ret_val = 1;
	//}
	//close(fd);
	fs.close();

	return 0;

}
int setPinDir(int pinNum, int dir){//output=1,input=0
	int fd;
	char buf[MAX_BUF];
	char ch;
	
        
        
	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/direction", pinNum);
	std::fstream fs;
    fs.open(buf);
        

	//fd = open(buf, O_WRONLY);
	//if(fd<0){
	//	return -1;

	//}
	//else{
		if(dir == 0){
			fs <<"in";//write(fd,"in\n",4);

		}
		else
			fs <<"out";//write(fd,"out\n",5);


	//}
	//close(fd);
	fs.close();

	return 0;
}
int exportPin(int pinNum){
	int fd;
	char buf[MAX_BUF];
	char ch;
	int len = snprintf(buf, sizeof(buf), "%d", pinNum);
	//write(fd, buf, len);
	//close(fd);

	//fd = open("/sys/class/gpio/export", O_WRONLY);
	 //std::fstream fs;
        
        //fs.open("/sys/class/gpio/export");
        //fs << pinNum;
	//fs.close();
	std::ofstream stream("/sys/class/gpio/export");

  if (!stream) {
   
    return -1;
  }

  stream << pinNum;
  stream.close();

	//if(fd<0){
	//	return -1;

	//}
	//else{
		//len = snprintf(buf, sizeof(buf), "%i", pinNum);
		//write(fd, buf, len);


	//}	
	//close(fd);
	return 0;
}
int unexportPin(int pinNum){
	int fd;
	char buf[MAX_BUF];
	char ch;
	//int len = snprintf(buf, sizeof(buf), "%d", pinNum);
	//write(fd, buf, len);
	//close(fd);
	std::fstream fs;
    fs.open("/sys/class/gpio/unexport");
    fs << pinNum;
	fs.close();
	//fd = open("/sys/class/gpio/unexport", O_WRONLY);

	//if(fd<0){
	//	return -1;

	//}
	//else{
		//len = snprintf(buf, sizeof(buf), "%d", pinNum);
	//	write(fd, buf, len);


	//}	
	//close(fd);
	return 0;
}
