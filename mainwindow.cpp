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
	
	// ���ͷ��address
	this->getImgAdd();


    //���ñ���gif
    setGif();

    QMap<QString,QString> userMap;                 //��¼�û����������
    QMap<QString,UserWindow*> userWindowMap;       //װ���û������û������

    //lineEdit �� setText�������ı� text�ǻ�ȡ�ı�

    userMap["1"] = "1";
    userMap["ZYunfei"] = "YUNFEI";
    userMap["NBY"] = "NBY";


    //��¼�� Ĭ��Ϊ���Ʒ�
    ui->lineEdit_username->setText("ZYunfei");
    ui->lineEdit_password->setFocus();                     //���ù��Ĭ��



    for(int i = 0;i < userMap.size(); ++i)
    {
        //����n�����ݿ⣨n = usernameList.length()��
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",QString("myDiary%1").arg(i));
        db.setDatabaseName(QString(".//qtDb%1.db").arg(i));
        if( !db.open())  qDebug() << "�޷��������ݿ�����";       //���db.open�൱�ؼ�����û��һ������д���ݿ�ʧ�ܡ�
        else qDebug()<<"���ݿ����ӳɹ�";

        QSqlQuery query(db);
        query.exec("create table person (time varchar, diary varchar,family varchar,pointSize varchar)");
        db.close();
    }

    //��ʼ����¼����û�����
    QMap<QString,QString>::ConstIterator iteMap = userMap.begin();
    for(iteMap = userMap.begin();iteMap != userMap.end();iteMap++)
    {
        UserWindow * userWindow = new UserWindow(iteMap.key(),this);
        userWindowMap[iteMap.key()] = userWindow;
    }




    //�������¼��ťʱ�ж�password�Ƿ���ȷ
    connect(ui->pushButton_login,&QPushButton::clicked,[=](){
        QString username = ui->lineEdit_username->text();
        if(userMap[username] == "") QMessageBox::critical(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��¼�˺Ų����ڣ�"));
        if(userMap[username] != "")
        {
            if(ui->lineEdit_password->text() == userMap[username])
            {
                //�������û����ڣ���¼�ɹ��󴰿ڣ�
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
            else QMessageBox::critical(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��¼��������"));
        }
    });

    //������˳���ťʱ�˳���¼����
    connect(ui->pushButton_logout,&QPushButton::clicked,[=](){this->close();});


    //��¼��������ͷ����ʾ������qq��
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
    case Qt::Key_Return:                          //�س����¼����¼��ť
        emit ui->pushButton_login->clicked();
        break;
    }
}

void MainWindow::getImgAdd()
{
	// ��ͷ���ַtxt�ı�
	ifstream ifs;
	ifs.open("./userImgAdd.txt", ios::in);
	if (!ifs.is_open())
	{
		// û���ļ���������������Ĭ��ͷ��
		qDebug() << "file doesn't exit";
		userImg["1"] = ":/images/IMG_12.png";
		userImg["ZYunfei"] = ":/images/IMG_11.png";
		userImg["NBY"] = ":/images/IMG_13.png";
	}
	else
	{
		// �����ļ���ͷ���ַ
		string name;
		string address;
		while (ifs >> name && ifs >> address)
		{
			userImg[name] = address;
		}
	}
}
