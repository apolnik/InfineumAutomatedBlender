
#include "systeminterfaceqt.h"
#include "ui_systeminterfaceqt.h"
#include "Stepper.h"
#include "SysParam.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include "gpioTool.h"
#include "tempMeasurement.h"
#include "unistd.h"
Stepper* s;
RTOS_TMR *timer_obj1;//updates displays text
typedef struct{
	QLabel* disReadOut;
	QLabel* tempReadOut;
	QLabel* weightReadOut;

}displayText;
Ui::MainWindow* gui=NULL;
tempMeasurement* tm;
void MainWindow::updateDisplay(void* label){
	//displayText* labels = (displayText*)label;
	//QString weight;
	//QString temp;
	//QString dis;
	//double disMeasurement=0;
	//s.disSensor.measureDistance(&disMeasurement);
	//dis = QString::number(disMeasurement);
	double temp = tm->measureHeat();

	QString temp_qt = QString::number(temp);
	//gui->disReadOut->setText(dis);
	gui->tempReadOut->setText(temp_qt);
	//ui->weightReadOut->setText(weight);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	QString dis;
    	ui->setupUi(this);
    	gui = ui;
	tm = new tempMeasurement(IRTEMP1_PIN);
    	int waitdelay = 1000;
	OSTickInitialize();
	RTOSTmrInit();
    	QString errmsg = "Error Starting Timer";
	INT8U err_val;
	INT8 *timer_name[1] = {"Display"};
	displayText labels = {ui->disReadOut,ui->tempReadOut,ui->weightReadOut};
	RTOS_TMR *timer_obj1 = RTOSTmrCreate(0,waitdelay,RTOS_TMR_PERIODIC,
											updateDisplay,&labels,timer_name[0],&err_val);
	QString export1 = QString::number(exportPin(66));
	gui->disReadOut->setText(export1);
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
	s = new Stepper();
        int direction = FORWARD;
        s->setMode(FULLSTEP);
        s->step(&direction);
	usleep(60000);
        s->step(&direction);
	usleep(60000);
        s->step(&direction);
	usleep(60000);
        s->step(&direction);
	usleep(60000);
	s->step(&direction);
	usleep(60000);

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
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);

	s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);

	s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
        s->step(&direction);
        usleep(60000);
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

