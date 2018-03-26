#include "stagewidget.h"
#include "ui_stagewidget.h"

StageWidget::StageWidget(QWidget *parent, QListWidget* q, QListWidgetItem* s) :
    QWidget(parent),
    ui(new Ui::StageWidget)
{
    q1=q;
    s1=s;
    ui->setupUi(this);

    ui->spinBox->setValue(q1->count());
}

StageWidget::~StageWidget()
{
    delete ui;
}


void StageWidget::on_deleteButton_clicked()
{

    delete s1;

}

void StageWidget::on_spinBox_valueChanged(int arg1)
{
    stage = arg1;

}

void StageWidget::on_mixtimeSpin_valueChanged(double arg1)
{
    mixtime = arg1;

}

void StageWidget::on_heattimeSpin_valueChanged(double arg1)
{
    heattime = arg1;
}

void StageWidget::on_tempSpin_valueChanged(int arg1)
{
    targetTemp = arg1;
}

void StageWidget::on_fluidamntSpin_valueChanged(double arg1)
{
    fluidAmnt = arg1;
}

void StageWidget::on_fluidnameEdit_textChanged(const QString &arg1)
{
    fluidName = arg1;
}
