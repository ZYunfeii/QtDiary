#include "timelistwindow.h"
#include "ui_timelistwindow.h"
#include <QPropertyAnimation>
#include <QDebug>

TimeListWindow::TimeListWindow(QString userName,QWidget * ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeListWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("");

    //链接数据库 加载日记历史信息
    databaseInit(userName);
    QSqlQuery query(db);
    query.exec("select * from person");
    while(query.next())
    {
        QString time = query.value(0).toString();
        if(time != "")
        {
            QListWidgetItem * listWidgetItem = new QListWidgetItem(time);
            ui->listWidget->insertItem(0,listWidgetItem);
        }
    }

    //双击日期链接出detailwindow
    connect(ui->listWidget,&QListWidget::itemDoubleClicked,[=](){
        //下面这两行为了保证最多只出现一个详情窗口，即双击两个listItem后第一个会关闭
        delete detailWindow;
        detailWindow = NULL;

        QListWidgetItem * currItem = ui->listWidget->currentItem();
        QString chooseTime = currItem->text();

        databaseInit(userName);
        QSqlQuery query(db);
        query.exec("select * from person");
        while(query.next())
        {
            if(query.value(0).toString() == chooseTime)
            {
                QString diary = query.value(1).toString();
                QString fontPointSize = query.value(3).toString();
                QString fontFamily = query.value(2).toString();
                detailWindow = new DetailWindow(diary,chooseTime,fontPointSize,fontFamily);
                detailWindow->show();
                QPropertyAnimation *pPosAnimation4 = new QPropertyAnimation(detailWindow, "pos");     //添加动画
                pPosAnimation4->setDuration(550);
                pPosAnimation4->setStartValue(QPoint(ptr->x(),ptr->y()));
                pPosAnimation4->setEndValue(QPoint(ptr->x()+ptr->width(),ptr->y()));
                pPosAnimation4->setEasingCurve(QEasingCurve::InOutQuad);
                pPosAnimation4->start();

                break;
            }
        }
    });
}

void TimeListWindow::databaseInit(QString str)
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

void TimeListWindow::closeEvent(QCloseEvent *e)
{
    delete detailWindow;
    detailWindow = NULL;
}

TimeListWindow::~TimeListWindow()
{
    delete ui;
}
