#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stagewidget.h"
#include "Stepper.h"
#include "SysParam.h"
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include "gpioTool.h"
#include "tempMeasurement.h"
#include "unistd.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->clear();
    b1 = new batch_t();
    b2 = new batch_t();
    b3 = new batch_t();
    b4 = new batch_t();
    d1 = new Dialog(this,ui->treeWidget,1,b1);
    d2 = new Dialog(this,ui->treeWidget,2,b2);
    d3 = new Dialog(this,ui->treeWidget,3,b3);
    d4 = new Dialog(this,ui->treeWidget,4,b4);
    b = new BatchDialog(this,d1,d2,d3,d4);


    logs = new Logger();

        OSTickInitialize();
    RTOSTmrInit();


    scene_weight1 = new QGraphicsScene(this);
    scene_mix1 = new QGraphicsScene(this);
    scene_hot1 = new QGraphicsScene(this);


    scene_weight2 = new QGraphicsScene(this);
    scene_mix2 = new QGraphicsScene(this);
    scene_hot2 = new QGraphicsScene(this);


    scene_weight3 = new QGraphicsScene(this);
    scene_mix3 = new QGraphicsScene(this);
    scene_hot3 = new QGraphicsScene(this);


    scene_weight4 = new QGraphicsScene(this);
    scene_mix4 = new QGraphicsScene(this);
    scene_hot4 = new QGraphicsScene(this);

    ui->grph_weight1->setScene(scene_weight1);
    ui->grph_mix1->setScene(scene_mix1);
    ui->grph_hot1->setScene(scene_hot1);

    ui->grph_weight2->setScene(scene_weight2);
    ui->grph_mix2->setScene(scene_mix2);
    ui->grph_hot2->setScene(scene_hot2);

    ui->grph_weight3->setScene(scene_weight3);
    ui->grph_mix3->setScene(scene_mix3);
    ui->grph_hot3->setScene(scene_hot3);

    ui->grph_weight4->setScene(scene_weight4);
    ui->grph_mix4->setScene(scene_mix4);
    ui->grph_hot4->setScene(scene_hot4);


    vector_weight1_pnt = new QVector<QPoint>();
    vector_mix1_pnt = new QVector<QPoint>();
    vector_hot1_pnt = new QVector<QPoint>();


    vector_weight2_pnt = new QVector<QPoint>();
    vector_mix2_pnt = new QVector<QPoint>();
    vector_hot2_pnt = new QVector<QPoint>();


    vector_weight3_pnt = new QVector<QPoint>();
    vector_mix3_pnt = new QVector<QPoint>();
    vector_hot3_pnt = new QVector<QPoint>();


    vector_weight4_pnt = new QVector<QPoint>();
    vector_mix4_pnt = new QVector<QPoint>();
    vector_hot4_pnt = new QVector<QPoint>();


    vector_weight1_lines = new QVector<QGraphicsLineItem*>();
    vector_mix1_lines = new QVector<QGraphicsLineItem*>();
    vector_hot1_lines = new QVector<QGraphicsLineItem*>();


    vector_weight2_lines = new QVector<QGraphicsLineItem*>();
    vector_mix2_lines = new QVector<QGraphicsLineItem*>();
    vector_hot2_lines = new QVector<QGraphicsLineItem*>();


    vector_weight3_lines = new QVector<QGraphicsLineItem*>();
    vector_mix3_lines = new QVector<QGraphicsLineItem*>();
    vector_hot3_lines = new QVector<QGraphicsLineItem*>();


    vector_weight4_lines = new QVector<QGraphicsLineItem*>();
    vector_mix4_lines = new QVector<QGraphicsLineItem*>();
    vector_hot4_lines = new QVector<QGraphicsLineItem*>();

    timer = new QTimer(this);
    timer->start(10);
    connect (timer, SIGNAL(timeout()),this,SLOT(updateDisplays()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_config_run_clicked()
{

    b->show();
}

void MainWindow::on_run_preset_clicked()
{
   int num_bat = b->num_batches;//get number of batches to run on
   //Pass num_bat and stage parameters to fluidcntrl



}

void MainWindow::on_stopBtn_clicked()
{

}

void MainWindow::on_dial_hot1_actionTriggered(int action)
{

}

void MainWindow::on_spin_hot1_editingFinished()
{

}

void MainWindow::on_dial_mix1_actionTriggered(int action)
{

}

void MainWindow::on_spin_mix1_editingFinished()
{

}

void MainWindow::on_dial_hot2_actionTriggered(int action)
{

}

void MainWindow::on_spin_hot2_editingFinished()
{

}

void MainWindow::on_dial_mix2_actionTriggered(int action)
{

}

void MainWindow::on_spin_mix2_editingFinished()
{

}

void MainWindow::on_dial_hot3_actionTriggered(int action)
{

}

void MainWindow::on_spin_hot3_editingFinished()
{

}

void MainWindow::on_dial_mix3_actionTriggered(int action)
{

}

void MainWindow::on_spin_mix3_editingFinished()
{

}

void MainWindow::on_dial_hot4_actionTriggered(int action)
{

}

void MainWindow::on_spin_hot4_editingFinished()
{

}

void MainWindow::on_dial_mix4_actionTriggered(int action)
{

}

void MainWindow::on_spin_mix4_editingFinished()
{

}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_actionExport_Data_triggered()
{

}

void MainWindow::on_actionPreset_2_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{

}
void MainWindow::updateDisplays(){
    logs->updateLogs();
    int index =ui->beakers_tabwid->currentIndex();
    if(index==0){
        //Beaker 1
        int index_sub = ui->subtabs1->currentIndex();
        if(index_sub==0){
            //Update Beaker 1 - Weight Graph
            QGraphicsView *weight1 = ui->grph_weight1;
            scene_weight1->clear();
            //abacus and ordinate
            scene_weight1->addLine(40,scene_weight1->height()-40,
                scene_weight1->width()-40,scene_weight1->height()-40);
            scene_weight1->addLine(40,scene_weight1->height()-40,
                40,40);
            //grph_weight1
        }
        if(index_sub==1){
            //Update Beaker 1 - Mixing Torque Graph
            QGraphicsView *mix1 = ui->grph_mix1;
            scene_mix1->clear();
            //abacus and ordinate
            scene_mix1->addLine(40,scene_mix1->height()-40,
                scene_mix1->width()-40,scene_mix1->height()-40);
            scene_mix1->addLine(40,scene_mix1->height()-40,
                40,40);
            //grph_mix1
        }
        if(index_sub==2){
            //Update Beaker 1 - Hot Plate Temp Graph
            QGraphicsView *hot1 = ui->grph_hot1;
            scene_hot1->clear();
            //abacus and ordinate
            scene_hot1->addLine(40,scene_hot1->height()-40,
                scene_hot1->width()-40,scene_hot1->height()-40);
            scene_hot1->addLine(40,scene_hot1->height()-40,
                40,40);
            //grph_hot1
        }
    }
    if(index==1){
        //Beaker 2
        int index_sub = ui->subtabs2->currentIndex();
        if(index_sub==0){
            //Update Beaker 2 - Weight Graph    
            QGraphicsView *weight2 = ui->grph_weight2;
            scene_weight2->clear();
            //abacus and ordinate
            scene_weight2->addLine(40,scene_weight2->height()-40,
                scene_weight2->width()-40,scene_weight2->height()-40);
            scene_weight2->addLine(40,scene_weight2->height()-40,
                40,40);
            //grph_weight2
        }
        if(index_sub==1){
            //Update Beaker 2 - Mixing Torque Graph
            QGraphicsView *mix2 = ui->grph_mix2;
            scene_mix2->clear();
            //abacus and ordinate
            scene_mix2->addLine(40,scene_mix2->height()-40,
                scene_mix2->width()-40,scene_mix2->height()-40);
            scene_mix2->addLine(40,scene_mix2->height()-40,
                40,40);
            //grph_mix2
        }
        if(index_sub==2){
            //Update Beaker 2 - Hot Plate Temp Graph
            QGraphicsView *hot2 = ui->grph_hot2;
            scene_hot2->clear();
            //abacus and ordinate
            scene_hot2->addLine(40,scene_hot2->height()-40,
                scene_hot2->width()-40,scene_hot2->height()-40);
            scene_hot2->addLine(40,scene_hot2->height()-40,
                40,40);
            //grph_hot2
        }
    }
    if(index==2){
        //Beaker 3
        int index_sub = ui->subtabs3->currentIndex();
        if(index_sub==0){
            //Update Beaker 3 - Weight Graph
            QGraphicsView *weight3 = ui->grph_weight3;
            scene_weight3->clear();
            //abacus and ordinate
            scene_weight3->addLine(40,scene_weight3->height()-40,
                scene_weight3->width()-40,scene_weight3->height()-40);
            scene_weight3->addLine(40,scene_weight3->height()-40,
                40,40);
            //grph_weight3
            

        }
        if(index_sub==1){
            //Update Beaker 3 - Mixing Torque Graph
            QGraphicsView *mix3 = ui->grph_mix3;
            scene_mix3->clear();
            //abacus and ordinate
            scene_mix3->addLine(40,scene_mix3->height()-40,
                scene_mix3->width()-40,scene_mix3->height()-40);
            scene_mix3->addLine(40,scene_mix3->height()-40,
                40,40);
            //grph_mix3
            
            

        }
        if(index_sub==2){
            //Update Beaker 3 - Hot Plate Temp Graph
            QGraphicsView *hot3 = ui->grph_hot3;
            scene_hot3->clear();
            //abacus and ordinate
            scene_hot3->addLine(40,scene_hot3->height()-40,
                scene_hot3->width()-40,scene_hot3->height()-40);
            scene_hot3->addLine(40,scene_hot3->height()-40,
                40,40);
            //grph_hot3

        }
    }
    if(index==3){
        //Beaker 4
        int index_sub = ui->subtabs4->currentIndex();
        if(index_sub==0){
            //Update Beaker 4 - Weight Graph

            QGraphicsView *weight4 = ui->grph_weight4;
            scene_weight4->clear();
            //abacus and ordinate
            scene_weight4->addLine(40,scene_weight4->height()-40,
                scene_weight4->width()-40,scene_weight4->height()-40);
            scene_weight4->addLine(40,scene_weight4->height()-40,
                40,40);
            //grph_weight4
        }
        if(index_sub==1){
            //Update Beaker 4 - Mixing Torque Graph
            QGraphicsView *mix4 = ui->grph_mix4;
            scene_mix4->clear();
            //abacus and ordinate
            scene_mix4->addLine(40,scene_mix4->height()-40,
                scene_mix4->width()-40,scene_mix4->height()-40);
            scene_mix4->addLine(40,scene_mix4->height()-40,
                40,40);
            //grph_mix4
        }
        if(index_sub==2){
            //Update Beaker 4 - Hot Plate Temp Graph
            QGraphicsView *hot4 = ui->grph_hot4;
            scene_hot4->clear();
            //abacus and ordinate
            scene_hot4->addLine(40,scene_hot4->height()-40,
                scene_hot4->width()-40,scene_hot4->height()-40);
            scene_hot4->addLine(40,scene_hot4->height()-40,
                40,40);

            //grph_hot4
        }
    }



}
