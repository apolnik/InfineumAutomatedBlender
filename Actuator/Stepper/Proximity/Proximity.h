#ifndef Proximity_H
#define Proximity_H
#define SAMPLE_SIZE 5

class Proximity{
	public:
	double distance;
	double length;
	double* data;

	Proximity();
	
	int measureDistance(double* ret_val);
	double avgData();

}; 
#endif /* Proximity_H */
