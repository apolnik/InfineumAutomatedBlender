#include "i2cTool.h"

i2cTool::i2cTool(){
	if(open_i2c()<0)
		printf("Failed to open I2C device\n");


}
i2cTool::~i2cTool(){
	close_i2c();


}
int i2cTool::open_i2c(){

	i2cFile = open("/dev/i2c-2",O_RDWR);
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
int i2cTool::sendBytes(short data, char dev_addr, char reg_addr){
	setAddress(dev_addr);
	char buf[2];
	buf[0] = reg_addr;
	buf[1] = (data&0xFF00)>>8;
	buf[2] = (data&0x00FF);

	if(write(i2cFile,buf,3)!=3)
		return -1;
	else return 0;
}
#define I2C_SMBUS_READ 1
#define I2C_SMBUS_WORD_DATA 3
int i2cTool::readBytes(char dev_addr, char reg_addr, int size, char* output){
	
	char buf[1]; 
	buf[0]=reg_addr; 
	setAddress(dev_addr);
	if(write(i2cFile,buf,1)!=1)
		return -1;
	setAddress(dev_addr);
	if(int i=read(i2cFile,output,size)!=size)
		return i;
	else{
		printf("%i",(int)output[i]);
		 return size;}
}
int i2cTool::setAddress(char addr){
	dev_ADDR = addr;
	if(ioctl(i2cFile,I2C_SLAVE, dev_ADDR)<0)
		return -1;
	return 0;


}
int i2cTool::smbusReadWord(char devaddr, char regaddr){
	__u8 command = regaddr;
        setAddress(devaddr);
        return i2c_smbus_read_word_data(i2cFile, command);



}
