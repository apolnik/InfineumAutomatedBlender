#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
