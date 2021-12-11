/********************************************************************************
** Form generated from reading UI file 'timelistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMELISTWINDOW_H
#define UI_TIMELISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeListWindow
{
public:
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QWidget *TimeListWindow)
    {
        if (TimeListWindow->objectName().isEmpty())
            TimeListWindow->setObjectName(QString::fromUtf8("TimeListWindow"));
        TimeListWindow->resize(232, 300);
        TimeListWindow->setMinimumSize(QSize(232, 300));
        TimeListWindow->setMaximumSize(QSize(232, 300));
        listWidget = new QListWidget(TimeListWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 211, 261));
        listWidget->setLayoutDirection(Qt::LeftToRight);
        label = new QLabel(TimeListWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 4, 141, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        label->setFont(font);
        label->setMidLineWidth(1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(TimeListWindow);

        QMetaObject::connectSlotsByName(TimeListWindow);
    } // setupUi

    void retranslateUi(QWidget *TimeListWindow)
    {
        TimeListWindow->setWindowTitle(QApplication::translate("TimeListWindow", "Form", nullptr));
        label->setText(QApplication::translate("TimeListWindow", "\346\227\245\350\256\260\346\227\266\351\227\264\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeListWindow: public Ui_TimeListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELISTWINDOW_H
