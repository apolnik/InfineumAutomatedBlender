#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include <QApplication>
#include "systeminterfaceqt.h"
#include "Stepper.h"

using namespace std;


int main(int argc, char *argv[]){

	//OSTickInitialize();
    	//RTOSTmrInit();
	QApplication a(argc, argv);
    MainWindow w;
    w.show();
    	
    return a.exec();



}

