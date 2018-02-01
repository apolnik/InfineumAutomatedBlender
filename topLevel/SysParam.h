//PINOUT
#define STEPPER_MS1_PIN 1
#define STEPPER_MS2_PIN 2
#define STEPPER_STEP_PIN 3
#define STEPPER_SLP_PIN 4
#define STEPPER_DIR_PIN 5

#define DCMOT1_PIN 6
#define DCMOT2_PIN 7
#define DCMOT3_PIN 8
#define DCMOT4_PIN 9

#define IRTEMP1_PIN 10
#define IRTEMP2_PIN 11
#define IRTEMP3_PIN 12
#define IRTEMP4_PIN 13
#define CTEMP1_PIN 14
#define CTEMP2_PIN 15
#define CTEMP3_PIN 16
#define CTEMP4_PIN 17
#define HEATPAD1_PIN	18
#define HEATPAD2_PIN	19
#define HEATPAD3_PIN	20
#define HEATPAD4_PIN	21


//Stepper Motor Parameters
#define MIN_STEP_DIS 0.25f
#define BASE_SPEED 60//rpm
#define START_POS 30//inches
#define BAR_LENGTH 32//inches
#define BEAKER1_POS	6
#define BEAKER2_POS	12
#define	BEAKER3_POS	18
#define GARBAGE		24
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

#define VALVE_1		1
#define VALVE_2		2
#define VALVE_3		3
#define VALVE_4		4
#define VALVE_5		5
#define VALVE_6		6
#define VALVE_7		7
#define VALVE_8		8
#define VALVE_9		9
#define VALVE_10	10
