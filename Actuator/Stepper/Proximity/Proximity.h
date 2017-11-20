#ifndef Proximity_H
#define Proximity_H
 

class Proximity{
	public:
	double distance;
	double length;
	double* data;

	Proximity();
	
	double measureDistance();
	double avgData();

}; 
#endif /* Proximity_H */
