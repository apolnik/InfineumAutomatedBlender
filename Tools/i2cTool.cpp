#include "i2cTool.h"

i2cTool::i2cTool(){
	open_i2c();


}
~i2cTool::i2cTool(){
	close_i2c();


}
int i2cTool::open_i2c(){

	i2cFile = open("/dev/i2c-3",O_RDWR);
	if(i2cFile<0)
		return -1;
	else return 0;
}

int i2cTool::close_i2c(){
	close(i2cFile);



}

int i2cTool::sendByte(char data, char dev_addr, char reg_addr){
	setAddress(dev_addr);
	char buf[2];
	buf[0] = reg_addr;
	buf[1] = data;

	if(write(i2cFile,buf,2)!=2)
		return -1;
	else return 0;
}
int i2cTool::readBytes(char dev_addr, char reg_addr, int size, char* output){
	char buf[1];
	buf[0]=reg_addr; 
	setAddress(dev_addr);
	if(write(i2cFile,buf,1)!=1)
		return -1;
	setAddress(dev_addr);
	if(int i=read(i2cFile,output,size)!=n)
		return i;
	else return n;
}
int i2cTool::setAddress(char addr){
	dev_ADDR = addr;
	if(ioctl(i2cFile,I2C_SLAVE, reg_addr)<0)
		return -1;
	return 0;


}