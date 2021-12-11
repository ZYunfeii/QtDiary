#ifndef TIMELISTWINDOW_H
#define TIMELISTWINDOW_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "detailwindow.h"

namespace Ui {
class TimeListWindow;
}

class TimeListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TimeListWindow(QString userName,QWidget *ptr,QWidget *parent = 0);
    ~TimeListWindow();

    QSqlDatabase db;
    void databaseInit(QString str);
    DetailWindow * detailWindow = NULL;

protected:
    void closeEvent(QCloseEvent *);      //重写关闭事件，当timelistwindow关闭时关闭打开的detailwindow


private:
    Ui::TimeListWindow *ui;
};

#endif // TIMELISTWINDOW_H
