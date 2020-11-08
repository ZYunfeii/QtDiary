/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QStringLiteral("UserWindow"));
        UserWindow->resize(400, 800);
        UserWindow->setMinimumSize(QSize(400, 800));
        UserWindow->setMaximumSize(QSize(400, 800));
        actionOutApp = new QAction(UserWindow);
        actionOutApp->setObjectName(QStringLiteral("actionOutApp"));
        actionBackLog = new QAction(UserWindow);
        actionBackLog->setObjectName(QStringLiteral("actionBackLog"));
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        newFileButton = new QToolButton(centralwidget);
        newFileButton->setObjectName(QStringLiteral("newFileButton"));
        newFileButton->setGeometry(QRect(360, 30, 31, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/IMG_2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        newFileButton->setIcon(icon);
        textEditStart = new QTextEdit(centralwidget);
        textEditStart->setObjectName(QStringLiteral("textEditStart"));
        textEditStart->setGeometry(QRect(10, 80, 381, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(10);
        textEditStart->setFont(font);
        textEditStart->setReadOnly(true);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 130, 381, 561));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 379, 559));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(20, 10, 50, 50));
        userLabel->setMinimumSize(QSize(50, 50));
        userLabel->setMaximumSize(QSize(50, 50));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(120, 10, 171, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        timeLabel->setFont(font1);
        timeLabel->setAlignment(Qt::AlignCenter);
        diaryNumLabel = new QLabel(centralwidget);
        diaryNumLabel->setObjectName(QStringLiteral("diaryNumLabel"));
        diaryNumLabel->setGeometry(QRect(120, 40, 161, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        diaryNumLabel->setFont(font2);
        diaryNumLabel->setAlignment(Qt::AlignCenter);
        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        UserWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionOutApp);
        menu->addAction(actionBackLog);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "MainWindow", 0));
        actionOutApp->setText(QApplication::translate("UserWindow", "\351\200\200\345\207\272\345\272\224\347\224\250", 0));
        actionBackLog->setText(QApplication::translate("UserWindow", "\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", 0));
        newFileButton->setText(QApplication::translate("UserWindow", "...", 0));
        userLabel->setText(QApplication::translate("UserWindow", "TextLabel", 0));
        timeLabel->setText(QApplication::translate("UserWindow", "TextLabel", 0));
        diaryNumLabel->setText(QApplication::translate("UserWindow", "TextLabel", 0));
        menu->setTitle(QApplication::translate("UserWindow", "\350\217\234\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
