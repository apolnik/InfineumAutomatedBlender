
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

class i2cTool{

public:
	int i2cFile;
	char dev_ADDR;
	i2cTool();
	~i2cTool();
	int open_i2c();
	int close_i2c();
	int sendByte(char data, char dev_addr, char reg_addr);
	int readBytes(char dev_addr, char reg_addr, int size, char* output);
	int setAddress(char addr);
	int sendBytes(short data, char dev_addr, char reg_addr);
	int smbusReadWord(char devaddr, char regaddr);



};
