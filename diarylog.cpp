#include "diarylog.h"
#include "ui_diarylog.h"
#include <QDebug>

DiaryLog::DiaryLog(QString diary,QString time,QString pointSize,QString family,QString userName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryLog)
{
    ui->setupUi(this);

    //加载头像
    int index = getUserIndex(userName);
    QPixmap tmpPix;
    tmpPix.load(QString(":/images/IMG_1%1.png").arg(index + 1));
    ui->portraitLabel->setScaledContents(true);
    ui->portraitLabel->setPixmap(tmpPix);

    //将editwindow的信息书写在diarylog上
    QFont font;
    font.setFamily(family);
    font.setPointSize(pointSize.toInt());
    ui->textBrowser->setFont(font);
    ui->timeLabel->setText(time);
    ui->textBrowser->setText(diary);



    //删除某一条diarylog
    connect(ui->deleteButton,&QPushButton::clicked,[=](){
        databaseInit(userName);
        QSqlQuery query(db);
        QString deleteString = QString("%1%2%3").arg("'").arg(time).arg("'");                 //我思考这行代码思考了20分钟，数据库删除对比的信息如果是字符串要的是单引号！
        bool flag = query.exec(QString("DELETE FROM person WHERE time = %1").arg(deleteString));
        qDebug()<<flag;

        emit this->deleteSignal();
        delete this;   //删除userwindow中的日记框
    });
}
void DiaryLog::databaseInit(QString str)
{
    int i;
    if(str == "1") {i = 0;}
    if(str == "张云飞") {i = 1;}
    if(str == "Lily") {i = 2;}
    db = QSqlDatabase::addDatabase("QSQLITE", QString("myDiary%1").arg(i));
    db.setDatabaseName(QString(".//qtDb%1.db").arg(i));
    if( !db.open())         //这个db.open相当关键啊！没这一步后面写数据可失败。
    {
        qDebug() << "无法建立数据库连接";
    }
    else
    {
        qDebug()<<"数据库连接成功";
    }
}

int DiaryLog::getUserIndex(QString str)
{
    int i;
    if(str == "1") {i = 0;}
    if(str == "张云飞") {i = 1;}
    if(str == "Lily") {i = 2;}
    return i;
}

DiaryLog::~DiaryLog()
{
    qDebug()<<"diarylog析构函数执行";
    delete ui;
}
