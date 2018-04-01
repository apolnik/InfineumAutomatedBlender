#ifndef STAGEWIDGET_H
#define STAGEWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QListWidget>

namespace Ui {
class StageWidget;
}

class StageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StageWidget(QWidget *parent = 0,QListWidget* q=NULL, QListWidgetItem* s=NULL);
    ~StageWidget();
    QListWidget* q1;
    QListWidgetItem* s1;
    int stage;
    double mixtime;
    double heattime;
    int targetTemp;
    double fluidAmnt;
    QString fluidName;
private slots:

    void on_deleteButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_mixtimeSpin_valueChanged(double arg1);

    void on_heattimeSpin_valueChanged(double arg1);

    void on_tempSpin_valueChanged(int arg1);

    void on_fluidamntSpin_valueChanged(double arg1);

    void on_fluidnameEdit_textChanged(const QString &arg1);

private:
    Ui::StageWidget *ui;
};

#endif // STAGEWIDGET_H
