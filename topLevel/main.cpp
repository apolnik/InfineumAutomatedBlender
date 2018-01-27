#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include <QApplication>
#include "systeminterfaceqt.h"

using namespace std;


int main(int argc, char *argv[]){


	QApplication a(argc, argv);
    MainWindow w;
    w.show();
    	OSTickInitialize();
    		RTOSTmrInit();

    return a.exec();



}
