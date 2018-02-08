#include "weightMeasurement.h"
#include "gpioTool.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "SysParam.h"
weightMeasurement::weightMeasurement(int id){
	scaleID=id;
	if(scaleID == LOAD_CELL1_PIN){
		clkID = LOAD_CELL1_CLK;
	}
	else if(scaleID == LOAD_CELL1_PIN){
		clkID = LOAD_CELL1_CLK;

	}
	else if(scaleID == LOAD_CELL1_PIN){
		clkID = LOAD_CELL1_CLK;
		
	}
	else if(scaleID == LOAD_CELL1_PIN){
		clkID = LOAD_CELL1_CLK;
		
	}
	exportPin(clkID);
	exportPin(id);
	printf("Load Cell pins exported\n");

}
weightMeasurement::~weightMeasurement(){
	unexportPin(scaleID);
	unexportPin(clkID);
}
unsigned int weightMeasurement::measureWeight(){
	//"/sys/class/gpio/gpio%d/value"
	///sys/class/gpio/gpio%d/direction
	char dirbuf[16];
	char buf[16];
	char dirclk[16];
	char valclk[16];
	char DOUT[16];
	DOUT[0]='1';
	int pinNum = scaleID;
	int clkNum =clkID;
	
	
	snprintf(dirbuf, sizeof(dirbuf),  "/sys/class/gpio/gpio%d/direction", pinNum);
	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);

	snprintf(dirclk, sizeof(dirclk),  "/sys/class/gpio/gpio%d/direction", clkNum);
	snprintf(valclk, sizeof(valclk),  "/sys/class/gpio/gpio%d/value", clkNum);
	
	int dirfd = open(dirbuf,O_WRONLY);
	int valfd = open(buf,O_RDWR);
	
	int clkvalfd = open(valclk,O_WRONLY);
	int dirclkfd = open(dirclk,O_WRONLY);
	if(dirfd <0 ||clkvalfd<0|| valfd <0 || dirclkfd <0){
		printf("Error in opening gpio file...\n");
	}
	write(dirclkfd,"1",2);
	write(clkvalfd,"0",2);
	//setPinDir(clkID,1);
	//setPin(clkID,0);
	//setPinDir(scaleID,0);
	//write(dirfd,"1",2);
	//write(valfd,"1",2);
	write(dirfd,"0",2);
	close(dirfd);
	close(valfd);
	printf("Waiting for DOUT to go low\n");
	int d_ret=1;
	while(d_ret==1){
		getPin(scaleID,&d_ret);
		//read(valfd,DOUT,2);
		//lseek(valfd,0,SEEK_SET);
		//printf("%c",DOUT[0]);
	}
	int count=0;
	for(int i=0; i<24;i++){
			setPin(clkID,1);//write(clkvalfd,"1",2);
			count=count<<1;
			setPin(clkID,0);//write(clkvalfd,"0",2);
			getPin(scaleID,&d_ret);
			count +=d_ret;
			if(d_ret!=1 && d_ret!=0)
				printf("Got non-binary result for DOUT read: %i\n",d_ret);

	}
	setPin(clkID,1);//write(clkvalfd,"1",2);
	count = count ^ 0x800000;
	setPin(clkID,0);//write(clkvalfd,"0",2);
	//close(valfd);
	//close(dirfd);
	//close(dirclkfd);
	//close(clkvalfd);
	return count;
}
double weightMeasurement::avgData(){


}
