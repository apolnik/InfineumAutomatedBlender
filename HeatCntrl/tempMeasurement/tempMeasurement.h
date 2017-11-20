#ifndef tempMeasurement_H
#define tempMeasurement_H
 

class tempMeasurement{
	public:
	int tempsensorID;
	double* data;
	double temp;

	tempMeasurement();
	
	double measureHeat();
	double avgData();

}; 
#endif /* tempMeasurement_H */
