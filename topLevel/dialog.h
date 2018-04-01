#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QListWidget>
#include <QtGui/QTreeWidget>

typedef struct Stage{
    double mixtime;
    double heattime;
    int targetTemp;
    double fluidAmnt;
    char* fluidName;
    int fluidID;

}stage_t;
typedef struct Batch{
    stage_t stg1;
    stage_t stg2;
    stage_t stg3;
    stage_t stg4;
    stage_t stg5;

}batch_t;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, QTreeWidget* tw=NULL, int batch = 1, batch_t* b_=NULL);
    ~Dialog();
    QListWidget* listWidget;
    QTreeWidget* procedure;
    void updateTreeView();
    int batch_num;
    batch_t* b;
private slots:
    void on_nextButton_clicked();

    void on_addStageButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
