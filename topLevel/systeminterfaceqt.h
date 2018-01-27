#ifndef SYSTEMINTERFACEQT_H
#define SYSTEMINTERFACEQT_H

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
private:
    Ui::MainWindow *ui;
};


#endif // SYSTEMINTERFACEQT_H
