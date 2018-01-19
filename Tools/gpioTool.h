#ifndef gpioTool_H
#define gpioTool_H

#define MAX_BUF 64
#define OUT 1
#define IN 0
	int setPin(int pinNum, char val);
	int exportPin(int pinNum);
	int unexportPin(int pinNum);

	int getPin(int pinNum, int* ret_val);
	int setPinDir(int pinNum, int dir);//output=1,input=0


#endif /* gpioTool_H */