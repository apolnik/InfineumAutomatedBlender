/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *addStageButton;
    QPushButton *nextButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(629, 404);
        addStageButton = new QPushButton(Dialog);
        addStageButton->setObjectName(QString::fromUtf8("addStageButton"));
        addStageButton->setGeometry(QRect(200, 370, 99, 27));
        nextButton = new QPushButton(Dialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(340, 370, 99, 27));
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 611, 351));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMovement(QListView::Static);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setUniformItemSizes(true);

        verticalLayout_2->addWidget(listWidget);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addStageButton->setText(QApplication::translate("Dialog", "Add Stage", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("Dialog", "Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
