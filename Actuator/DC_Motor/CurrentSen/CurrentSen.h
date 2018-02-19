#ifndef CurrentSen_H
#define CurrentSen_H
#define INA219_REG_CALIBRATION          0x05 
#define INA219_CONFIG_BVOLTAGERANGE_32V         (0x2000)
#define INA219_CONFIG_GAIN_8_320MV              (0x1800)
#define INA219_CONFIG_BADCRES_12BIT             (0x0180)
#define INA219_CONFIG_SADCRES_12BIT_1S_532US    (0x0018)
#define INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS (0x0007)
/**************************************************************************/
/*! 
    @brief  default I2C address
*/
/**************************************************************************/
    #define INA219_ADDRESS                         (0x40)    // 1000000 (A0+A1=GND)

/**************************************************************************/
/*! 
    @brief  read
*/
/**************************************************************************/
    #define INA219_READ                            (0x01)

/*=========================================================================
    CONFIG REGISTER (R/W)
    -----------------------------------------------------------------------*/

/**************************************************************************/
/*! 
    @brief  config register address
*/
/**************************************************************************/
    #define INA219_REG_CONFIG                      (0x00)
    /*---------------------------------------------------------------------*/

/**************************************************************************/
/*! 
    @brief  reset bit
*/
/**************************************************************************/
    #define INA219_CONFIG_RESET                    (0x8000)  // Reset Bit

/**************************************************************************/
/*! 
    @brief  mask for bus voltage range
*/
/**************************************************************************/
    #define INA219_CONFIG_BVOLTAGERANGE_MASK       (0x2000)  // Bus Voltage Range Mask

/**************************************************************************/
/*! 
    @brief  bus voltage range values
*/
/**************************************************************************/
//enum{
   #define  INA219_CONFIG_BVOLTAGERANGE_16V         (0x0000) 
 // 0-16V Range
   #define  INA219_CONFIG_BVOLTAGERANGE_32V         (0x2000) 
 // 0-32V Range
//};


/**************************************************************************/
/*! 
    @brief  mask for gain bits
*/
/**************************************************************************/
    #define INA219_CONFIG_GAIN_MASK                (0x1800)  // Gain Mask

/**************************************************************************/
/*! 
    @brief  values for gain bits
*/
/**************************************************************************/
///enum{
   #define INA219_CONFIG_GAIN_1_40MV               (0x0000)
  // Gain 1, 40mV Range
   #define INA219_CONFIG_GAIN_2_80MV               (0x0800)
  // Gain 2, 80mV Range
   #define INA219_CONFIG_GAIN_4_160MV              (0x1000)
  // Gain 4, 160mV Range
   #define INA219_CONFIG_GAIN_8_320MV              (0x1800)
  // Gain 8, 320mV Range
//  };
	
  /**************************************************************************/
/*! 
    @brief  mask for bus ADC resolution bits
*/
/**************************************************************************/
    #define INA219_CONFIG_BADCRES_MASK             (0x0780)  // Bus ADC Resolution Mask

/**************************************************************************/
/*! 
    @brief  values for bus ADC resolution
*/
/**************************************************************************/
//enum {
   #define INA219_CONFIG_BADCRES_9BIT              (0x0000)
  // 9-bit bus res = 0..511
   #define INA219_CONFIG_BADCRES_10BIT             (0x0080)
  // 10-bit bus res = 0..1023
   #define INA219_CONFIG_BADCRES_11BIT             (0x0100)
  // 11-bit bus res = 0..2047
   #define INA219_CONFIG_BADCRES_12BIT             (0x0180)
  // 12-bit bus res = 0..4097
//};

/**************************************************************************/
/*! 
    @brief  mask for shunt ADC resolution bits
*/
/**************************************************************************/  
    #define INA219_CONFIG_SADCRES_MASK             (0x0078)  // Shunt ADC Resolution and Averaging Mask

/**************************************************************************/
/*! 
    @brief  values for shunt ADC resolution
*/
/**************************************************************************/
//enum {
   #define INA219_CONFIG_SADCRES_9BIT_1S_84US      (0x0000)
  // 1 x 9-bit shunt sample
   #define INA219_CONFIG_SADCRES_10BIT_1S_148US    (0x0008)
 // 1 x 10-bit shunt sample
   #define INA219_CONFIG_SADCRES_11BIT_1S_276US    (0x0010)
  // 1 x 11-bit shunt sample
   #define INA219_CONFIG_SADCRES_12BIT_1S_532US    (0x0018)
  // 1 x 12-bit shunt sample
   #define INA219_CONFIG_SADCRES_12BIT_2S_1060US   (0x0048)
	 // 2 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_4S_2130US   (0x0050)
  // 4 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_8S_4260US   (0x0058)
  // 8 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_16S_8510US  (0x0060)
  // 16 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_32S_17MS    (0x0068)
  // 32 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_64S_34MS    (0x0070)
  // 64 x 12-bit shunt samples averaged together
   #define INA219_CONFIG_SADCRES_12BIT_128S_69MS   (0x0078) 
 // 128 x 12-bit shunt samples averaged together
//};

/**************************************************************************/
/*! 
    @brief  mask for operating mode bits
*/
/**************************************************************************/
    #define INA219_CONFIG_MODE_MASK                (0x0007)  // Operating Mode Mask

/**************************************************************************/
/*! 
    @brief  values for operating mode
*/
/**************************************************************************/
// enum {   
  #define INA219_CONFIG_MODE_POWERDOWN            (0x0000)
  #define INA219_CONFIG_MODE_SVOLT_TRIGGERED      (0x0001)
  #define INA219_CONFIG_MODE_BVOLT_TRIGGERED      (0x0002)
  #define INA219_CONFIG_MODE_SANDBVOLT_TRIGGERED  (0x0003)
  #define INA219_CONFIG_MODE_ADCOFF               (0x0004)
  #define INA219_CONFIG_MODE_SVOLT_CONTINUOUS    (0x0005)
  #define INA219_CONFIG_MODE_BVOLT_CONTINUOUS     (0x0006)
   #define INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS  (0x0007)
//};
/*=========================================================================*/

/**************************************************************************/
/*! 
    @brief  shunt voltage register
*/
/**************************************************************************/
    #define INA219_REG_SHUNTVOLTAGE                (0x01)
/*=========================================================================*/

/**************************************************************************/
/*! 
    @brief  bus voltage register
*/
/**************************************************************************/
    #define INA219_REG_BUSVOLTAGE                  (0x02)
/*=========================================================================*/

/**************************************************************************/
/*! 
    @brief  power register
*/
/**************************************************************************/
    #define INA219_REG_POWER                       (0x03)
/*=========================================================================*/

/**************************************************************************/
/*! 
    @brief  current register
*/
/**************************************************************************/
    #define INA219_REG_CURRENT                     (0x04)
/*=========================================================================*/

/**************************************************************************/
/*! 
    @brief  calibration register
*/
/**************************************************************************/
    #define INA219_REG_CALIBRATION                 (0x05)
/*=========================================================================*/
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
