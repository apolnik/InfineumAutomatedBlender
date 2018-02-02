#include "systeminterfaceqt.h"
#include "ui_systeminterfaceqt.h"
#include "Stepper.h"
#include "SysParam.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
Stepper* s;
RTOS_TMR *timer_obj1;//updates displays text
typedef struct{
	QLabel* disReadOut;
	QLabel* tempReadOut;
	QLabel* weightReadOut;

}displayText;
Ui::MainWindow* gui=NULL;
void MainWindow::updateDisplay(void* label){
	//displayText* labels = (displayText*)label;
	//QString weight;
	//QString temp;
	//QString dis;
	//double disMeasurement=0;
	//s.disSensor.measureDistance(&disMeasurement);
	//dis = QString::number(disMeasurement);
	QString garbage = "garbage";
	//gui->disReadOut->setText(dis);
	gui->tempReadOut->setText(garbage);
	//ui->weightReadOut->setText(weight);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	s = new Stepper();
	int direction = FORWARD;
	s->setMode(FULLSTEP);
        s->step(&direction);
        s->step(&direction);
        s->step(&direction);
        s->step(&direction);
        s->step(&direction);

	QString dis;
    	ui->setupUi(this);
    	gui = ui;
    	int waitdelay = 1000;
	OSTickInitialize();
	RTOSTmrInit();
    	QString errmsg = "Error Starting Timer";
	INT8U err_val;
	INT8 *timer_name[1] = {"Display"};
	displayText labels = {ui->disReadOut,ui->tempReadOut,ui->weightReadOut};
	RTOS_TMR *timer_obj1 = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,
											updateDisplay,&labels,timer_name[0],&err_val);
	
	//double disMeasurement=0;
        //s.disSensor.measureDistance(&disMeasurement);
        //dis = QString::number(disMeasurement);
        QString garbage = "garbage";
        //gui->disReadOut->setText(dis);
        gui->tempReadOut->setText(garbage);

	if(err_val==0)
		RTOSTmrStart(timer_obj1, &err_val);
	else
		ui->tempReadOut->setText(QString::number(err_val));
}

MainWindow::~MainWindow()
{
    delete ui;
   	INT8U err_val;
    RTOSTmrDel(timer_obj1,&err_val);
}

void MainWindow::on_pump1Btn_clicked()
{
	int direction = FORWARD;
	s->setMode(FULLSTEP);
	s->step(&direction);
	s->step(&direction);
	s->step(&direction);
	s->step(&direction);
	s->step(&direction);
}

void MainWindow::on_pump2Btn_clicked()
{

}

void MainWindow::on_clnBtn_clicked()
{

}

void MainWindow::on_linearRail_rangeChanged(int min, int max)
{

}

