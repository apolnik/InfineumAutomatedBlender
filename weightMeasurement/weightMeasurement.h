#ifndef weightMeasurement_H
#define weightMeasurement_H


class weightMeasurement{
	public:
	
	int scaleID;
	double* data;
	double weight;

	weightMeasurement();
	
	double measureWeight();
	double avgData();

};
 
#endif /* weightMeasurement_H */
