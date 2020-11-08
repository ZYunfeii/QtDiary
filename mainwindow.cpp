#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //lineEdit 的 setText是设置文本 text是获取文本

    usernameList<<"1"<<"张云飞"<<"Lily";
    password<<"1"<<"YUNFEI"<<"Lilypass";


    for(int i = 0;i < usernameList.length(); ++i)
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


    QVector<UserWindow*> userWindowVec;
    for(int i = 0;i < usernameList.length(); ++i)
    {
        UserWindow * userWindow = new UserWindow(usernameList[i]);
        userWindowVec.push_back(userWindow);
    }



    //当点击登录按钮时判断password是否正确
    connect(ui->pushButton_login,&QPushButton::clicked,[=](){
        int index;
        QString username = ui->lineEdit_username->text();
        index = this->FindUsernameIndex(username,usernameList);
        if(index != -1)
        {
            if(ui->lineEdit_password->text()==password.at(index))
            {
                //创建主用户窗口（登录成功后窗口）

                this->hide();
                userWindowVec[index]->show();

                connect(userWindowVec[index],&UserWindow::ChooseBackSignal,[=](){
                    this->show();
                    userWindowVec[index]->close();
                });
            }else
            {
                QMessageBox::critical(this,"错误","登录密码有误！");
            }
        }else
        {
            QMessageBox::critical(this,"错误","登录账号不存在！");
        }
    });

    //当点击退出按钮时退出登录界面
    connect(ui->pushButton_logout,&QPushButton::clicked,this,this->close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::FindUsernameIndex(QString str,QStringList usernameList)
{
    for(int i = 0;i < usernameList.size();++i)
    {
        if(str == usernameList.at(i))
        {
            return i;
        }
    }
    return -1;                  //登录账号在usernameList中不存在
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/IMG_3.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
