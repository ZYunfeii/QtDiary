#ifndef DIARYLOG_H
#define DIARYLOG_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class DiaryLog;
}

class DiaryLog : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryLog(QString diary,QString time,QString pointSize,QString family,QString userName,QWidget *parent = 0);
    ~DiaryLog();

    void databaseInit(QString str);
    int getUserIndex(QString str);
    QSqlDatabase db;

signals:
    void deleteSignal(void);

private:
    Ui::DiaryLog *ui;
};

#endif // DIARYLOG_H
