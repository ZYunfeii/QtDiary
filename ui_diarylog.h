/********************************************************************************
** Form generated from reading UI file 'diarylog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIARYLOG_H
#define UI_DIARYLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiaryLog
{
public:
    QLabel *label;
    QLabel *timeLabel;
    QTextBrowser *textBrowser;
    QPushButton *deleteButton;
    QLabel *portraitLabel;

    void setupUi(QWidget *DiaryLog)
    {
        if (DiaryLog->objectName().isEmpty())
            DiaryLog->setObjectName(QStringLiteral("DiaryLog"));
        DiaryLog->resize(350, 130);
        DiaryLog->setMinimumSize(QSize(350, 130));
        DiaryLog->setMaximumSize(QSize(350, 130));
        QFont font;
        font.setPointSize(9);
        DiaryLog->setFont(font);
        label = new QLabel(DiaryLog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 270, 130));
        label->setMinimumSize(QSize(270, 130));
        label->setMaximumSize(QSize(270, 130));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_8.png")));
        timeLabel = new QLabel(DiaryLog);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(130, 0, 161, 21));
        timeLabel->setMinimumSize(QSize(161, 21));
        timeLabel->setMaximumSize(QSize(161, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        timeLabel->setFont(font1);
        textBrowser = new QTextBrowser(DiaryLog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(110, 30, 191, 81));
        textBrowser->setMinimumSize(QSize(191, 81));
        textBrowser->setMaximumSize(QSize(191, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        textBrowser->setFont(font2);
        textBrowser->setStyleSheet(QStringLiteral("background-color: rgb(18, 189, 124);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        deleteButton = new QPushButton(DiaryLog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(320, 60, 30, 30));
        deleteButton->setMinimumSize(QSize(30, 30));
        deleteButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/IMG_9.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        deleteButton->setFlat(true);
        portraitLabel = new QLabel(DiaryLog);
        portraitLabel->setObjectName(QStringLiteral("portraitLabel"));
        portraitLabel->setGeometry(QRect(10, 80, 50, 50));
        portraitLabel->setMinimumSize(QSize(50, 50));
        portraitLabel->setMaximumSize(QSize(50, 50));

        retranslateUi(DiaryLog);

        QMetaObject::connectSlotsByName(DiaryLog);
    } // setupUi

    void retranslateUi(QWidget *DiaryLog)
    {
        DiaryLog->setWindowTitle(QApplication::translate("DiaryLog", "Form", 0));
        label->setText(QString());
        timeLabel->setText(QApplication::translate("DiaryLog", "TextLabel", 0));
        deleteButton->setText(QString());
        portraitLabel->setText(QApplication::translate("DiaryLog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class DiaryLog: public Ui_DiaryLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIARYLOG_H
