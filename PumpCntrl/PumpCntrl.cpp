#include "PumpCntrl.h"
#include "SysParam.h"
PumpCntrl::PumpCntrl(int pumpid_,int pump_dir){
	
	pumpID = pumpid_;
	dir_pin = pump_dir;
	if(pumpID != PERISTALLTIC120){
		pump = new DC_Motor(pumpID);
		dir =0;	
		exportPin(pumpID);
		setPinDir(pumpID,1);
	}
	else{
		dir =0;
		exportPin(pumpID);
		setPinDir(pumpID,1);

	}
}
PumpCntrl::~PumpCntrl(){
	deactivatePump();
	unexportPin(pumpID);

}
int PumpCntrl::activatePump(){
	if(pumpID != PERISTALLTIC120){
		if(pump->on_off == OFF)
			pump->toggleState();
	}
	else{
		setPin(pumpID, 1);
	}
	return 0;

}
int PumpCntrl::deactivatePump(){
	
	if(pumpID != PERISTALLTIC120){
		if(pump->on_off == ON)
			pump->toggleState();
	}
	else{
		setPin(pumpID,0);
	}
	return 0;

}
int PumpCntrl::changeDir(int dir_){
	if(pumpID!=PERISTALLTIC120){
		dir = dir_;
		setPin(dir_pin, dir);
	}
	return 0;
}

