#include "dialog.h"
#include "ui_dialog.h"
#include "stagewidget.h"
#include "mainwindow.h"
#include "QString"
#include "QTextStream"
Dialog::Dialog(QWidget *parent,QTreeWidget* tw, int batch, batch_t* b_) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    procedure = tw;
    ui->setupUi(this);
    listWidget = ui->listWidget;
    batch_num = batch;
    b=b_;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_nextButton_clicked()
{
    updateTreeView();
    this->close();
}

void Dialog::updateTreeView(){

    QListWidget *lw = ui->listWidget;
    int count = lw->count();
    QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(procedure);
    procedure->addTopLevelItem((topLevelItem));
    QString batch;
    QTextStream(&batch) << "Batch " << batch_num << ": ";
    topLevelItem->setText(0,batch);
    for(int i =0; i<count; i++){
        QTreeWidgetItem *headerItem = new QTreeWidgetItem(topLevelItem);
        QString header;
        QTextStream(&header) << "Stage " << i+1 << ":";
        headerItem->setText(0,header);
        //topLevelItem->setText(0,header);
        StageWidget* sw = (StageWidget*)lw->itemWidget(lw->item(i));
        QTreeWidgetItem *fluidItem = new QTreeWidgetItem(headerItem);
        QString fluid;
        QTextStream(&fluid) << "Fluid: " << sw->fluidName << " - Volume: " << sw->fluidAmnt << " mL";
        fluidItem->setText(0,fluid);
        QTreeWidgetItem *heatItem = new QTreeWidgetItem(headerItem);
        QString heat;
        QTextStream(&heat) << "Temperature: " << sw->targetTemp << " C - Duration: " << sw->heattime << " s";
        heatItem->setText(0,heat);
        QTreeWidgetItem *mixItem = new QTreeWidgetItem(headerItem);
        QString mix;
        QTextStream(&mix) << "Mixing Duration: " << sw->mixtime << " s";
        mixItem->setText(0,mix);
        if(i==0){
            b->stg1.heattime = sw->heattime;
            b->stg1.targetTemp = sw->targetTemp;
            b->stg1.mixtime = sw->mixtime;
            b->stg1.fluidAmnt= sw->fluidAmnt;
            QByteArray ba = sw->fluidName.toLatin1();
            b->stg1.fluidName = ba.data();
            b->stg1.fluidID = 0;
        }
        if(i==1){
            b->stg2.heattime = sw->heattime;
            b->stg2.targetTemp = sw->targetTemp;
            b->stg2.mixtime = sw->mixtime;
            b->stg2.fluidAmnt= sw->fluidAmnt;
            QByteArray ba = sw->fluidName.toLatin1();
            b->stg2.fluidName = ba.data();
            b->stg2.fluidID = 1;
        }
        if(i==2){
            b->stg3.heattime = sw->heattime;
            b->stg3.targetTemp = sw->targetTemp;
            b->stg3.mixtime = sw->mixtime;
            b->stg3.fluidAmnt= sw->fluidAmnt;
            QByteArray ba = sw->fluidName.toLatin1();
            b->stg3.fluidName = ba.data();
            b->stg3.fluidID = 2;
        }
        if(i==3){
            b->stg4.heattime = sw->heattime;
            b->stg4.targetTemp = sw->targetTemp;
            b->stg4.mixtime = sw->mixtime;
            b->stg4.fluidAmnt= sw->fluidAmnt;
            QByteArray ba = sw->fluidName.toLatin1();
            b->stg4.fluidName = ba.data();
            b->stg4.fluidID = 3;
        }
        if(i==4){
            b->stg5.heattime = sw->heattime;
            b->stg5.targetTemp = sw->targetTemp;
            b->stg5.mixtime = sw->mixtime;
            b->stg5.fluidAmnt= sw->fluidAmnt;
            QByteArray ba = sw->fluidName.toLatin1();
            b->stg5.fluidName = ba.data();
            b->stg5.fluidID = 4;
        }

    }
}
void Dialog::on_addStageButton_clicked()
{
    if(ui->listWidget->count()<5){
        QListWidgetItem *newStage = new QListWidgetItem(ui->listWidget);
        StageWidget * s = new StageWidget(this,ui->listWidget,newStage);
        newStage->setSizeHint (QSize(100,200));
        ui->listWidget->addItem(newStage);


        ui->listWidget->setItemWidget(newStage,s);

    }
}
