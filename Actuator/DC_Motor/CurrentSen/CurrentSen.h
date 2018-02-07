#ifndef CurrentSen_H
#define CurrentSen_H
 
#define INA219_CONFIG_BVOLTAGERANGE_32V         (0x2000)
#define INA219_CONFIG_GAIN_8_320MV              (0x1800)
#define INA219_CONFIG_BADCRES_12BIT             (0x0180)
#define INA219_CONFIG_SADCRES_12BIT_1S_532US    (0x0018)
#define INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS (0x0007)
class CurrentSen{
	public:
	double current;
	double* data;
	int currentID;

	CurrentSen(int);
	~CurrentSen();
	short ina219_calValue;
	double measureCurrent();
	double avgData();
	int calibrate(short config);
	double measurePower();
}; 
#endif /* CurrentSen_H */
