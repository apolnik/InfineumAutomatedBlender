#include <QCoreApplication>
#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"

using namespace std;


int main(int argc, char *argv[]){

	// Initialize the OS Tick
	OSTickInitialize();

	// Initialize the RTOS Timer
	RTOSTmrInit();	
	


}