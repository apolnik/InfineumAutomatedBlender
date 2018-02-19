#include "PumpCntrl.h"

PumpCntrl::PumpCntrl(int pumpid_,int pump_dir){
	
	pumpid = pumpid_;
	dir_pin = pump_dir;
	if(pumpid != PERISTALLTIC120){
		pump = new DC_MOTOR(pumpid);
		dir =0;	
		exportPin(pumpid);
		setPinDir(pumpid,1);
	}
	else{
		dir =0;
		exportPin(pumpid);
		setPinDir(pumpid,1);

	}
}
PumpCntrl::~PumpCntrl(){
	deactivatePump();
	unexportPin(pumpid);

}
int PumpCntrl::activatePump(){
	if(pumpid != PERISTALLTIC120){
		if(pump->on_off == OFF)
			pump->toggleState();
	}
	else{
		setPin(pumpid, 1);
	}
	return 0;

}
int PumpCntrl::deactivatePump(){
	
	if(pumpid != PERISTALLTIC120){
		if(pump->on_off == ON)
			pump->toggleState();
	}
	else{
		setPin(pumpid,0);
	}
	return 0;

}
int PumpCntrl::changeDir(dir_){
	if(pumpid!=PERISTALLTIC120){
		dir = dir_;
		setPin(dir_pin, dir);
	}
	return 0;
}

