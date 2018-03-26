#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>   // using the termios.h library
#include <string.h>
int openArduino(){
	int file;
	if ((file = open("/dev/ttyO4", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Failed to open the file.\n");
      return -1;
   }
   struct termios options;               //The termios structure is vital
   tcgetattr(file, &options);            //Sets the parameters associated with file
    // Set up the communications options:
   //   9600 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;    //ignore partity errors, CR -> newline
   tcflush(file, TCIFLUSH);             //discard file information not transmitted
   tcsetattr(file, TCSANOW, &options);  //changes occur immmediately
   return file;
}


int sendArduino(char* s, int file){
	int count;
	int len = strlen(s);
	   if ((count = write(file, &s,len+1))<0){        //send the string
      		perror("Failed to write to the output\n");
      return -1;
   }

}
int recvArduino(char* s, int file){
	int count;
	 if ((count = read(file, (void*)(s), 100))<0){   //receive the data
    	  perror("Failed to read from the input\n");
    	  return -1;
   	}
   
   return 0;

}
void closeArduino(int file){
	
	close(file);
}
