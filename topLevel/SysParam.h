//PINOUT STEPPER
#define STEPPER_MS1_PIN 0
#define STEPPER_MS2_PIN 0
#define STEPPER_STEP_PIN 0
#define STEPPER_SLP_PIN 45
#define STEPPER_DIR_PIN 46

#define DCMOT1_DIR_PIN 6
#define DCMOT2_DIR_PIN 7
#define DCMOT3_DIR_PIN 8
#define DCMOT4_DIR_PIN 9
#define DCMOT1_PWM_PIN 6
#define DCMOT2_PWM_PIN 7
#define DCMOT3_PWM_PIN 8
#define DCMOT4_PWM_PIN 9

#define LOAD_CELL1_PIN 1 //44
#define LOAD_CELL2_PIN 2
#define LOAD_CELL3_PIN 3
#define LOAD_CELL4_PIN 4
#define LOAD_CELL1_CLK 1 //46
#define LOAD_CELL2_CLK 2
#define LOAD_CELL3_CLK 3
#define LOAD_CELL4_CLK 4


#define IRTEMP1_PIN 10
#define IRTEMP2_PIN 11
#define IRTEMP3_PIN 12
#define IRTEMP4_PIN 13
#define CTEMP1_PIN 14
#define CTEMP2_PIN 15
#define CTEMP3_PIN 16
#define CTEMP4_PIN 17
#define HEATPAD1_PIN	47
#define HEATPAD2_PIN	19
#define HEATPAD3_PIN	20
#define HEATPAD4_PIN	21
//Pump Pins
<<<<<<< HEAD
#define PERISTALLTIC120 27
#define DIAPHRAGM_PUMP 2
#define PERISTALLTIC12 3
=======
#define PERISTALLTIC120 
#define DIAPHRAGM_PUMP 44
#define PERISTALLTIC12 ""
>>>>>>> 33ffdb11cd1dd77179c0670c60f629e15f547162
#define PERI12_DIR 4
#define DIA_DIR 5

//Stepper Motor Parameters
#define MIN_STEP_DIS 0.25f
#define BASE_SPEED 60//rpm
#define START_POS 0//inches
#define BAR_LENGTH 13//inches
#define BEAKER1_POS	0
#define BEAKER2_POS	8
#define	BEAKER3_POS	18
#define GARBAGE		24

//DC Motor Parameters
#define DEFAULT_PERIOD_DC 4000
#define DEFAULT_DUTY_DC 2000
//IR Temp Sensor I2C Addresses Read
#define IR_TEMP_OBJ_1		0x07
//IR Temp Sensor I2C Addresses Write
#define IR_TEMP_DEV_ADDR	0x5A
#define IR_TEMP_TO_MAX 		0x000
#define IR_TEMP_TO_MIN 		0x001
#define IR_TEMP_TA_RANGE 	0x003
#define IR_TEMP_PWM_CNTRL	0x002
#define IR_TEMP_EM_COEF		0x004 	//Emissivity = dec2hex[ round( 65535 x ε) ] 
#define IR_TEMP_SMBUS_ADDR	0x00D
//Contact Temp Sensor I2c Addresses
//https://cdn-shop.adafruit.com/datasheets/MCP9808.pdf
#define C_TEMP_DEV_ADDR				   0x18
#define MCP9808_REG_UPPER_TEMP         0x02
#define MCP9808_REG_LOWER_TEMP         0x03
#define MCP9808_REG_CRIT_TEMP          0x04
#define MCP9808_REG_AMBIENT_TEMP       0x05
#define MCP9808_REG_MANUF_ID           0x06
#define MCP9808_REG_DEVICE_ID          0x07

#define HEAT_FREQ	60
#define DEFAULT_DUTY_CYC	0.5

#define VALVE_1		66
#define VALVE_2		67
#define VALVE_3		3
#define VALVE_4		4
#define VALVE_5		5
#define VALVE_6		6
#define VALVE_7		7
#define VALVE_8		8
#define VALVE_9		9
#define VALVE_10	10

//Current Sensor
#define INA219_ADDRESS              0x40
#define INA219_REG_CURRENT			0x04
#define INA219_REG_CONFIG                      (0x00)
#define INA219_REG_POWER                       (0x03)
