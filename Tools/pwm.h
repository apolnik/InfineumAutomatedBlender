#ifndef pwm_H
#define pwm_H

int setPeriod(int pin, unsigned int period);
int getPeriod(int pin);
int setDutyCyc(int pin, unsigned int duty);
double getDutyCyc(int pin);
int setPolarity(int pin, int polarity);
int start_running_pwm(int pin);
int stop_pwm(int pin);

#endif