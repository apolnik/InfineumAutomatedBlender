#define GUI 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#if GUI
	#include <QApplication>
	#include "systeminterfaceqt.h"
#endif
#include "SysParam.h"
#include "Stepper.h"
#include "weightMeasurement.h"
#include "HeatCntrl.h"
#include "tof.h"
#include "CurrentSen.h"
#include "ValveCntrl.h"
using namespace std;


int main(int argc, char *argv[]){
	
	
	#if GUI
		QApplication a(argc, argv);
		MainWindow w;
    		w.show();
    	
    		return a.exec();
	#else
		OSTickInitialize();
       		RTOSTmrInit();
		//weightMeasurement w(LOAD_CELL1_PIN);
		Stepper *s = new Stepper(LINRAIL);
		int direction = BACKWARD;
		s->setMode(FULLSTEP);
		HeatCntrl* h = new HeatCntrl(HEATPAD1_PIN);
		printf("Heat Cntrl Setup\n");
		//h->setDesiredTemp(100,100000);
		CurrentSen* current = new CurrentSen(0);
		
		int tof = tofInit(1,0x29,2);
		ValveCntrl valve1(VALVE_1);
		ValveCntrl valve2(VALVE_2);
		PumpCntrl pump1(PERISTALLTIC120,1);
		//PumpCntrl pump2(PERISTALLTIC12,PERI12_DIR);
		if(tof!=1){
			printf("Error Init TOF\n");

		}
	while(1){
		printf("Starting to measure weight\n");
		//unsigned int weight = w.measureWeight();
    		//printf("Weight Value: %u\n",weight);
    		printf("Continue? (b to break, o for options)\n");
    		char decision[32];
    		scanf("%s",decision);
	
    		if(decision[0]=='b'){
    			break;
    		}
    		else if(decision[0]=='o'){

    			printf("s for stepper motor routine\n");
    			printf("v for valve routine\n");
    			printf("p for pump routine\n");
    			printf("d for demo routine\n");



    		}
    		else if(decision[0]=='s'){
			while(1){
				//s->step(&direction);
			//	valve1.moveValve(BEAKER1_POS);
				setPin(STEPPER_DIR_PIN,1);
				setPin(STEPPER_STEP_PIN,0);
		                setPin(STEPPER_STEP_PIN,1);

				usleep(1000);
			}
    		}
    		else if(decision[0]=='v'){
			valve1.openValve();    		
			valve2.openValve();
    		}
		else if(decision[0]=='c'){
			double cur_weight = current->measureCurrent();
			printf("%.4f\n",cur_weight);
		}
		else if(decision[0]=='h'){
			h->setDesiredTemp(100,100000);	
			printf("%.2f",h->IRtempSensor->measureHeat());


		}
    		else if(decision[0]=='p'){
    			setPin(PERISTALLTIC120,1);
		}
 		
    		else if(decision[0]=='d'){
    			//demo
			valve1.moveValve(BEAKER2_POS);
			valve1.moveValve(BEAKER1_POS);
			valve1.openValve();
			pump1.activatePump();
			scanf("%s",decision);//usleep(1000000*1*60);
			pump1.deactivatePump();
			valve1.closeValve();
			h->setDesiredTemp(60, 10*60);			
												
    		}
		else if(decision[0]=='f'){
			int iDistance = tofReadDistance();
			if (iDistance < 4096) // valid range?
				printf("Distance = %dmm\n", iDistance);

		}
		
	}
    return 0;



	#endif


}

