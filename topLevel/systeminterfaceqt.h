#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPoint>
#include <QGraphicsLineItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer* timer;

    QGraphicsScene *scene_weight1;
    QGraphicsScene *scene_mix1;
    QGraphicsScene *scene_hot1;


    QGraphicsScene *scene_weight2;
    QGraphicsScene *scene_mix2;
    QGraphicsScene *scene_hot2;


    QGraphicsScene *scene_weight3;
    QGraphicsScene *scene_mix3;
    QGraphicsScene *scene_hot3;


    QGraphicsScene *scene_weight4;
    QGraphicsScene *scene_mix4;
    QGraphicsScene *scene_hot4;


    QVector *vector_weight1_pnt;
    QVector *vector_mix1_pnt;
    QVector *vector_hot1_pnt;


    QVector *vector_weight2_pnt;
    QVector *vector_mix2_pnt;
    QVector *vector_hot2_pnt;


    QVector *vector_weight3_pnt;
    QVector *vector_mix3_pnt;
    QVector *vector_hot3_pnt;


    QVector *vector_weight4_pnt;
    QVector *vector_mix4_pnt;
    QVector *vector_hot4_pnt;


    QVector *vector_weight1_lines;
    QVector *vector_mix1_lines;
    QVector *vector_hot1_lines;


    QVector *vector_weight2_lines;
    QVector *vector_mix2_lines;
    QVector *vector_hot2_lines;


    QVector *vector_weight3_lines;
    QVector *vector_mix3_lines;
    QVector *vector_hot3_lines;


    QVector *vector_weight4_lines;
    QVector *vector_mix4_lines;
    QVector *vector_hot4_lines;

private slots:
    void on_pump1Btn_clicked();

    void on_pump2Btn_clicked();

    void on_clnBtn_clicked();

    void on_linearRail_rangeChanged(int min, int max);

    void on_config_run_clicked();

    void on_run_preset_clicked();

    void on_stopBtn_clicked();

    void on_dial_hot1_actionTriggered(int action);

    void on_spin_hot1_editingFinished();

    void on_dial_mix1_actionTriggered(int action);

    void on_spin_mix1_editingFinished();

    void on_dial_hot2_actionTriggered(int action);

    void on_spin_hot2_editingFinished();

    void on_dial_mix2_actionTriggered(int action);

    void on_spin_mix2_editingFinished();

    void on_dial_hot3_actionTriggered(int action);

    void on_spin_hot3_editingFinished();

    void on_dial_mix3_actionTriggered(int action);

    void on_spin_mix3_editingFinished();

    void on_dial_hot4_actionTriggered(int action);

    void on_spin_hot4_editingFinished();

    void on_dial_mix4_actionTriggered(int action);

    void on_spin_mix4_editingFinished();

    void updateDisplays();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
