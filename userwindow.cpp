#include "userwindow.h"
#include "ui_userwindow.h"
#include "editwindow.h"
#include "diarylog.h"
#include "timelistwindow.h"
#include <QDebug>
#include <QPainter>
#include <QDateTime>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QFileDialog>
#include <qmessagebox.h>
#include <map>
//extern map<string, string> userImg;
UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{

}

UserWindow::UserWindow(QString str,class MainWindow* w):ui(new Ui::UserWindow)
{
    ui->setupUi(this);
	this->userName = str;

    //��ʼ�����Ͻ�ͷ����Ϣ
    QPixmap tmpPix;
    tmpPix.load(QString::fromStdString(w->userImg[str.toStdString()]));
    ui->userLabel->setScaledContents(true);
    ui->userLabel->setPixmap(tmpPix);

	// ��װ�¼�������
	ui->userLabel->installEventFilter(this);


    //��ʼ����������ʱ��
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    ui->timeLabel->setText(QString::fromLocal8Bit("������%1").arg(time));


    //�˵��˳�ѡ��
    connect(ui->actionOutApp,&QAction::triggered,[=](){this->close();});

    //�˵����ص�¼����ѡ��
    connect(ui->actionBackLog,&QAction::triggered,[=](){
       emit this->ChooseBackSignal();
    });

    //��ʼ��layout
    ui->textEditStart->setText(QString::fromLocal8Bit("������Ͻ��½���ť����ʼ���ĵ�һƪ�ռǰɣ�"));
    QVBoxLayout * playout = new QVBoxLayout;     //QScrollArea��layout
    playout->setDirection(QBoxLayout::BottomToTop);
	


    //��������
    QString windowName = QString::fromLocal8Bit(str.toUtf8()) + QString::fromLocal8Bit("���ռ�").toUtf8();
    this->setWindowTitle(windowName);

    //�������ݿ� �����ռ���ʷ��Ϣ��diarylog��ʽ����
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
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,w->userImg,this);
			this->diarylogList.push_back(diaryLog);
            playout->addWidget(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);

            //����ɾ���ź�
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString::fromLocal8Bit("�����ۼ�д����%1ƪ�ռ�").arg(numberOfRows));
            });
        }
    }


    //���ڼ�¼��ť��������list
    connect(ui->timeListButon,&QPushButton::clicked,[=](){
        TimeListWindow * timeListWindow = new TimeListWindow(str,this);
        timeListWindow->show();
        QPropertyAnimation *pPosAnimation1 = new QPropertyAnimation(timeListWindow, "pos");     //��Ӷ���
        pPosAnimation1->setDuration(550);
        pPosAnimation1->setStartValue(QPoint(this->x(),this->y()+this->height()-timeListWindow->height()));
        pPosAnimation1->setEndValue(QPoint(this->x()-timeListWindow->width(),this->y()+this->height()-timeListWindow->height()));
        pPosAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
        pPosAnimation1->start();
    });

    //��ʼ���ռ���������ʾ�ڶ���
    query.first();
    query.previous();
    if(query.last())
    {
        numberOfRows =  query.at() + 1;
    }
    ui->diaryNumLabel->setText(QString::fromLocal8Bit("�����ۼ�д����%1ƪ�ռ�").arg(numberOfRows));



    //����½��򿪱༭����
    connect(ui->newFileButton,&QToolButton::clicked,[=](){
        EditWindow * editWindow = new EditWindow(this);
        editWindow->show();
        QPropertyAnimation *pPosAnimation2 = new QPropertyAnimation(editWindow, "pos");     //��Ӷ���
        pPosAnimation2->setDuration(550);
        pPosAnimation2->setStartValue(QPoint(this->x()-100,this->y()));
        pPosAnimation2->setEndValue(QPoint(this->x()-100,this->y()+200));
        pPosAnimation2->setEasingCurve(QEasingCurve::InOutQuad);
        pPosAnimation2->start();



        //�����༭���ڱ����ź�
        connect(editWindow,&EditWindow::saveSignal,[=](){
            QString diary = editWindow->diary;             //ȡ���ռ�����
            QString fontFamily = editWindow->font.family();       //�ռǵ�������
            QString fontPointSize = QString::number(editWindow->font.pointSize());   //�ռǵ������С

            editWindow->close();

            //��ȡ��ǰʱ��
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            //����ռ�widget
			w->getImgAdd();
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,w->userImg,this);
            playout->addWidget(diaryLog);
			this->diarylogList.push_back(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);



            //�������ݿⱣ��ʱ�䡢�ռ����ݡ����塢�ֺ�
            databaseInit(str);
            QSqlQuery query(db);
            query.prepare("INSERT INTO person (time, diary,family,pointSize)"
                          "VALUES (:time, :diary, :family, :pointSize)");
            query.bindValue(":time",time);
            query.bindValue(":diary",diary);
            query.bindValue(":family",fontFamily);
            query.bindValue(":pointSize",fontPointSize);
            bool flag = query.exec();
            qDebug()<<flag;

            //���¶����ռ�������ʾ
            numberOfRows += 1;
            ui->diaryNumLabel->clear();
            ui->diaryNumLabel->setText(QString::fromLocal8Bit("�����ۼ�д����%1ƪ�ռ�").arg(numberOfRows));

            //����ɾ���ź�
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString::fromLocal8Bit("�����ۼ�д����%1ƪ�ռ�").arg(numberOfRows));
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
    if(str == "ZYunfei") {i = 0;}
    if(str == "1") {i = 1;}
    if(str == "NBY") {i = 2;}
    db = QSqlDatabase::addDatabase("QSQLITE", QString("myDiary%1").arg(i));
    db.setDatabaseName(QString(".//qtDb%1.db").arg(i));
    if( !db.open())         //���db.open�൱�ؼ�����û��һ������д���ݿ�ʧ�ܡ�
    {
        qDebug() << "�޷��������ݿ�����";
    }
    else
    {
        qDebug()<<"���ݿ����ӳɹ�";
    }
}

// ��ͷ��
bool UserWindow::eventFilter(QObject *obj, QEvent *event)
{
	// ֻ֧��Ӣ�����Ƶ�ͼƬ
	if (qobject_cast<QLabel*>(obj) == ui->userLabel && event->type() == QEvent::MouseButtonRelease)
	{
		QString path = QFileDialog::getOpenFileName(this, "open the file", "C:\\Users\\lenovo\\Desktop");
		if (path == "") return true; // ��;�˳�ѡ��ͼƬ������ֱ��return��
		QString strAll;
		QStringList strList;
		QFile readFile("userImgAdd.txt");
		if (readFile.open((QIODevice::ReadOnly | QIODevice::Text)))
		{
			QTextStream stream(&readFile);
			strAll = stream.readAll();
		}
		readFile.close();
		QFile writeFile("userImgAdd.txt");
		if (writeFile.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream stream(&writeFile);
			strList = strAll.split("\n");
			for (int i = 0; i < strList.count(); i++)
			{
				QStringList tempList = strList.at(i).split(" ");
				if (tempList.at(0) == this->userName)
				{
					QString tempStr = this->userName + " " + path;
					stream << tempStr << "\n";
				}
				else if (i == strList.count() - 1)
				{
					stream << strList.at(i);
				}
				else
				{
					stream << strList.at(i) << "\n";
				}
			}
		}
		writeFile.close();
		// ����diarylog��ͷ��
		QPixmap tmpPix;
		tmpPix.load(path);
		for (vector<class DiaryLog*>::iterator it = diarylogList.begin(); it < diarylogList.end(); it++)
		{
			(*it)->proLabel->setScaledContents(true);
			(*it)->proLabel->setPixmap(tmpPix);
		}
		
		// �������Ͻ�����ͷ��
		ui->userLabel->setScaledContents(true);
		ui->userLabel->setPixmap(tmpPix);
		return true;
	}
	return false;
}

UserWindow::~UserWindow()
{
    qDebug()<<"����userWindow����";
    delete ui;
}


