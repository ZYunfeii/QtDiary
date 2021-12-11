/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
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
            EditWindow->setObjectName(QString::fromUtf8("EditWindow"));
        EditWindow->resize(600, 400);
        EditWindow->setMinimumSize(QSize(0, 0));
        EditWindow->setMaximumSize(QSize(600, 400));
        actionBack = new QAction(EditWindow);
        actionBack->setObjectName(QString::fromUtf8("actionBack"));
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontComboBox = new QFontComboBox(widget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setEditable(false);
        fontComboBox->setCurrentIndex(234);

        horizontalLayout->addWidget(fontComboBox);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(30, 30));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_6.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        saveButton = new QToolButton(widget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/IMG_4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon);

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addWidget(widget);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        EditWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        EditWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionBack);

        retranslateUi(EditWindow);

        comboBox->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QApplication::translate("EditWindow", "\346\227\245\350\256\260\347\274\226\350\276\221", nullptr));
        actionBack->setText(QApplication::translate("EditWindow", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        fontComboBox->setCurrentText(QApplication::translate("EditWindow", "\345\215\216\346\226\207\346\245\267\344\275\223", nullptr));
        label->setText(QString());
        comboBox->setItemText(0, QApplication::translate("EditWindow", "6", nullptr));
        comboBox->setItemText(1, QApplication::translate("EditWindow", "7", nullptr));
        comboBox->setItemText(2, QApplication::translate("EditWindow", "8", nullptr));
        comboBox->setItemText(3, QApplication::translate("EditWindow", "9", nullptr));
        comboBox->setItemText(4, QApplication::translate("EditWindow", "10", nullptr));
        comboBox->setItemText(5, QApplication::translate("EditWindow", "11", nullptr));
        comboBox->setItemText(6, QApplication::translate("EditWindow", "12", nullptr));
        comboBox->setItemText(7, QApplication::translate("EditWindow", "13", nullptr));
        comboBox->setItemText(8, QApplication::translate("EditWindow", "14", nullptr));

        saveButton->setText(QApplication::translate("EditWindow", "...", nullptr));
        menu->setTitle(QApplication::translate("EditWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
