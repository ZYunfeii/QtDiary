#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0);
    UserWindow(QString);
    ~UserWindow();
    void paintEvent(QPaintEvent *);

    QSqlDatabase db;
    void databaseInit(QString str);
    int getUserIndex(QString str);

    int numberOfRows = 0;             //日记条数



private:
    Ui::UserWindow *ui;

signals:
    void ChooseBackSignal();
};

#endif // USERWINDOW_H
