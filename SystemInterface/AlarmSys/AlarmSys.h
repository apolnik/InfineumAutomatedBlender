#ifndef AlarmSys_H
#define AlarmSys_H
 

class AlarmSys{
	public:
	int status;

	AlarmSys();
	
	int raiseAlarm();
	int ckTempThres();
	int ckProxThres();
	int ckWeightThres();
	int ckMotorRPMThres();
	int ckError();

};
#endif /* AlarmSys_H */
