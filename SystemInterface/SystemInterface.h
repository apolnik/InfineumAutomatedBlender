#ifndef SystemInterface_H
#define SystemInterface_H
#include "mixCntrl.h"
#include "FluidTranCntrl.h"
#include <QMainWindow>
#include "QListWidgetItem"
#include  "QVBoxLayout"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;


};
class SystemInterface{
	public:
	mixCntrl* mixer;
	FluidTranCntrl* fluidtrans;
	
	SystemInterface();
	

	int addFluid();
	int mixBeaker();
	int DisplayLogs();
	int RaiseAlarms();

};
#endif /* SystemInterface_H */
