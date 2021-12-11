#ifndef DIARYLOG_H
#define DIARYLOG_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <qlabel.h>
#include "detailwindow.h"
#include "userwindow.h"
#include <map>
#include <string>

namespace Ui {
class DiaryLog;
}
using namespace std;
class DiaryLog : public QWidget
{
	Q_OBJECT
		friend class UserWindow;
public:
    explicit DiaryLog(QString diary,QString time,QString pointSize,QString family,QString userName,
		              map<string,string>,QWidget *parent = 0);
    ~DiaryLog();

    void databaseInit(QString str);
    QSqlDatabase db;

    DetailWindow * detailWindow = NULL;
	QLabel * proLabel = NULL;
	Ui::DiaryLog *ui;
signals:
    void deleteSignal(void);

private:
    

};

#endif // DIARYLOG_H
