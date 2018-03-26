/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAbout;
    QAction *actionPreset;
    QAction *actionExport_Data;
    QAction *actionPreset_2;
    QWidget *centralwidget;
    QLabel *stage_lbl;
    QPushButton *run_preset;
    QPushButton *config_run;
    QPushButton *stopBtn;
    QProgressBar *progressBar;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *procd_lbl;
    QTabWidget *beakers_tabwid;
    QWidget *Beaker1_tab;
    QTabWidget *subtabs1;
    QWidget *weight1;
    QGraphicsView *grph_weight1;
    QWidget *mix1;
    QDial *dial_mix1;
    QDoubleSpinBox *spin_mix1;
    QLabel *lbl0_mix1;
    QLabel *lbl1_mix1;
    QGraphicsView *grph_mix1;
    QWidget *hot1;
    QDial *dial_hot1;
    QDoubleSpinBox *spin_hot1;
    QLabel *lbl0_hot1;
    QLabel *lbl1_hot1;
    QGraphicsView *grph_hot1;
    QLabel *beaker1_lbl;
    QWidget *Beaker2_tab;
    QLabel *beaker2_lbl;
    QTabWidget *subtabs2;
    QWidget *weight2;
    QGraphicsView *grph_weight2;
    QWidget *mix2;
    QDial *dial_mix2;
    QDoubleSpinBox *spin_mix2;
    QLabel *lbl0_mix2;
    QLabel *lbl1_mix2;
    QGraphicsView *grph_mix2;
    QWidget *hot2;
    QDial *dial_hot2;
    QDoubleSpinBox *spin_hot2;
    QLabel *lbl0_hot2;
    QLabel *lbl1_hot2;
    QGraphicsView *grph_hot2;
    QWidget *Beaker3_tab;
    QTabWidget *subtabs3;
    QWidget *weight3;
    QGraphicsView *grph_weight3;
    QWidget *mix3;
    QDial *dial_mix3;
    QDoubleSpinBox *spin_mix3;
    QLabel *lbl0_mix3;
    QLabel *lbl1_mix3;
    QGraphicsView *grph_mix3;
    QWidget *hot3;
    QDial *dial_hot3;
    QDoubleSpinBox *spin_hot3;
    QLabel *lbl0_hot3;
    QLabel *lbl1_hot3;
    QGraphicsView *grph_hot3;
    QLabel *beaker3_lbl;
    QWidget *Beaker4_tab;
    QTabWidget *subtabs4;
    QWidget *weight4;
    QGraphicsView *grph_weight4;
    QWidget *mix4;
    QDial *dial_mix4;
    QDoubleSpinBox *spin_mix4;
    QLabel *lbl0_mix4;
    QLabel *lbl1_mix4;
    QGraphicsView *grph_mix4;
    QWidget *hot4;
    QDial *dial_hot4;
    QDoubleSpinBox *spin_hot4;
    QLabel *lbl0_hot4;
    QLabel *lbl1_hot4;
    QGraphicsView *grph_hot4;
    QLabel *beaker4_lbl;
    QLabel *control_lbl;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(943, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Pictures/Infineum-Colour-Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionPreset = new QAction(MainWindow);
        actionPreset->setObjectName(QString::fromUtf8("actionPreset"));
        actionExport_Data = new QAction(MainWindow);
        actionExport_Data->setObjectName(QString::fromUtf8("actionExport_Data"));
        actionPreset_2 = new QAction(MainWindow);
        actionPreset_2->setObjectName(QString::fromUtf8("actionPreset_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stage_lbl = new QLabel(centralwidget);
        stage_lbl->setObjectName(QString::fromUtf8("stage_lbl"));
        stage_lbl->setGeometry(QRect(50, 350, 411, 21));
        run_preset = new QPushButton(centralwidget);
        run_preset->setObjectName(QString::fromUtf8("run_preset"));
        run_preset->setGeometry(QRect(540, 40, 121, 22));
        config_run = new QPushButton(centralwidget);
        config_run->setObjectName(QString::fromUtf8("config_run"));
        config_run->setGeometry(QRect(720, 40, 131, 22));
        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(540, 80, 311, 21));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 380, 421, 23));
        progressBar->setValue(0);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(480, 0, 16, 421));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-40, 330, 531, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(490, 110, 451, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        procd_lbl = new QLabel(centralwidget);
        procd_lbl->setObjectName(QString::fromUtf8("procd_lbl"));
        procd_lbl->setGeometry(QRect(500, 130, 141, 17));
        beakers_tabwid = new QTabWidget(centralwidget);
        beakers_tabwid->setObjectName(QString::fromUtf8("beakers_tabwid"));
        beakers_tabwid->setGeometry(QRect(0, 0, 481, 341));
        beakers_tabwid->setCursor(QCursor(Qt::ArrowCursor));
        Beaker1_tab = new QWidget();
        Beaker1_tab->setObjectName(QString::fromUtf8("Beaker1_tab"));
        subtabs1 = new QTabWidget(Beaker1_tab);
        subtabs1->setObjectName(QString::fromUtf8("subtabs1"));
        subtabs1->setGeometry(QRect(10, 30, 461, 271));
        subtabs1->setCursor(QCursor(Qt::ArrowCursor));
        weight1 = new QWidget();
        weight1->setObjectName(QString::fromUtf8("weight1"));
        grph_weight1 = new QGraphicsView(weight1);
        grph_weight1->setObjectName(QString::fromUtf8("grph_weight1"));
        grph_weight1->setGeometry(QRect(40, 20, 301, 211));
        grph_weight1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs1->addTab(weight1, QString());
        mix1 = new QWidget();
        mix1->setObjectName(QString::fromUtf8("mix1"));
        dial_mix1 = new QDial(mix1);
        dial_mix1->setObjectName(QString::fromUtf8("dial_mix1"));
        dial_mix1->setGeometry(QRect(380, 80, 50, 64));
        spin_mix1 = new QDoubleSpinBox(mix1);
        spin_mix1->setObjectName(QString::fromUtf8("spin_mix1"));
        spin_mix1->setGeometry(QRect(370, 180, 69, 27));
        lbl0_mix1 = new QLabel(mix1);
        lbl0_mix1->setObjectName(QString::fromUtf8("lbl0_mix1"));
        lbl0_mix1->setGeometry(QRect(350, 70, 101, 20));
        lbl1_mix1 = new QLabel(mix1);
        lbl1_mix1->setObjectName(QString::fromUtf8("lbl1_mix1"));
        lbl1_mix1->setGeometry(QRect(350, 160, 111, 21));
        grph_mix1 = new QGraphicsView(mix1);
        grph_mix1->setObjectName(QString::fromUtf8("grph_mix1"));
        grph_mix1->setGeometry(QRect(40, 20, 301, 211));
        grph_mix1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs1->addTab(mix1, QString());
        hot1 = new QWidget();
        hot1->setObjectName(QString::fromUtf8("hot1"));
        dial_hot1 = new QDial(hot1);
        dial_hot1->setObjectName(QString::fromUtf8("dial_hot1"));
        dial_hot1->setGeometry(QRect(380, 80, 50, 64));
        spin_hot1 = new QDoubleSpinBox(hot1);
        spin_hot1->setObjectName(QString::fromUtf8("spin_hot1"));
        spin_hot1->setGeometry(QRect(370, 180, 69, 27));
        lbl0_hot1 = new QLabel(hot1);
        lbl0_hot1->setObjectName(QString::fromUtf8("lbl0_hot1"));
        lbl0_hot1->setGeometry(QRect(360, 70, 91, 17));
        lbl1_hot1 = new QLabel(hot1);
        lbl1_hot1->setObjectName(QString::fromUtf8("lbl1_hot1"));
        lbl1_hot1->setGeometry(QRect(350, 160, 111, 21));
        grph_hot1 = new QGraphicsView(hot1);
        grph_hot1->setObjectName(QString::fromUtf8("grph_hot1"));
        grph_hot1->setGeometry(QRect(40, 20, 301, 211));
        grph_hot1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs1->addTab(hot1, QString());
        beaker1_lbl = new QLabel(Beaker1_tab);
        beaker1_lbl->setObjectName(QString::fromUtf8("beaker1_lbl"));
        beaker1_lbl->setGeometry(QRect(170, 0, 121, 31));
        QFont font;
        font.setPointSize(20);
        font.setItalic(true);
        beaker1_lbl->setFont(font);
        beakers_tabwid->addTab(Beaker1_tab, QString());
        Beaker2_tab = new QWidget();
        Beaker2_tab->setObjectName(QString::fromUtf8("Beaker2_tab"));
        beaker2_lbl = new QLabel(Beaker2_tab);
        beaker2_lbl->setObjectName(QString::fromUtf8("beaker2_lbl"));
        beaker2_lbl->setGeometry(QRect(170, 0, 121, 31));
        beaker2_lbl->setFont(font);
        subtabs2 = new QTabWidget(Beaker2_tab);
        subtabs2->setObjectName(QString::fromUtf8("subtabs2"));
        subtabs2->setGeometry(QRect(10, 30, 461, 271));
        subtabs2->setCursor(QCursor(Qt::ArrowCursor));
        weight2 = new QWidget();
        weight2->setObjectName(QString::fromUtf8("weight2"));
        grph_weight2 = new QGraphicsView(weight2);
        grph_weight2->setObjectName(QString::fromUtf8("grph_weight2"));
        grph_weight2->setGeometry(QRect(40, 20, 301, 211));
        grph_weight2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs2->addTab(weight2, QString());
        mix2 = new QWidget();
        mix2->setObjectName(QString::fromUtf8("mix2"));
        dial_mix2 = new QDial(mix2);
        dial_mix2->setObjectName(QString::fromUtf8("dial_mix2"));
        dial_mix2->setGeometry(QRect(380, 80, 50, 64));
        spin_mix2 = new QDoubleSpinBox(mix2);
        spin_mix2->setObjectName(QString::fromUtf8("spin_mix2"));
        spin_mix2->setGeometry(QRect(370, 180, 69, 27));
        lbl0_mix2 = new QLabel(mix2);
        lbl0_mix2->setObjectName(QString::fromUtf8("lbl0_mix2"));
        lbl0_mix2->setGeometry(QRect(350, 70, 101, 20));
        lbl1_mix2 = new QLabel(mix2);
        lbl1_mix2->setObjectName(QString::fromUtf8("lbl1_mix2"));
        lbl1_mix2->setGeometry(QRect(350, 160, 111, 21));
        grph_mix2 = new QGraphicsView(mix2);
        grph_mix2->setObjectName(QString::fromUtf8("grph_mix2"));
        grph_mix2->setGeometry(QRect(40, 20, 301, 211));
        grph_mix2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs2->addTab(mix2, QString());
        hot2 = new QWidget();
        hot2->setObjectName(QString::fromUtf8("hot2"));
        dial_hot2 = new QDial(hot2);
        dial_hot2->setObjectName(QString::fromUtf8("dial_hot2"));
        dial_hot2->setGeometry(QRect(380, 80, 50, 64));
        spin_hot2 = new QDoubleSpinBox(hot2);
        spin_hot2->setObjectName(QString::fromUtf8("spin_hot2"));
        spin_hot2->setGeometry(QRect(370, 180, 69, 27));
        lbl0_hot2 = new QLabel(hot2);
        lbl0_hot2->setObjectName(QString::fromUtf8("lbl0_hot2"));
        lbl0_hot2->setGeometry(QRect(360, 70, 91, 17));
        lbl1_hot2 = new QLabel(hot2);
        lbl1_hot2->setObjectName(QString::fromUtf8("lbl1_hot2"));
        lbl1_hot2->setGeometry(QRect(350, 160, 111, 21));
        grph_hot2 = new QGraphicsView(hot2);
        grph_hot2->setObjectName(QString::fromUtf8("grph_hot2"));
        grph_hot2->setGeometry(QRect(40, 20, 301, 211));
        grph_hot2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs2->addTab(hot2, QString());
        beakers_tabwid->addTab(Beaker2_tab, QString());
        Beaker3_tab = new QWidget();
        Beaker3_tab->setObjectName(QString::fromUtf8("Beaker3_tab"));
        subtabs3 = new QTabWidget(Beaker3_tab);
        subtabs3->setObjectName(QString::fromUtf8("subtabs3"));
        subtabs3->setGeometry(QRect(10, 30, 461, 271));
        subtabs3->setCursor(QCursor(Qt::ArrowCursor));
        weight3 = new QWidget();
        weight3->setObjectName(QString::fromUtf8("weight3"));
        grph_weight3 = new QGraphicsView(weight3);
        grph_weight3->setObjectName(QString::fromUtf8("grph_weight3"));
        grph_weight3->setGeometry(QRect(40, 20, 301, 211));
        grph_weight3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs3->addTab(weight3, QString());
        mix3 = new QWidget();
        mix3->setObjectName(QString::fromUtf8("mix3"));
        dial_mix3 = new QDial(mix3);
        dial_mix3->setObjectName(QString::fromUtf8("dial_mix3"));
        dial_mix3->setGeometry(QRect(380, 80, 50, 64));
        spin_mix3 = new QDoubleSpinBox(mix3);
        spin_mix3->setObjectName(QString::fromUtf8("spin_mix3"));
        spin_mix3->setGeometry(QRect(370, 180, 69, 27));
        lbl0_mix3 = new QLabel(mix3);
        lbl0_mix3->setObjectName(QString::fromUtf8("lbl0_mix3"));
        lbl0_mix3->setGeometry(QRect(350, 70, 101, 20));
        lbl1_mix3 = new QLabel(mix3);
        lbl1_mix3->setObjectName(QString::fromUtf8("lbl1_mix3"));
        lbl1_mix3->setGeometry(QRect(350, 160, 111, 21));
        grph_mix3 = new QGraphicsView(mix3);
        grph_mix3->setObjectName(QString::fromUtf8("grph_mix3"));
        grph_mix3->setGeometry(QRect(40, 20, 301, 211));
        grph_mix3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs3->addTab(mix3, QString());
        hot3 = new QWidget();
        hot3->setObjectName(QString::fromUtf8("hot3"));
        dial_hot3 = new QDial(hot3);
        dial_hot3->setObjectName(QString::fromUtf8("dial_hot3"));
        dial_hot3->setGeometry(QRect(380, 80, 50, 64));
        spin_hot3 = new QDoubleSpinBox(hot3);
        spin_hot3->setObjectName(QString::fromUtf8("spin_hot3"));
        spin_hot3->setGeometry(QRect(370, 180, 69, 27));
        lbl0_hot3 = new QLabel(hot3);
        lbl0_hot3->setObjectName(QString::fromUtf8("lbl0_hot3"));
        lbl0_hot3->setGeometry(QRect(360, 70, 91, 17));
        lbl1_hot3 = new QLabel(hot3);
        lbl1_hot3->setObjectName(QString::fromUtf8("lbl1_hot3"));
        lbl1_hot3->setGeometry(QRect(350, 160, 111, 21));
        grph_hot3 = new QGraphicsView(hot3);
        grph_hot3->setObjectName(QString::fromUtf8("grph_hot3"));
        grph_hot3->setGeometry(QRect(40, 20, 301, 211));
        grph_hot3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs3->addTab(hot3, QString());
        beaker3_lbl = new QLabel(Beaker3_tab);
        beaker3_lbl->setObjectName(QString::fromUtf8("beaker3_lbl"));
        beaker3_lbl->setGeometry(QRect(170, 0, 121, 31));
        beaker3_lbl->setFont(font);
        beakers_tabwid->addTab(Beaker3_tab, QString());
        Beaker4_tab = new QWidget();
        Beaker4_tab->setObjectName(QString::fromUtf8("Beaker4_tab"));
        subtabs4 = new QTabWidget(Beaker4_tab);
        subtabs4->setObjectName(QString::fromUtf8("subtabs4"));
        subtabs4->setGeometry(QRect(10, 30, 461, 271));
        subtabs4->setCursor(QCursor(Qt::ArrowCursor));
        weight4 = new QWidget();
        weight4->setObjectName(QString::fromUtf8("weight4"));
        grph_weight4 = new QGraphicsView(weight4);
        grph_weight4->setObjectName(QString::fromUtf8("grph_weight4"));
        grph_weight4->setGeometry(QRect(40, 20, 301, 211));
        grph_weight4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs4->addTab(weight4, QString());
        mix4 = new QWidget();
        mix4->setObjectName(QString::fromUtf8("mix4"));
        dial_mix4 = new QDial(mix4);
        dial_mix4->setObjectName(QString::fromUtf8("dial_mix4"));
        dial_mix4->setGeometry(QRect(380, 80, 50, 64));
        spin_mix4 = new QDoubleSpinBox(mix4);
        spin_mix4->setObjectName(QString::fromUtf8("spin_mix4"));
        spin_mix4->setGeometry(QRect(370, 180, 69, 27));
        lbl0_mix4 = new QLabel(mix4);
        lbl0_mix4->setObjectName(QString::fromUtf8("lbl0_mix4"));
        lbl0_mix4->setGeometry(QRect(350, 70, 101, 20));
        lbl1_mix4 = new QLabel(mix4);
        lbl1_mix4->setObjectName(QString::fromUtf8("lbl1_mix4"));
        lbl1_mix4->setGeometry(QRect(350, 160, 111, 21));
        grph_mix4 = new QGraphicsView(mix4);
        grph_mix4->setObjectName(QString::fromUtf8("grph_mix4"));
        grph_mix4->setGeometry(QRect(40, 20, 301, 211));
        grph_mix4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs4->addTab(mix4, QString());
        hot4 = new QWidget();
        hot4->setObjectName(QString::fromUtf8("hot4"));
        dial_hot4 = new QDial(hot4);
        dial_hot4->setObjectName(QString::fromUtf8("dial_hot4"));
        dial_hot4->setGeometry(QRect(380, 80, 50, 64));
        spin_hot4 = new QDoubleSpinBox(hot4);
        spin_hot4->setObjectName(QString::fromUtf8("spin_hot4"));
        spin_hot4->setGeometry(QRect(370, 180, 69, 27));
        lbl0_hot4 = new QLabel(hot4);
        lbl0_hot4->setObjectName(QString::fromUtf8("lbl0_hot4"));
        lbl0_hot4->setGeometry(QRect(360, 70, 91, 17));
        lbl1_hot4 = new QLabel(hot4);
        lbl1_hot4->setObjectName(QString::fromUtf8("lbl1_hot4"));
        lbl1_hot4->setGeometry(QRect(350, 160, 111, 21));
        grph_hot4 = new QGraphicsView(hot4);
        grph_hot4->setObjectName(QString::fromUtf8("grph_hot4"));
        grph_hot4->setGeometry(QRect(40, 20, 301, 211));
        grph_hot4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        subtabs4->addTab(hot4, QString());
        beaker4_lbl = new QLabel(Beaker4_tab);
        beaker4_lbl->setObjectName(QString::fromUtf8("beaker4_lbl"));
        beaker4_lbl->setGeometry(QRect(170, 0, 121, 31));
        beaker4_lbl->setFont(font);
        beakers_tabwid->addTab(Beaker4_tab, QString());
        control_lbl = new QLabel(centralwidget);
        control_lbl->setObjectName(QString::fromUtf8("control_lbl"));
        control_lbl->setGeometry(QRect(540, 10, 67, 17));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(500, 150, 431, 271));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 943, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport_Data);
        menuNew->addAction(actionPreset_2);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        beakers_tabwid->setCurrentIndex(3);
        subtabs1->setCurrentIndex(0);
        subtabs2->setCurrentIndex(0);
        subtabs3->setCurrentIndex(0);
        subtabs4->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Automated Blend Machine", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionPreset->setText(QApplication::translate("MainWindow", "Preset", 0, QApplication::UnicodeUTF8));
        actionExport_Data->setText(QApplication::translate("MainWindow", "Export Data", 0, QApplication::UnicodeUTF8));
        actionPreset_2->setText(QApplication::translate("MainWindow", "Preset", 0, QApplication::UnicodeUTF8));
        stage_lbl->setText(QApplication::translate("MainWindow", "Stage:", 0, QApplication::UnicodeUTF8));
        run_preset->setText(QApplication::translate("MainWindow", "Run Preset", 0, QApplication::UnicodeUTF8));
        config_run->setText(QApplication::translate("MainWindow", "Configure Run", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        procd_lbl->setText(QApplication::translate("MainWindow", "Procedure Steps", 0, QApplication::UnicodeUTF8));
        subtabs1->setTabText(subtabs1->indexOf(weight1), QApplication::translate("MainWindow", "Weight", 0, QApplication::UnicodeUTF8));
        lbl0_mix1->setText(QApplication::translate("MainWindow", "Adjust Torque", 0, QApplication::UnicodeUTF8));
        lbl1_mix1->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs1->setTabText(subtabs1->indexOf(mix1), QApplication::translate("MainWindow", "Mixing Torque", 0, QApplication::UnicodeUTF8));
        lbl0_hot1->setText(QApplication::translate("MainWindow", "Adjust Heat", 0, QApplication::UnicodeUTF8));
        lbl1_hot1->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs1->setTabText(subtabs1->indexOf(hot1), QApplication::translate("MainWindow", "Hot Plate Temperature", 0, QApplication::UnicodeUTF8));
        beaker1_lbl->setText(QApplication::translate("MainWindow", "Beaker 1", 0, QApplication::UnicodeUTF8));
        beakers_tabwid->setTabText(beakers_tabwid->indexOf(Beaker1_tab), QApplication::translate("MainWindow", "Beaker 1", 0, QApplication::UnicodeUTF8));
        beaker2_lbl->setText(QApplication::translate("MainWindow", "Beaker 2", 0, QApplication::UnicodeUTF8));
        subtabs2->setTabText(subtabs2->indexOf(weight2), QApplication::translate("MainWindow", "Weight", 0, QApplication::UnicodeUTF8));
        lbl0_mix2->setText(QApplication::translate("MainWindow", "Adjust Torque", 0, QApplication::UnicodeUTF8));
        lbl1_mix2->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs2->setTabText(subtabs2->indexOf(mix2), QApplication::translate("MainWindow", "Mixing Torque", 0, QApplication::UnicodeUTF8));
        lbl0_hot2->setText(QApplication::translate("MainWindow", "Adjust Heat", 0, QApplication::UnicodeUTF8));
        lbl1_hot2->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs2->setTabText(subtabs2->indexOf(hot2), QApplication::translate("MainWindow", "Hot Plate Temperature", 0, QApplication::UnicodeUTF8));
        beakers_tabwid->setTabText(beakers_tabwid->indexOf(Beaker2_tab), QApplication::translate("MainWindow", "Beaker 2", 0, QApplication::UnicodeUTF8));
        subtabs3->setTabText(subtabs3->indexOf(weight3), QApplication::translate("MainWindow", "Weight", 0, QApplication::UnicodeUTF8));
        lbl0_mix3->setText(QApplication::translate("MainWindow", "Adjust Torque", 0, QApplication::UnicodeUTF8));
        lbl1_mix3->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs3->setTabText(subtabs3->indexOf(mix3), QApplication::translate("MainWindow", "Mixing Torque", 0, QApplication::UnicodeUTF8));
        lbl0_hot3->setText(QApplication::translate("MainWindow", "Adjust Heat", 0, QApplication::UnicodeUTF8));
        lbl1_hot3->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs3->setTabText(subtabs3->indexOf(hot3), QApplication::translate("MainWindow", "Hot Plate Temperature", 0, QApplication::UnicodeUTF8));
        beaker3_lbl->setText(QApplication::translate("MainWindow", "Beaker 3", 0, QApplication::UnicodeUTF8));
        beakers_tabwid->setTabText(beakers_tabwid->indexOf(Beaker3_tab), QApplication::translate("MainWindow", "Beaker 3", 0, QApplication::UnicodeUTF8));
        subtabs4->setTabText(subtabs4->indexOf(weight4), QApplication::translate("MainWindow", "Weight", 0, QApplication::UnicodeUTF8));
        lbl0_mix4->setText(QApplication::translate("MainWindow", "Adjust Torque", 0, QApplication::UnicodeUTF8));
        lbl1_mix4->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs4->setTabText(subtabs4->indexOf(mix4), QApplication::translate("MainWindow", "Mixing Torque", 0, QApplication::UnicodeUTF8));
        lbl0_hot4->setText(QApplication::translate("MainWindow", "Adjust Heat", 0, QApplication::UnicodeUTF8));
        lbl1_hot4->setText(QApplication::translate("MainWindow", "Adjust Duration", 0, QApplication::UnicodeUTF8));
        subtabs4->setTabText(subtabs4->indexOf(hot4), QApplication::translate("MainWindow", "Hot Plate Temperature", 0, QApplication::UnicodeUTF8));
        beaker4_lbl->setText(QApplication::translate("MainWindow", "Beaker 4", 0, QApplication::UnicodeUTF8));
        beakers_tabwid->setTabText(beakers_tabwid->indexOf(Beaker4_tab), QApplication::translate("MainWindow", "Beaker 4", 0, QApplication::UnicodeUTF8));
        control_lbl->setText(QApplication::translate("MainWindow", "Control", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
