#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include "Stepper.h"
#include "SysParam.h"
using namespace std;


int main(int argc, char *argv[]){

	OSTickInitialize();
    RTOSTmrInit();
	weightMeasurement w(LOAD_CELL1_PIN);

	while(1){
		double weight = w.measureWeight();
    	fprint("Weight Value: %f\n",weight);
    	fprint("Continue? (b to break, o for options)\n");
    	char decision[32];
    	scanf("%s",decision);

    	if(decision[0]=='b'){
    		break;
    	}
    	else if(decision[0]=='o'){

    		fprintf("s for stepper motor routine\n");
    		fprintf("v for valve routine\n");
    		fprintf("p for pump routine\n")
    		fprintf("d for dc motor routine\n")



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


}

