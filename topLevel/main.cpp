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
		weightMeasurement w(LOAD_CELL1_PIN);

	while(1){
		printf("Starting to measure weight\n");
		unsigned int weight = w.measureWeight();
    		printf("Weight Value: %u\n",weight);
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
    			printf("d for dc motor routine\n");



    		}
    		else if(decision[0]=='s'){

    		}
    		else if(decision[0]=='v'){
    		
    		}
    		else if(decision[0]=='p'){
    			
    		}
    		else if(decision[0]=='d'){
    		
    		}
	}
    return 0;



	#endif


}

