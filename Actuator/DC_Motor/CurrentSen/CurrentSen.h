#ifndef CurrentSen_H
#define CurrentSen_H
 

class CurrentSen{
	public:
	double current;
	double* data;

	CurrentSen();
	
	double measureCurrent();
	double avgData();

}; 
#endif /* CurrentSen_H */
