#ifndef BATCHDIALOG_H
#define BATCHDIALOG_H

#include <QtGui/QDialog>
#include "dialog.h"
namespace Ui {
class BatchDialog;
}

class BatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BatchDialog(QWidget *parent = 0, Dialog* d1=NULL,Dialog* d2=NULL,Dialog* d3=NULL,Dialog* d4=NULL);
    ~BatchDialog();
    int num_batches;
    Dialog* d1;
    Dialog* d2;
    Dialog* d3;
    Dialog* d4;
private slots:
    void on_closeButton_clicked();

    void on_setStageButton_clicked();

    void on_batchSpin_valueChanged(int arg1);

private:
    Ui::BatchDialog *ui;
};

#endif // BATCHDIALOG_H
