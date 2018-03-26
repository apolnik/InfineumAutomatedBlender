#include "batchdialog.h"
#include "ui_batchdialog.h"

BatchDialog::BatchDialog(QWidget *parent,Dialog* d1_,Dialog* d2_,Dialog* d3_,Dialog* d4_) :
    QDialog(parent),
    ui(new Ui::BatchDialog)
{
    d1=d1_;
    d2=d2_;
    d3=d3_;
    d4=d4_;
    ui->setupUi(this);
    num_batches=0;
}

BatchDialog::~BatchDialog()
{
    delete ui;
}

void BatchDialog::on_closeButton_clicked()
{
    this->close();
}

void BatchDialog::on_setStageButton_clicked()
{

    if(num_batches==1){
        d1->show();
    }
    if(num_batches==2){
        d2->show();
        d1->show();
    }
    if(num_batches==3){
        d3->show();
        d2->show();
        d1->show();
    }
    if(num_batches==4){
        d4->show();
        d3->show();
        d2->show();
        d1->show();
    }
    this->close();
}

void BatchDialog::on_batchSpin_valueChanged(int arg1)
{
    num_batches=arg1;
}
