#include "diarylog.h"
#include "ui_diarylog.h"
#include <QDebug>
#include <QPropertyAnimation>

DiaryLog::DiaryLog(QString diary,QString time,QString pointSize,QString family,QString userName,
	               map<string,string>m,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryLog)
{
    ui->setupUi(this);
	this->proLabel = ui->portraitLabel;

    //加载头像
    QPixmap tmpPix;
    tmpPix.load(QString::fromStdString(m[userName.toStdString()]));
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


    //进入一条日记的详情
    connect(ui->detailButton,&QPushButton::clicked,[=](){       
        detailWindow = new DetailWindow(diary,time,pointSize,family);
        detailWindow->show();
        QPropertyAnimation *pPosAnimation3 = new QPropertyAnimation(detailWindow, "pos");     //添加动画
        pPosAnimation3->setDuration(550);
        pPosAnimation3->setStartValue(QPoint(parent->x(),parent->y()));
        pPosAnimation3->setEndValue(QPoint(parent->x()+parent->width(),parent->y()));
        pPosAnimation3->setEasingCurve(QEasingCurve::InOutQuad);
        pPosAnimation3->start();
    });
}
void DiaryLog::databaseInit(QString str)
{
    int i;
    if(str == "ZYunfei") {i = 0;}
    if(str == "1") {i = 1;}
    if(str == "NBY") {i = 2;}
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

DiaryLog::~DiaryLog()
{
    qDebug()<<"diarylog析构函数执行";
    delete ui;
}
