#ifndef HeatCntrl_H
#define HeatCntrl_H
 

class HeatCntrl{
	public:
	int heatID;
	int heaterType;
	double templ
	tempMeasurement* tempSensor;


	HeatCntrl();

	int activateHeater();
	double getTemp();

}; 
#endif /* HeatCntrl_H */
