#include "Proximity.h"
#include <stdio.h>
#include <unistd.h>
#include "SysParam.h"
//#include <prussdrv.h>
//#include <pruss_intc_mapping.h>
//https://github.com/luigif/hcsr04/blob/master/hcsr04.c

Proximity::Proximity(){
	data = new double[SAMPLE_SIZE];
	for(int i=0; i<SAMPLE_SIZE; i++){
		data[i]=0;

	}
	length = BAR_LENGTH;
	distance = BAR_LENGTH;
}
int Proximity::measureDistance(double* ret_val){
	
	return 0;
}
double Proximity::avgData(){


}

