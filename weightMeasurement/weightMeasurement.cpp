#include "weightMeasurement.h"
#include "gpioTool.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "SysParam.h"
#include<linux/spi/spidev.h>
#include<sys/ioctl.h>
#include<stdint.h>
#define SPI_PATH "/dev/spidev1.0"
	double weightMeasurement::beaker1_weight=0;
	double weightMeasurement::beaker2_weight=0;
	double weightMeasurement::beaker3_weight=0;
	double weightMeasurement::beaker4_weight=0;
int transfer(int fd, unsigned char send[], unsigned char receive[], int length){
   struct spi_ioc_transfer transfer;           //the transfer structure
   transfer.tx_buf = (unsigned long) send;     //the buffer for sending data
   transfer.rx_buf = (unsigned long) receive;  //the buffer for receiving data
   transfer.len = length;                      //the length of buffer
   transfer.speed_hz = 1000000;                //the speed in Hz
   transfer.bits_per_word = 25;                 //bits per word
   transfer.delay_usecs = 0;                   //delay in us

   // send the SPI message (all of the above fields, inc. buffers)
   int status = ioctl(fd, SPI_IOC_MESSAGE(1), &transfer);
   if (status < 0) {
      perror("SPI: SPI_IOC_MESSAGE Failed");
      return -1;
   }
   return status;
}

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

	int fd=0;
	unsigned int value, null=0x00;         //sending only a single char
   uint8_t bits = 25, mode = 1;             //8-bits per word, SPI mode 3
   uint32_t speed = 1000000;               //Speed is 1 MHz 
	if ((fd = open(SPI_PATH, O_RDWR))<0){
	      perror("SPI Error: Can't open device.");
	      return -1;
	   }
	if (ioctl(fd, SPI_IOC_RD_MODE, &mode)==-1){
	      perror("SPI: Can't get SPI mode.");
	      return -1;
	   }
	
   	if (ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits)==-1){
      		perror("SPI: Can't get bits per word.");
      		return -1;
   	}
	   if (ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed)==-1){
     		 perror("SPI: Can't get max speed HZ.");
     		 return -1;
   	}
	unsigned int ret_val_spi;
	transfer(fd,NULL,(unsigned char*)&ret_val_spi,1);
	ret_val_spi = ret_val_spi ^ 0x800000;
	return ret_val_spi;
	snprintf(dirbuf, sizeof(dirbuf),  "/sys/class/gpio/gpio%d/direction", pinNum);
	snprintf(buf, sizeof(buf),  "/sys/class/gpio/gpio%d/value", pinNum);

	snprintf(dirclk, sizeof(dirclk),  "/sys/class/gpio/gpio%d/direction", clkNum);
	snprintf(valclk, sizeof(valclk),  "/sys/class/gpio/gpio%d/value", clkNum);
	
	//int dirfd = open(dirbuf,O_WRONLY);
	//int valfd = open(buf,O_RDWR);
	
	//int clkvalfd = open(valclk,O_WRONLY);
	//int dirclkfd = open(dirclk,O_WRONLY);
	//if(dirfd <0 ||clkvalfd<0|| valfd <0 || dirclkfd <0){
	//	printf("Error in opening gpio file...\n");
	//}
	//write(dirclkfd,"1",2);
	//write(clkvalfd,"0",2);
	setPinDir(clkID,1);
	setPin(clkID,0);
	setPinDir(scaleID,0);
	//write(dirfd,"1",2);
	//write(valfd,"1",2);
	//write(dirfd,"0",2);
	//close(dirfd);
	//close(valfd);
	printf("Waiting for DOUT to go low\n");
	int d_ret=1;
	while(d_ret==1){
		getPin(scaleID,&d_ret);
		//read(valfd,DOUT,2);
		//lseek(valfd,0,SEEK_SET);
		//printf("%i",d_ret);
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
