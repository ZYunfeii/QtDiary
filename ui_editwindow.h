/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QAction *actionBack;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QLabel *label;
    QComboBox *comboBox;
    QToolButton *saveButton;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName(QStringLiteral("EditWindow"));
        EditWindow->resize(600, 400);
        EditWindow->setMinimumSize(QSize(600, 400));
        EditWindow->setMaximumSize(QSize(600, 400));
        actionBack = new QAction(EditWindow);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fontComboBox = new QFontComboBox(widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setCurrentIndex(237);

        horizontalLayout->addWidget(fontComboBox);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(30, 30));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_6.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        saveButton = new QToolButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/IMG_4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon);

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addWidget(widget);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        EditWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        EditWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionBack);

        retranslateUi(EditWindow);

        comboBox->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QApplication::translate("EditWindow", "\346\227\245\350\256\260\347\274\226\350\276\221", 0));
        actionBack->setText(QApplication::translate("EditWindow", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", 0));
        fontComboBox->setCurrentText(QApplication::translate("EditWindow", "\345\215\216\346\226\207\350\241\214\346\245\267", 0));
        label->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("EditWindow", "5", 0)
         << QApplication::translate("EditWindow", "6", 0)
         << QApplication::translate("EditWindow", "7", 0)
         << QApplication::translate("EditWindow", "8", 0)
         << QApplication::translate("EditWindow", "9", 0)
         << QApplication::translate("EditWindow", "10", 0)
         << QApplication::translate("EditWindow", "11", 0)
         << QApplication::translate("EditWindow", "12", 0)
        );
        saveButton->setText(QApplication::translate("EditWindow", "...", 0));
        menu->setTitle(QApplication::translate("EditWindow", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
