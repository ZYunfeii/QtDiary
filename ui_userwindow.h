/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QAction *actionOutApp;
    QAction *actionBackLog;
    QWidget *centralwidget;
    QToolButton *newFileButton;
    QTextEdit *textEditStart;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *userLabel;
    QLabel *timeLabel;
    QLabel *diaryNumLabel;
    QPushButton *timeListButon;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(400, 800);
        UserWindow->setMinimumSize(QSize(400, 800));
        UserWindow->setMaximumSize(QSize(400, 800));
        actionOutApp = new QAction(UserWindow);
        actionOutApp->setObjectName(QString::fromUtf8("actionOutApp"));
        actionBackLog = new QAction(UserWindow);
        actionBackLog->setObjectName(QString::fromUtf8("actionBackLog"));
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newFileButton = new QToolButton(centralwidget);
        newFileButton->setObjectName(QString::fromUtf8("newFileButton"));
        newFileButton->setGeometry(QRect(360, 30, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/IMG_2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        newFileButton->setIcon(icon);
        textEditStart = new QTextEdit(centralwidget);
        textEditStart->setObjectName(QString::fromUtf8("textEditStart"));
        textEditStart->setGeometry(QRect(10, 80, 381, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(10);
        textEditStart->setFont(font);
        textEditStart->setReadOnly(true);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 130, 381, 561));
        scrollArea->setStyleSheet(QString::fromUtf8("background-image: url(:/images/IMG_14.png);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 379, 559));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(20, 10, 50, 50));
        userLabel->setMinimumSize(QSize(50, 50));
        userLabel->setMaximumSize(QSize(50, 50));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(120, 10, 171, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        timeLabel->setFont(font1);
        timeLabel->setAlignment(Qt::AlignCenter);
        diaryNumLabel = new QLabel(centralwidget);
        diaryNumLabel->setObjectName(QString::fromUtf8("diaryNumLabel"));
        diaryNumLabel->setGeometry(QRect(120, 40, 161, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        diaryNumLabel->setFont(font2);
        diaryNumLabel->setAlignment(Qt::AlignCenter);
        timeListButon = new QPushButton(centralwidget);
        timeListButon->setObjectName(QString::fromUtf8("timeListButon"));
        timeListButon->setGeometry(QRect(40, 720, 41, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        timeListButon->setFont(font3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/IMG_16.png"), QSize(), QIcon::Normal, QIcon::Off);
        timeListButon->setIcon(icon1);
        timeListButon->setIconSize(QSize(30, 30));
        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        UserWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionOutApp);
        menu->addAction(actionBackLog);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "MainWindow", nullptr));
        actionOutApp->setText(QApplication::translate("UserWindow", "\351\200\200\345\207\272\345\272\224\347\224\250", nullptr));
        actionBackLog->setText(QApplication::translate("UserWindow", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        newFileButton->setText(QApplication::translate("UserWindow", "...", nullptr));
        userLabel->setText(QApplication::translate("UserWindow", "TextLabel", nullptr));
        timeLabel->setText(QApplication::translate("UserWindow", "TextLabel", nullptr));
        diaryNumLabel->setText(QApplication::translate("UserWindow", "TextLabel", nullptr));
        timeListButon->setText(QString());
        menu->setTitle(QApplication::translate("UserWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
