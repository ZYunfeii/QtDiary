#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <userwindow.h>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int FindUsernameIndex(QString,QStringList);
    void paintEvent(QPaintEvent *);


    QStringList usernameList;
    QStringList password;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
