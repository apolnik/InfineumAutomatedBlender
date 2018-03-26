  #include "HX711.h"
  int motorPWM_pin;
  int miniPeriPump1;
  int miniPeriPump2;
  int loadCell1_sda = 1;
  int loadCell2_sda = 2;
  int loadCell3_sda = 3;
  int loadCell4_sda = 4;
  int loadCell_scl = 5;
  int tempProbe1;
  int tempProbe2;
  int tempProbe3;
  int tempProbe4;

  int DEFAULTPWM;
  int dcMotorPWM;
  int miniPeri1PWM;
  int miniPeri2PWM;


  HX711 scale1(loadCell1_sda, loadCell_scl);
  HX711 scale2(loadCell2_sda, loadCell_scl);
  HX711 scale3(loadCell3_sda, loadCell_scl);
  HX711 scale4(loadCell4_sda, loadCell_scl);
void setup() {
  // put your setup code here, to run once:
     motorPWM_pin = 1;
   miniPeriPump1 = 2;
   miniPeriPump2 = 3;

   DEFAULTPWM = 100;
   dcMotorPWM = DEFAULTPWM;
   miniPeri1PWM = DEFAULTPWM;
   miniPeri2PWM = DEFAULTPWM;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      
    char c = Serial.read();
    if(c == 'm'){
      if(Serial.available())
      {
        c = Serial.read();
        if(c == '1'){
          //turn on to default pwm value
          dcMotorPWM = DEFAULTPWM;
          analogWrite(motorPWM_pin, dcMotorPWM);
          
        }
        else if(c == 'u'){
          //increase pwm  
          if(dcMotorPWM<255) dcMotorPWM++;
          analogWrite(motorPWM_pin, dcMotorPWM);
        }
        else if(d == 'd'){
          //decrease pwm
          if(dcMotorPWM>0) dcMotorPWM--;
          analogWrite(motorPWM_pin, dcMotorPWM);
        }
        else if(c == '0'){
          //turn off pwm
          dcMotorPWM = 0;
          analogWrite(motorPWM_pin, dcMotorPWM);
        }
        else{
          //do nothing
        }   
      }  
      
    }
    else if(c == 'p'){
      if(Serial.available())
      {
        c = Serial.read();
        if(c == '1'){
          //mini Peristalltic pump 1  
          if(Serial.available())
          {
            c = Serial.read();
            if(c == '1'){
              //turn on to default pwm value
              miniPeri1PWM = DEFAULTPWM;
              analogWrite(miniPeriPump1, miniPeri1PWM);
              
            }
            else if(c == 'u'){
              //increase pwm  
              if(miniPeri1PWM<255) miniPeri1PWM++;
              analogWrite(miniPeriPump1, miniPeri1PWM);
            }
            else if(d == 'd'){
              //decrease pwm
              if(miniPeri1PWM>0) miniPeri1PWM--;
              analogWrite(miniPeriPump1, miniPeri1PWM);
            }
            else if(c == '0'){
              //turn off pwm
              miniPeri1PWM = 0;
              analogWrite(miniPeriPump1, miniPeri1PWM);
            }
            else{
              //do nothing
            }   
          }
        }
        else if(c=='2'){
          //mini Peristalltic pump 2 
          if(Serial.available())
          {
            c = Serial.read();
            if(c == '1'){
              //turn on to default pwm value
              miniPeri2PWM = DEFAULTPWM;
              analogWrite(miniPeriPump2, miniPeri2PWM);
              
            }
            else if(c == 'u'){
              //increase pwm  
              if(miniPeri2PWM<255) miniPeri2PWM++;
              analogWrite(miniPeriPump2, miniPeri2PWM);
            }
            else if(d == 'd'){
              //decrease pwm
              if(miniPeri2PWM>0) miniPeri2PWM--;
              analogWrite(miniPeriPump2, miniPeri2PWM);
            }
            else if(c == '0'){
              //turn off pwm
              miniPeri2PWM = 0;
              analogWrite(miniPeriPump2, miniPeri2PWM);
            }
            else{
              //do nothing
            } 
          }
        }
        else{
          
        }   
      }  
      
    }
    else if(c == 'd'){
      //collect and relay all sensors connected to arduino
      //Load Cell Readings
      Serial.print(scale1.read_average(20));
      Serial.print(scale2.read_average(20));
      Serial.print(scale3.read_average(20));
      Serial.print(scale4.read_average(20));



      //Temperature Probe Readings 





      //Flow Sensor Readings




      
    }
  }
  
}
