/********************************************************************************
** Form generated from reading UI file 'detailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILWINDOW_H
#define UI_DETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailWindow
{
public:
    QTextBrowser *textBrowser;
    QLineEdit *timeEdit;

    void setupUi(QWidget *DetailWindow)
    {
        if (DetailWindow->objectName().isEmpty())
            DetailWindow->setObjectName(QString::fromUtf8("DetailWindow"));
        DetailWindow->resize(411, 330);
        DetailWindow->setMinimumSize(QSize(411, 330));
        DetailWindow->setMaximumSize(QSize(411, 330));
        textBrowser = new QTextBrowser(DetailWindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 391, 281));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/images/IMG_15.jpg);"));
        timeEdit = new QLineEdit(DetailWindow);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(110, 10, 211, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        timeEdit->setFont(font);
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setReadOnly(true);

        retranslateUi(DetailWindow);

        QMetaObject::connectSlotsByName(DetailWindow);
    } // setupUi

    void retranslateUi(QWidget *DetailWindow)
    {
        DetailWindow->setWindowTitle(QApplication::translate("DetailWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailWindow: public Ui_DetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILWINDOW_H
