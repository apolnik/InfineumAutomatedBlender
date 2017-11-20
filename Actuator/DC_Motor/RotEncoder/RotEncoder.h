#ifndef RotEncoder_H
#define RotEncoder_H
 

class RotEncoder{
	public:
	double speed;
	double* data;

	RotEncoder();
	
	double measureSpeed();
	double avgData();

}; 
#endif /* RotEncoder_H */
