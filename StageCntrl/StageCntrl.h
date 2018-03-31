#ifndef StageCntrl_H
#define StageCntrl_H
typedef struct StageParam{
	double mixtime;
    double heattime;
    int targetTemp;
    double fluidAmnt;
    int fluidID;
}sparam_t;
typedef struct BatchParam{
	int numStages;
	sparam_t stg1;
    sparam_t stg2;
    sparam_t stg3;
    sparam_t stg4;
    sparam_t stg5;	
}bparam_t;
class StageCntrl{
public:
	bparam_t * c_batches;
	int num_batches;
	StageCntrl(bparam_t* batches, int numBatches);
	~StageCntrl();
	int startThreads();
	int executeBatch();
	void* heatThread(int batchnum);
	void* DC_mixCntrl();
};


#endif