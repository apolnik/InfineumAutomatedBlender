/********************************************************************************
** Form generated from reading UI file 'stagewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGEWIDGET_H
#define UI_STAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StageWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *deleteButton;
    QLabel *label;
    QDoubleSpinBox *heattimeSpin;
    QDoubleSpinBox *fluidamntSpin;
    QLabel *stageLabel;
    QDoubleSpinBox *mixtimeSpin;
    QLabel *heattimeLabel;
    QLabel *fluidamntLabel;
    QLineEdit *fluidnameEdit;
    QSpinBox *spinBox;
    QLabel *fluidnameLabel;
    QLabel *tempLabel;
    QSpinBox *tempSpin;

    void setupUi(QWidget *StageWidget)
    {
        if (StageWidget->objectName().isEmpty())
            StageWidget->setObjectName(QString::fromUtf8("StageWidget"));
        StageWidget->resize(393, 194);
        verticalLayoutWidget = new QWidget(StageWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 391, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(300, 0, 81, 27));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 80, 141, 17));
        heattimeSpin = new QDoubleSpinBox(groupBox);
        heattimeSpin->setObjectName(QString::fromUtf8("heattimeSpin"));
        heattimeSpin->setGeometry(QRect(210, 150, 69, 27));
        fluidamntSpin = new QDoubleSpinBox(groupBox);
        fluidamntSpin->setObjectName(QString::fromUtf8("fluidamntSpin"));
        fluidamntSpin->setGeometry(QRect(10, 100, 81, 27));
        fluidamntSpin->setDecimals(4);
        fluidamntSpin->setMaximum(999.99);
        stageLabel = new QLabel(groupBox);
        stageLabel->setObjectName(QString::fromUtf8("stageLabel"));
        stageLabel->setGeometry(QRect(210, 30, 67, 17));
        mixtimeSpin = new QDoubleSpinBox(groupBox);
        mixtimeSpin->setObjectName(QString::fromUtf8("mixtimeSpin"));
        mixtimeSpin->setGeometry(QRect(210, 100, 69, 27));
        heattimeLabel = new QLabel(groupBox);
        heattimeLabel->setObjectName(QString::fromUtf8("heattimeLabel"));
        heattimeLabel->setGeometry(QRect(210, 130, 171, 17));
        fluidamntLabel = new QLabel(groupBox);
        fluidamntLabel->setObjectName(QString::fromUtf8("fluidamntLabel"));
        fluidamntLabel->setGeometry(QRect(10, 80, 151, 17));
        fluidnameEdit = new QLineEdit(groupBox);
        fluidnameEdit->setObjectName(QString::fromUtf8("fluidnameEdit"));
        fluidnameEdit->setGeometry(QRect(10, 50, 171, 27));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(210, 50, 48, 27));
        spinBox->setMinimum(1);
        spinBox->setMaximum(5);
        fluidnameLabel = new QLabel(groupBox);
        fluidnameLabel->setObjectName(QString::fromUtf8("fluidnameLabel"));
        fluidnameLabel->setGeometry(QRect(10, 30, 131, 17));
        tempLabel = new QLabel(groupBox);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setGeometry(QRect(10, 130, 171, 17));
        tempSpin = new QSpinBox(groupBox);
        tempSpin->setObjectName(QString::fromUtf8("tempSpin"));
        tempSpin->setGeometry(QRect(10, 150, 71, 27));
        tempSpin->setMaximum(300);
        deleteButton->raise();
        fluidamntSpin->raise();
        heattimeSpin->raise();
        label->raise();
        stageLabel->raise();
        mixtimeSpin->raise();
        heattimeLabel->raise();
        fluidamntLabel->raise();
        fluidnameEdit->raise();
        spinBox->raise();
        fluidnameLabel->raise();
        tempLabel->raise();
        tempSpin->raise();
        deleteButton->raise();
        label->raise();
        heattimeSpin->raise();
        fluidamntSpin->raise();
        stageLabel->raise();
        mixtimeSpin->raise();
        heattimeLabel->raise();
        fluidamntLabel->raise();
        fluidnameEdit->raise();
        spinBox->raise();
        fluidnameLabel->raise();
        tempLabel->raise();
        tempSpin->raise();

        verticalLayout->addWidget(groupBox);


        retranslateUi(StageWidget);

        QMetaObject::connectSlotsByName(StageWidget);
    } // setupUi

    void retranslateUi(QWidget *StageWidget)
    {
        StageWidget->setWindowTitle(QApplication::translate("StageWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StageWidget", "Stage", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("StageWidget", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StageWidget", "Mixing Duration (s) :", 0, QApplication::UnicodeUTF8));
        stageLabel->setText(QApplication::translate("StageWidget", "Stage:", 0, QApplication::UnicodeUTF8));
        heattimeLabel->setText(QApplication::translate("StageWidget", "Heating Duration (s):", 0, QApplication::UnicodeUTF8));
        fluidamntLabel->setText(QApplication::translate("StageWidget", "Fluid Amount (mL):", 0, QApplication::UnicodeUTF8));
        fluidnameLabel->setText(QApplication::translate("StageWidget", "Enter Fluid Name:", 0, QApplication::UnicodeUTF8));
        tempLabel->setText(QApplication::translate("StageWidget", "Beaker Temperature (C):", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StageWidget: public Ui_StageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGEWIDGET_H
