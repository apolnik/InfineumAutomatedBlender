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
	#if 0
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
	prussdrv_init();
	/* Open PRU Interrupt */
	if (prussdrv_open (PRU_EVTOUT_0)) {
		// Handle failure
		fprintf(stderr, ">> PRU open failed\n");
		return -1;
	}

	/* Get the interrupt initialized */
	prussdrv_pruintc_init(&pruss_intc_initdata);

	/* Get pointers to PRU local memory */
	void *pruDataMem;
	prussdrv_map_prumem(PRUSS0_PRU0_DATARAM, &pruDataMem);
	unsigned int *pruData = (unsigned int *) pruDataMem;

	/* Execute code on PRU */
	printf(">> Executing HCSR-04 code\n");
	prussdrv_exec_program(0, "hcsr04.bin");
	prussdrv_pru_wait_event (PRU_EVTOUT_0);
	prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);
	prussdrv_pru_disable(0);
	prussdrv_exit();
	*ret_val = (double) pruData[0] / 148.4376;
	distance = *ret_val;
	for(int i =SAMPLE_SIZE-1; i>0;i--){
		data[i]=data[i-1];

	}
	data[0]=distance;
	#endif
	return 0;
}
double Proximity::avgData(){


}

