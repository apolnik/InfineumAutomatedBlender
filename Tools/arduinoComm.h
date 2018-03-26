#ifndef ARDUINO_UART
#define ARDUINO_UART
int openArduino();
int sendArduino(char* s, int file);
int recvArduino(char* s, int file);

void closeArduino(int file);


#endif