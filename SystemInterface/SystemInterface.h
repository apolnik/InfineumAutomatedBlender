#ifndef SystemInterface_H
#define SystemInterface_H
#include "mixCntrl.h"
#include "FluidTranCntrl.h"

class SystemInterface{
	public:
	mixCntrl* mixer;
	FluidTranCntrl* fluidtrans;
	
	SystemInterface();
	

	int addFluid();
	int mixBeaker();
	int DisplayLogs();
	int RaiseAlarms();

};
#endif /* SystemInterface_H */
