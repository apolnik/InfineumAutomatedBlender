#include "StageCntrl.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t fluid_tran;
pthread_mutex_t barrier;

pthread_cond_t cond_barrier;
StageCntrl::StageCntrl(bparam_t* batches, int numBatches){
	c_batches = batches;
	num_batches = numBatches;
}
int stage;
int max_numStages;
int StageCntrl::startThreads(){
	pthread_t batches[num_batches];
	int batch_index[num_batches];
	

	for(int i = 0; i<num_batches; i++){
		batch_index[i]=i;
		pthread_create(&batches[i],NULL,heatThread,&batch_index[i]);
	}
	for(int i = 0; i<num_batches; i++){

		pthread_join(&batches[i],NULL);
	}

}
StageCntrl::~StageCntrl(){


}
//The purpose of using threads here is that there
//are some aspects of control that need to be done concurrently.
//...mainly heat control. The other stuff is done sequentially
int StageCntrl::executeBatch(){
	int stagecnt = c_batches[0]->numStages;
	int i = 0;
	ValveCntrl valve1(VALVE_1);
	ValveCntrl valve2(VALVE_2);
	ValveCntrl valve3(VALVE_3);
	ValveCntrl valve4(VALVE_4);
	ValveCntrl valve5(VALVE_5);

	for(i=0;i<stagecnt; i++){
		for(int j=0; j<num_batches; j++){
			stage=i;

			ValveCntrl *valve_ptr;
		//Fluid transfer for each batch
			int position = 0;
			double fluid_amount =0;

			if(i==0){
				fluid_amount = c_batches[j].stg1.fluidAmnt;
				valve_ptr = &valve1;
			}
			else if(i==1){
				fluid_amount = c_batches[j].stg2.fluidAmnt;
				valve_ptr = &valve2;
			}
			else if(i==2){
				fluid_amount = c_batches[j].stg3.fluidAmnt;
				valve_ptr = &valve3;
			}
			else if(i==3){
				fluid_amount = c_batches[j].stg4.fluidAmnt;
				valve_ptr = &valve4;
			}
			else if(i==4){
				fluid_amount = c_batches[j].stg5.fluidAmnt;
				valve_ptr = &valve5;
			}
			if(j==0){
				position = BEAKER1_POS;
				
			}
			else if(j==1){
				position = BEAKER2_POS;
			}
			else if(j==2){
				position = BEAKER3_POS;
			}
			else if(j==3){
				position = BEAKER4_POS;
			}

			valve_ptr->moveValve(position);
			fillsyringePump(fluid_amount);
			valve_ptr->openValve();
			dispenseSyringePump(fluid_amount);
			valve_ptr->closeValve();	
			//Done with Fluid transfer
	
		}

		//Heating and stirring
		startThreads();



		//Done with stage
	}
}
void* StageCntrl::heatThread(int batchnum){
	//We use "stage" to determine what stage we are at
	int duration=0;
	double targetTemp=0;
	int pad=0;
	if(stage == 0){
		duration = c_batches[batchnum].stg1.heattime;
		targetTemp = c_batches[batchnum].stg1.targetTemp;
	}
	else if(stage == 1){
		duration = c_batches[batchnum].stg2.heattime;
		targetTemp = c_batches[batchnum].stg2.targetTemp;
	}
	else if(stage == 2){
		duration = c_batches[batchnum].stg3.heattime;
		targetTemp = c_batches[batchnum].stg3.targetTemp;
	}
	else if(stage == 3){
		duration = c_batches[batchnum].stg4.heattime;
		targetTemp = c_batches[batchnum].stg4.targetTemp;
	}
	else if(stage == 4){
		duration = c_batches[batchnum].stg5.heattime;
		targetTemp = c_batches[batchnum].stg5.targetTemp;
	}
	if(batchnum==0){
		pad = HEATPAD1_PIN;
	}
	else if(batchnum==1){
		pad = HEATPAD2_PIN;
	}
	else if(batchnum==2){
		pad = HEATPAD3_PIN;
	}
	else if(batchnum==3){
		pad = HEATPAD4_PIN;
	}

	HeatCntrl* h = new HeatCntrl(pad);
	h->setDesiredTemp(targetTemp,(double)duration);



}