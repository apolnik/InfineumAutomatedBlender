#include "PumpCntrl.h"
#include "SysParam.h"
PumpCntrl::PumpCntrl(int pumpid_,int pump_dir, int syringeID = SYRINGE1){
	
	pumpID = pumpid_;
	dir_pin = pump_dir;
	if(pumpID != PERISTALLTIC120 && pumpID != PERISTALLTIC120_2 && pumpid != PERISTALLTIC120_3){
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

	syringe = new Stepper(syringeID);
}
PumpCntrl::~PumpCntrl(){
	deactivatePump();
	unexportPin(pumpID);
	delete syringe;
}
int PumpCntrl::activatePump(){
	if(pumpID != PERISTALLTIC120 && pumpID != PERISTALLTIC120_2 && pumpid != PERISTALLTIC120_3){
		if(pump->on_off == OFF)
			pump->toggleState();
	}
	else{
		setPin(pumpid, 1);
	}
	return 0;

}
int PumpCntrl::deactivatePump(){
	
	if(pumpID != PERISTALLTIC120 && pumpID != PERISTALLTIC120_2 && pumpid != PERISTALLTIC120_3){
		if(pump->on_off == ON)
			pump->toggleState();
	}
	else{
		setPin(pumpid,0);
	}
	return 0;

}
int PumpCntrl::changeDir(int dir_){
	if(pumpID != PERISTALLTIC120 && pumpID != PERISTALLTIC120_2 && pumpid != PERISTALLTIC120_3){
		dir = dir_;
		setPin(dir_pin, dir);
	}
	return 0;
}
int PumpCntrl::fillsyringePump(double microL){
	int retract_dir = 0;
	
	for(int i = 0; i < (int)(microL*100); i++){
		for(int j =0; j < STEPS_1uL; j++){
			syringe->step(&retract_dir)
			if(i==0 && j < STEPS_1uL/2){
				usleep(1000*(STEPS_1uL/2)-j);
			}
			else if(i==((int)(microL*100)-1) && j>STEPS_1uL/2){
				usleep(1000*(j-STEPS_1uL/2));
			}
			else{
				usleep(1000);
			}
		}

	}
	int s_id = syringe->id_;
	int pump_time_us = 0;
	if(s_id == SYRINGE1){
		pump_time_us=S1_refill_1uL*microL;
	}
	else if(s_id == SYRINGE2){
		pump_time_us=S2_refill_1uL*microL;

	}
	else if(s_id == SYRINGE3){
		pump_time_us=S3_refill_1uL*microL;
		
	}
	else if(s_id == SYRINGE4){
		pump_time_us=S4_refill_1uL*microL;
		
	}
	else if(s_id == SYRINGE5){
		pump_time_us=S5_refill_1uL*microL;
		
	}
	else{
		//error
		return -1;
	}
	activatePump();
	usleep(pump_time_us); 
	deactivatePump();
	return 0;
}

int PumpCntrl::dispenseSyringePump(double microL){
	int dispense_dir = 1;
	for(int i = 0; i < (int)(microL*100); i++){
		for(int j =0; j < STEPS_1uL; j++){
			syringe->step(&dispense_dir)
			if(i==0 && j < STEPS_1uL/2){
				usleep(1000*(STEPS_1uL/2)-j);
			}
			else if(i==((int)(microL*100)-1) && j>STEPS_1uL/2){
				usleep(1000*(j-STEPS_1uL/2));
			}
			else{
				usleep(1000);
			}
		}

	}
	return 0;

}
