#ifndef weightMeasurement_H
#define weightMeasurement_H


class weightMeasurement{
	public:
	static double beaker1_weight;
	static double beaker2_weight;
	static double beaker3_weight;
	static double beaker4_weight;

	int scaleID;
	int clkID;
	double* data;
	double weight;

	weightMeasurement(int);
	~weightMeasurement();	
	unsigned int measureWeight();
	double avgData();

};
 
#endif /* weightMeasurement_H */
