#ifndef HeatCntrl_H
#define HeatCntrl_H

#include "tempMeasurement.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#define eps_derv .5
class HeatCntrl{
private:
	int setPWM(double dutycyc, void* rise, void* fall);
	static void measureStats(void *);
public:
	bool testing;
	bool kill;
	double kp;
	double kd;
	double ki;
	double kp_crit;
	double T_crit;
	double derivatives[1000];
	int counter;
	int heatID;
	int heaterType;
	double temp;
	double duty;
	double target_temp;
	double err_old;
	double integral;
	double temp_pres;
	tempMeasurement* IRtempSensor;
	tempMeasurement* CtempSensor;
	RTOS_TMR *fall_timer;
	RTOS_TMR *rise_timer;
	RTOS_TMR *stat_timer;
	RTOS_TMR *kill_timer;
	HeatCntrl(int heat);

	//void activateHeater();
	int setDesiredTemp(double temp, double hold_time);
	double getTemp();
	void updatePWM();
	int testHeatCntrl(int iterations, int fd);
}; 
#endif /* HeatCntrl_H */
