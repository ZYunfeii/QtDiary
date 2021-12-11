/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_login;
    QPushButton *pushButton_logout;
    QLabel *label_3;
    QLabel *image_label;
    QLabel *gifLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 480);
        MainWindow->setMinimumSize(QSize(700, 480));
        MainWindow->setMaximumSize(QSize(700, 480));
        QFont font;
        font.setPointSize(1);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 200, 416, 130));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 11);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(13);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_username = new QLineEdit(widget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_username->setFont(font2);
        lineEdit_username->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_username, 0, 1, 1, 1);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setFont(font2);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        lineEdit_username->raise();
        lineEdit_password->raise();
        label->raise();
        label_2->raise();
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(170, 340, 356, 53));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_login = new QPushButton(widget_2);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\344\273\277\345\256\213"));
        font3.setPointSize(13);
        pushButton_login->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_login);

        pushButton_logout = new QPushButton(widget_2);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_logout);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 50, 81, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font4.setPointSize(20);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        image_label = new QLabel(centralWidget);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(300, 100, 101, 91));
        image_label->setFrameShape(QFrame::Panel);
        image_label->setScaledContents(true);
        gifLabel = new QLabel(centralWidget);
        gifLabel->setObjectName(QString::fromUtf8("gifLabel"));
        gifLabel->setGeometry(QRect(0, 0, 700, 480));
        gifLabel->setMinimumSize(QSize(700, 480));
        gifLabel->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        gifLabel->raise();
        widget->raise();
        widget_2->raise();
        label_3->raise();
        image_label->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pushButton_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton_logout->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\220\276\350\256\260", nullptr));
        image_label->setText(QString());
        gifLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
