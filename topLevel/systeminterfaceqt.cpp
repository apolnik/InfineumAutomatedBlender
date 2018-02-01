#include "systeminterfaceqt.h"
#include "ui_systeminterfaceqt.h"
#include "Stepper.h"
#include "SysParam.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
Stepper s;
RTOS_TMR *timer_obj1;//updates displays text
typedef struct{
	QLabel* disReadOut;
	QLabel* tempReadOut;
	QLabel* weightReadOut;

}displayText;
void updateDisplay(void*);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int waitdelay = 1000;
    	QString errmsg = "Error Starting Timer";
	INT8U err_val;
	INT8 *timer_name[1] = {"Display"};
	displayText labels = {ui->disReadOut,ui->tempReadOut,ui->weightReadOut};
	RTOS_TMR *timer_obj1 = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,
										updateDisplay,&labels,timer_name[0],&err_val);
	if(err_val==0)
		RTOSTmrStart(timer_obj1, &err_val);
	else
		ui->tempReadOut->setText(errmsg);
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
	s.step(&direction);
	s.step(&direction);
	s.step(&direction);
	s.step(&direction);
	s.step(&direction);
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
void updateDisplay(void* label){
	displayText* labels = (displayText*)label;
	QString weight;
	QString temp;
	QString dis;
	double disMeasurement=0;
	s.disSensor.measureDistance(&disMeasurement);
	dis = QString::number(disMeasurement);
	QString garbage = "garbage";
	labels->disReadOut->setText(dis);
	labels->tempReadOut->setText(garbage);
	//labels->weightReadOut->setText(weight);
}