#ifndef DC_Motor_H
#define DC_Motor_H
 

class DC_Motor : public Actuator{
	public:
	
	bool stirrer;
	int position;
	double speed;
	double torque;
	double power;

	weightMeasurement();

	double getSpeed();
	int setSpeed();

}; 
#endif /* DC_Motor_H */
