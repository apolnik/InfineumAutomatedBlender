/********************************************************************************
** Form generated from reading UI file 'batchdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHDIALOG_H
#define UI_BATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BatchDialog
{
public:
    QPushButton *setStageButton;
    QPushButton *closeButton;
    QLabel *batchLabel;
    QSpinBox *batchSpin;

    void setupUi(QDialog *BatchDialog)
    {
        if (BatchDialog->objectName().isEmpty())
            BatchDialog->setObjectName(QString::fromUtf8("BatchDialog"));
        BatchDialog->resize(400, 155);
        setStageButton = new QPushButton(BatchDialog);
        setStageButton->setObjectName(QString::fromUtf8("setStageButton"));
        setStageButton->setGeometry(QRect(90, 100, 99, 27));
        closeButton = new QPushButton(BatchDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(210, 100, 99, 27));
        batchLabel = new QLabel(BatchDialog);
        batchLabel->setObjectName(QString::fromUtf8("batchLabel"));
        batchLabel->setGeometry(QRect(60, 50, 271, 17));
        batchSpin = new QSpinBox(BatchDialog);
        batchSpin->setObjectName(QString::fromUtf8("batchSpin"));
        batchSpin->setGeometry(QRect(250, 50, 48, 27));
        batchSpin->setMinimum(1);
        batchSpin->setMaximum(4);

        retranslateUi(BatchDialog);

        QMetaObject::connectSlotsByName(BatchDialog);
    } // setupUi

    void retranslateUi(QDialog *BatchDialog)
    {
        BatchDialog->setWindowTitle(QApplication::translate("BatchDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        setStageButton->setText(QApplication::translate("BatchDialog", "Set Stages", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("BatchDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        batchLabel->setText(QApplication::translate("BatchDialog", "Set Number of Batches:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BatchDialog: public Ui_BatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHDIALOG_H
