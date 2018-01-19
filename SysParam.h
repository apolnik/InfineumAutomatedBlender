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


//Stepper Motor Parameters
#define MIN_STEP_DIS 0.25f
#define BASE_SPEED 60//rpm
#define START_POS 30//inches
#define BAR_LENGTH 32//inches

//IR Temp Sensor I2C Addresses
#define IR_TEMP_TO_MAX 		0x000
#define IR_TEMP_TO_MIN 		0x001
#define IR_TEMP_TA_RANGE 	0x003
#define IR_TEMP_PWM_CNTRL	0x002
#define IR_TEMP_EM_COEF		0x004 	//Emissivity = dec2hex[ round( 65535 x ε) ] 
#define IR_TEMP_SMBUS_ADDR	0x00D



