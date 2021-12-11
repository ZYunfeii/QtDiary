#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "mainwindow.h"
#include "diarylog.h"
#include <map>
#include <vector>
#include <string>


namespace Ui {
class UserWindow;
}
using namespace std;
class UserWindow : public QMainWindow
{
	Q_OBJECT

public:
    UserWindow(QWidget *parent = 0);
    UserWindow(QString,class MainWindow *);
    ~UserWindow();
    void paintEvent(QPaintEvent *);
	bool UserWindow::eventFilter(QObject *obj, QEvent *event);

    QSqlDatabase db;
    void databaseInit(QString str);

    int numberOfRows = 0;             //日记条数




private:
    Ui::UserWindow *ui;
	QString userName;
	vector<class DiaryLog*> diarylogList;

signals:
    void ChooseBackSignal();
};

#endif // USERWINDOW_H
