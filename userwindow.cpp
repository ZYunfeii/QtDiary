#include "userwindow.h"
#include "ui_userwindow.h"
#include "editwindow.h"
#include "diarylog.h"
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QFile>
#include <QGridLayout>


UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{

}

UserWindow::UserWindow(QString str):ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    //初始化左上角头像信息
    int index = getUserIndex(str);
    QPixmap tmpPix;
    tmpPix.load(QString(":/images/IMG_1%1.png").arg(index + 1));
    ui->userLabel->setScaledContents(true);
    ui->userLabel->setPixmap(tmpPix);

    //初始化顶部日期时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    ui->timeLabel->setText(QString("今天是%1").arg(time));


    //菜单退出选项
    connect(ui->actionOutApp,&QAction::triggered,[=](){this->close();});

    //菜单返回登录界面选项
    connect(ui->actionBackLog,&QAction::triggered,[=](){
       emit this->ChooseBackSignal();
    });

    //初始化layout
    ui->textEditStart->setText("点击右上角新建按钮，开始您的第一篇日记吧！");
    QVBoxLayout * playout = new QVBoxLayout;     //QScrollArea的layout
    playout->setDirection(QBoxLayout::BottomToTop);


    //界面名称
    QString windowName = QString(str.toUtf8()) + QString("的日记").toUtf8();
    this->setWindowTitle(windowName);

    //链接数据库 加载日记历史信息以diarylog形式呈现
    databaseInit(str);
    QSqlQuery query(db);
    query.exec("select * from person");
    while(query.next())
    {
        QString time = query.value(0).toString();
        QString diary = query.value(1).toString();
        QString fontPointSize = query.value(3).toString();
        QString fontFamily = query.value(2).toString();
        if(diary != "")
        {
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,this);
            playout->addWidget(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);

            //监听删除信号
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString("您已累计写下了%1篇日记").arg(numberOfRows));
            });
        }
    }

    //初始化日记数量并显示在顶部
    query.first();
    query.previous();
    if(query.last())
    {
        numberOfRows =  query.at() + 1;
    }
    ui->diaryNumLabel->setText(QString("您已累计写下了%1篇日记").arg(numberOfRows));



    //点击新建打开编辑窗口
    connect(ui->newFileButton,&QToolButton::clicked,[=](){
        EditWindow * editWindow = new EditWindow(this);
        editWindow->show();

        //监听编辑窗口保存信号
        connect(editWindow,&EditWindow::saveSignal,[=](){
            QString diary = editWindow->diary;             //取到日记内容
            QString fontFamily = editWindow->font.family();       //日记的字体风格
            QString fontPointSize = QString::number(editWindow->font.pointSize());   //日记的字体大小

            editWindow->close();

            //获取当前时间
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            //添加日记widget
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,this);
            playout->addWidget(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);



            //利用数据库保存时间、日记内容、字体、字号
            QSqlQuery query(db);
            query.prepare("INSERT INTO person (time, diary,family,pointSize)"
                          "VALUES (:time, :diary, :family, :pointSize)");
            query.bindValue(":time",time);
            query.bindValue(":diary",diary);
            query.bindValue(":family",fontFamily);
            query.bindValue(":pointSize",fontPointSize);
            query.exec();

            //更新顶部日记数量显示
            numberOfRows += 1;
            ui->diaryNumLabel->clear();
            ui->diaryNumLabel->setText(QString("您已累计写下了%1篇日记").arg(numberOfRows));

            //监听删除信号
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString("您已累计写下了%1篇日记").arg(numberOfRows));
            });
        });

    });

}

void UserWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/IMG_10.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void UserWindow::databaseInit(QString str)
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

int UserWindow::getUserIndex(QString str)
{
    int i;
    if(str == "1") {i = 0;}
    if(str == "张云飞") {i = 1;}
    if(str == "Lily") {i = 2;}
    return i;
}


UserWindow::~UserWindow()
{
    qDebug()<<"调用userWindow析构";
    delete ui;
}


