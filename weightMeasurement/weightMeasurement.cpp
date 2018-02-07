#include "weightMeasurement.h"

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
	exportPin(clkID)
	exportPin(id);

}
weightMeasurement::~weightMeasurement(){
	unexportPin(scaleID);

}
double weightMeasurement::measureWeight(){
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
	int dirclk = open(dirclk,O_WRONLY);

	write(dirclk,"1",2);
	write(clkvalfd,"0",2);
	
	write(dirfd,"1",2);
	write(valfd,"1",2);
	write(dirfd,"0",2);
	close(dirfd);
	while(DOUT[0]=='1'){
		read(valfd,&DOUT,2);
		seek(valfd,0,0);
	}
	int count=0;
	for(int i=0; i<24;i++){
			write(clkvalfd,"1",2);
			count=count<<1;
			write(clkvalfd,"0",2);
			read(valfd,&DOUT,2);
			if(DOUT[0]=='1')
				count++;

	}
	write(clkvalfd,"1",2);
	count = count ^ 0x800000;
	write(clkvalfd,"0"2);
	close(valfd);
	close(dirfd);
	close(dirclk);
	close(clkvalfd);
	return count;
}
double weightMeasurement::avgData(){


}
