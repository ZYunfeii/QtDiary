#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMovie>
#include <fstream>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	// 获得头像address
	this->getImgAdd();


    //设置背景gif
    setGif();

    QMap<QString,QString> userMap;                 //记录用户名和密码的
    QMap<QString,UserWindow*> userWindowMap;       //装载用户名和用户界面的

    //lineEdit 的 setText是设置文本 text是获取文本

    userMap["1"] = "1";
    userMap["ZYunfei"] = "YUNFEI";
    userMap["NBY"] = "NBY";


    //登录名 默认为张云飞
    ui->lineEdit_username->setText("ZYunfei");
    ui->lineEdit_password->setFocus();                     //设置光标默认



    for(int i = 0;i < userMap.size(); ++i)
    {
        //创建n个数据库（n = usernameList.length()）
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",QString("myDiary%1").arg(i));
        db.setDatabaseName(QString(".//qtDb%1.db").arg(i));
        if( !db.open())  qDebug() << "无法建立数据库连接";       //这个db.open相当关键啊！没这一步后面写数据可失败。
        else qDebug()<<"数据库连接成功";

        QSqlQuery query(db);
        query.exec("create table person (time varchar, diary varchar,family varchar,pointSize varchar)");
        db.close();
    }

    //初始化登录后的用户界面
    QMap<QString,QString>::ConstIterator iteMap = userMap.begin();
    for(iteMap = userMap.begin();iteMap != userMap.end();iteMap++)
    {
        UserWindow * userWindow = new UserWindow(iteMap.key(),this);
        userWindowMap[iteMap.key()] = userWindow;
    }




    //当点击登录按钮时判断password是否正确
    connect(ui->pushButton_login,&QPushButton::clicked,[=](){
        QString username = ui->lineEdit_username->text();
        if(userMap[username] == "") QMessageBox::critical(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("登录账号不存在！"));
        if(userMap[username] != "")
        {
            if(ui->lineEdit_password->text() == userMap[username])
            {
                //创建主用户窗口（登录成功后窗口）
                this->hide();
                userWindowMap[username]->show();
                connect(userWindowMap[username],&UserWindow::ChooseBackSignal,[=](){
                    this->show();
					getImgAdd();
					QPixmap tmpPix;
					tmpPix.load(QString::fromStdString(userImg[username.toStdString()]));
					ui->image_label->setPixmap(tmpPix);
					userWindowMap[username]->close();
                });
            }
            else QMessageBox::critical(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("登录密码有误！"));
        }
    });

    //当点击退出按钮时退出登录界面
    connect(ui->pushButton_logout,&QPushButton::clicked,[=](){this->close();});


    //登录界面人物头像显示（类似qq）
    QTimer * timer = new QTimer(this);
    timer->start(200);
    connect(timer,&QTimer::timeout,[=](){
        QString userName = ui->lineEdit_username->text();
        if(userMap.count(userName) != 0)
        {
            QPixmap tmpPix;
            tmpPix.load(QString::fromStdString(userImg[userName.toStdString()]));
            ui->image_label->setPixmap(tmpPix);

        }
        else ui->image_label->clear();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGif(void)
{
    QMovie * movie = new QMovie(":/images/IMG_7.gif");
    ui->gifLabel->setMovie(movie);
    movie->start();
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case Qt::Key_Return:                          //回车按下激活登录按钮
        emit ui->pushButton_login->clicked();
        break;
    }
}

void MainWindow::getImgAdd()
{
	// 读头像地址txt文本
	ifstream ifs;
	ifs.open("./userImgAdd.txt", ios::in);
	if (!ifs.is_open())
	{
		// 没有文件的情况下用下面的默认头像
		qDebug() << "file doesn't exit";
		userImg["1"] = ":/images/IMG_12.png";
		userImg["ZYunfei"] = ":/images/IMG_11.png";
		userImg["NBY"] = ":/images/IMG_13.png";
	}
	else
	{
		// 加载文件中头像地址
		string name;
		string address;
		while (ifs >> name && ifs >> address)
		{
			userImg[name] = address;
		}
	}
}
