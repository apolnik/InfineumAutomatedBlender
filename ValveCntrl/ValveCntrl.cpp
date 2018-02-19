#include "ValveCntrl.h"
#include "gpioTool.h"
#define VALVE1_POS	0.5f
#define VALVE2_POS	2.5f
#define VALVE3_POS	0
#define VALVE4_POS	0
#define VALVE5_POS	0

ValveCntrl::ValveCntrl(int valveid){
	carriage = Stepper::stepper_motor;
	valveID = valveid;
	exportPin(valveID);
	setPinDir(valveID,OUT);

}
ValveCntrl::~ValveCntrl(){
	unexportPin(valveID);
}
int ValveCntrl::openValve(){
	return setPin(valveID,1);

}
int ValveCntrl::moveValve(int beaker){
	if(checkGuideUse()==-1)return -1;
	if(beaker==1 || beaker == BEAKER1_POS){
		return carriage->controlPosition(BEAKER1_POS+VALVE1_POS,BASE_SPEED);
		
	}
	else if(beaker==2 ||beaker == BEAKER2_POS){
		return carriage->controlPosition(BEAKER2_POS+VALVE2_POS,BASE_SPEED);

	}
	else if(beaker==3 || beaker == BEAKER3_POS){
		return carriage->controlPosition(BEAKER3_POS+VALVE3_POS,BASE_SPEED);

	}
	else if(beaker==0 || beaker == GARBAGE){
		return carriage->controlPosition(GARBAGE,BASE_SPEED);

	}
	else
		return -1;
}
int ValveCntrl::closeValve(){
	return setPin(valveID,0);

}
int ValveCntrl::checkGuideUse(){

	if(carriage->inUse==1)
		return -1;
	return 0;
}
