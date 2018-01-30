#include "systeminterfaceqt.h"
#include "ui_systeminterfaceqt.h"
#include "Stepper.h"
#include "SysParam.h"
Stepper s;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
}

MainWindow::~MainWindow()
{
    delete ui;
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
