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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *linearRail;
    QLabel *disLabel;
    QLabel *disReadOut;
    QLabel *tempLabel;
    QLabel *tempReadOut;
    QLabel *weightLabel;
    QLabel *weightReadOut;
    QLabel *lrLabel;
    QPushButton *pump1Btn;
    QPushButton *pump2Btn;
    QPushButton *clnBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(408, 294);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        linearRail = new QSlider(centralwidget);
        linearRail->setObjectName(QString::fromUtf8("linearRail"));
        linearRail->setGeometry(QRect(50, 40, 331, 91));
        linearRail->setOrientation(Qt::Horizontal);
        disLabel = new QLabel(centralwidget);
        disLabel->setObjectName(QString::fromUtf8("disLabel"));
        disLabel->setGeometry(QRect(50, 140, 121, 16));
        disReadOut = new QLabel(centralwidget);
        disReadOut->setObjectName(QString::fromUtf8("disReadOut"));
        disReadOut->setGeometry(QRect(230, 140, 59, 14));
        tempLabel = new QLabel(centralwidget);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setGeometry(QRect(50, 170, 141, 16));
        tempReadOut = new QLabel(centralwidget);
        tempReadOut->setObjectName(QString::fromUtf8("tempReadOut"));
        tempReadOut->setGeometry(QRect(230, 170, 59, 14));
        weightLabel = new QLabel(centralwidget);
        weightLabel->setObjectName(QString::fromUtf8("weightLabel"));
        weightLabel->setGeometry(QRect(50, 200, 131, 16));
        weightReadOut = new QLabel(centralwidget);
        weightReadOut->setObjectName(QString::fromUtf8("weightReadOut"));
        weightReadOut->setGeometry(QRect(230, 200, 59, 14));
        lrLabel = new QLabel(centralwidget);
        lrLabel->setObjectName(QString::fromUtf8("lrLabel"));
        lrLabel->setGeometry(QRect(50, 50, 121, 16));
        pump1Btn = new QPushButton(centralwidget);
        pump1Btn->setObjectName(QString::fromUtf8("pump1Btn"));
        pump1Btn->setGeometry(QRect(29, 20, 111, 22));
        pump2Btn = new QPushButton(centralwidget);
        pump2Btn->setObjectName(QString::fromUtf8("pump2Btn"));
        pump2Btn->setGeometry(QRect(150, 20, 111, 22));
        clnBtn = new QPushButton(centralwidget);
        clnBtn->setObjectName(QString::fromUtf8("clnBtn"));
        clnBtn->setGeometry(QRect(270, 20, 111, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 408, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        disLabel->setText(QApplication::translate("MainWindow", "Distance Read Out", 0, QApplication::UnicodeUTF8));
        disReadOut->setText(QApplication::translate("MainWindow", "0.0 in", 0, QApplication::UnicodeUTF8));
        tempLabel->setText(QApplication::translate("MainWindow", "Temperature Read Out", 0, QApplication::UnicodeUTF8));
        tempReadOut->setText(QApplication::translate("MainWindow", "0 C", 0, QApplication::UnicodeUTF8));
        weightLabel->setText(QApplication::translate("MainWindow", "Weight Read Out", 0, QApplication::UnicodeUTF8));
        weightReadOut->setText(QApplication::translate("MainWindow", "0.00 g", 0, QApplication::UnicodeUTF8));
        lrLabel->setText(QApplication::translate("MainWindow", "Linear Rail Control", 0, QApplication::UnicodeUTF8));
        pump1Btn->setText(QApplication::translate("MainWindow", "Activate Pump 1", 0, QApplication::UnicodeUTF8));
        pump2Btn->setText(QApplication::translate("MainWindow", "Activate Pump 2", 0, QApplication::UnicodeUTF8));
        clnBtn->setText(QApplication::translate("MainWindow", "Activate Cleaning", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
