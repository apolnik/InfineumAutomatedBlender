#include "CurrentSen.h"
#include "i2cTool.h"
#include "SysParam.h"
void setCalibration_16V_400mA();
CurrentSen::CurrentSen(int id){
	currentID = id;
	ina219_calValue=4096;
	short config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

   // calibrate(config);
	setCalibration_16V_400mA();
}
CurrentSen::~CurrentSen(){

}

void setCalibration_16V_400mA(void) {
  
  // Calibration which uses the highest precision for 
  // current measurement (0.1mA), at the expense of 
  // only supporting 16V at 400mA max.

  // VBUS_MAX = 16V
  // VSHUNT_MAX = 0.04          (Assumes Gain 1, 40mV)
  // RSHUNT = 0.1               (Resistor value in ohms)
  
  // 1. Determine max possible current
  // MaxPossible_I = VSHUNT_MAX / RSHUNT
  // MaxPossible_I = 0.4A

  // 2. Determine max expected current
  // MaxExpected_I = 0.4A
  
  // 3. Calculate possible range of LSBs (Min = 15-bit, Max = 12-bit)
  // MinimumLSB = MaxExpected_I/32767
  // MinimumLSB = 0.0000122              (12uA per bit)
  // MaximumLSB = MaxExpected_I/4096
  // MaximumLSB = 0.0000977              (98uA per bit)
  
  // 4. Choose an LSB between the min and max values
  //    (Preferrably a roundish number close to MinLSB)
  // CurrentLSB = 0.00005 (50uA per bit)
  
  // 5. Compute the calibration register
  // Cal = trunc (0.04096 / (Current_LSB * RSHUNT))
  // Cal = 8192 (0x2000)

 int  ina219_calValue = 8192;

  // 6. Calculate the power LSB
  // PowerLSB = 20 * CurrentLSB
  // PowerLSB = 0.001 (1mW per bit)
  
  // 7. Compute the maximum current and shunt voltage values before overflow
  //
  // Max_Current = Current_LSB * 32767
  // Max_Current = 1.63835A before overflow
  //
  // If Max_Current > Max_Possible_I then
  //    Max_Current_Before_Overflow = MaxPossible_I
  // Else
  //    Max_Current_Before_Overflow = Max_Current
  // End If
  //
  // Max_Current_Before_Overflow = MaxPossible_I
  // Max_Current_Before_Overflow = 0.4
  //
  // Max_ShuntVoltage = Max_Current_Before_Overflow * RSHUNT
  // Max_ShuntVoltage = 0.04V
  //
  // If Max_ShuntVoltage >= VSHUNT_MAX
  //    Max_ShuntVoltage_Before_Overflow = VSHUNT_MAX
  // Else
  //    Max_ShuntVoltage_Before_Overflow = Max_ShuntVoltage
  // End If
  //
  // Max_ShuntVoltage_Before_Overflow = VSHUNT_MAX
  // Max_ShuntVoltage_Before_Overflow = 0.04V
  
  // 8. Compute the Maximum Power
  // MaximumPower = Max_Current_Before_Overflow * VBUS_MAX
  // MaximumPower = 0.4 * 16V
  // MaximumPower = 6.4W
  
  // Set multipliers to convert raw current/power values
 int  ina219_currentDivider_mA = 20;  // Current LSB = 50uA per bit (1000/50 = 20)
 int ina219_powerMultiplier_mW = 1;     // Power LSB = 1mW per bit

  // Set Calibration register to 'Cal' calculated above 
  //wireWriteRegister(INA219_REG_CALIBRATION, ina219_calValue);
  i2cTool Sensor;
        Sensor.sendBytes(ina219_calValue, INA219_REG_CALIBRATION, 5);
  // Set Config register to take into account the settings above
  int config = INA219_CONFIG_BVOLTAGERANGE_16V |
                    INA219_CONFIG_GAIN_1_40MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;
 // wireWriteRegister(INA219_REG_CONFIG, config);
 Sensor.sendBytes(config,INA219_ADDRESS,INA219_REG_CONFIG);

}

double CurrentSen::measureCurrent(){
	char buf[3];

	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,5);

	Sensor.readBytes(INA219_ADDRESS,INA219_REG_CURRENT,3,buf);
	double ret_val = double((buf[0]<<8) | buf[1])/10;
	return ret_val;

}
double CurrentSen::measurePower(){
	char buf[3];

	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,5);

	Sensor.readBytes(INA219_ADDRESS,INA219_REG_POWER,3,buf);
	double ret_val = 2* double((buf[0]<<8) | buf[1]);
	return ret_val;

}

double CurrentSen::avgData(){


	
}
int CurrentSen::calibrate(short config){
	i2cTool Sensor;
	Sensor.sendBytes(ina219_calValue,INA219_ADDRESS,5);
	return Sensor.sendBytes(config,INA219_ADDRESS,INA219_REG_CONFIG);



}
