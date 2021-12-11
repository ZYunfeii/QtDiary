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

    //初始化左上角头像信息
    QPixmap tmpPix;
    tmpPix.load(QString::fromStdString(w->userImg[str.toStdString()]));
    ui->userLabel->setScaledContents(true);
    ui->userLabel->setPixmap(tmpPix);

	// 安装事件过滤器
	ui->userLabel->installEventFilter(this);


    //初始化顶部日期时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    ui->timeLabel->setText(QString::fromLocal8Bit("今天是%1").arg(time));


    //菜单退出选项
    connect(ui->actionOutApp,&QAction::triggered,[=](){this->close();});

    //菜单返回登录界面选项
    connect(ui->actionBackLog,&QAction::triggered,[=](){
       emit this->ChooseBackSignal();
    });

    //初始化layout
    ui->textEditStart->setText(QString::fromLocal8Bit("点击右上角新建按钮，开始您的第一篇日记吧！"));
    QVBoxLayout * playout = new QVBoxLayout;     //QScrollArea的layout
    playout->setDirection(QBoxLayout::BottomToTop);
	


    //界面名称
    QString windowName = QString::fromLocal8Bit(str.toUtf8()) + QString::fromLocal8Bit("的日记").toUtf8();
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
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,w->userImg,this);
			this->diarylogList.push_back(diaryLog);
            playout->addWidget(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);

            //监听删除信号
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString::fromLocal8Bit("您已累计写下了%1篇日记").arg(numberOfRows));
            });
        }
    }


    //日期记录按钮链接日期list
    connect(ui->timeListButon,&QPushButton::clicked,[=](){
        TimeListWindow * timeListWindow = new TimeListWindow(str,this);
        timeListWindow->show();
        QPropertyAnimation *pPosAnimation1 = new QPropertyAnimation(timeListWindow, "pos");     //添加动画
        pPosAnimation1->setDuration(550);
        pPosAnimation1->setStartValue(QPoint(this->x(),this->y()+this->height()-timeListWindow->height()));
        pPosAnimation1->setEndValue(QPoint(this->x()-timeListWindow->width(),this->y()+this->height()-timeListWindow->height()));
        pPosAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
        pPosAnimation1->start();
    });

    //初始化日记数量并显示在顶部
    query.first();
    query.previous();
    if(query.last())
    {
        numberOfRows =  query.at() + 1;
    }
    ui->diaryNumLabel->setText(QString::fromLocal8Bit("您已累计写下了%1篇日记").arg(numberOfRows));



    //点击新建打开编辑窗口
    connect(ui->newFileButton,&QToolButton::clicked,[=](){
        EditWindow * editWindow = new EditWindow(this);
        editWindow->show();
        QPropertyAnimation *pPosAnimation2 = new QPropertyAnimation(editWindow, "pos");     //添加动画
        pPosAnimation2->setDuration(550);
        pPosAnimation2->setStartValue(QPoint(this->x()-100,this->y()));
        pPosAnimation2->setEndValue(QPoint(this->x()-100,this->y()+200));
        pPosAnimation2->setEasingCurve(QEasingCurve::InOutQuad);
        pPosAnimation2->start();



        //监听编辑窗口保存信号
        connect(editWindow,&EditWindow::saveSignal,[=](){
            QString diary = editWindow->diary;             //取到日记内容
            QString fontFamily = editWindow->font.family();       //日记的字体风格
            QString fontPointSize = QString::number(editWindow->font.pointSize());   //日记的字体大小

            editWindow->close();

            //获取当前时间
            QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

            //添加日记widget
			w->getImgAdd();
            DiaryLog * diaryLog = new DiaryLog(diary,time,fontPointSize,fontFamily,str,w->userImg,this);
            playout->addWidget(diaryLog);
			this->diarylogList.push_back(diaryLog);
            ui->scrollArea->widget()->setLayout(playout);



            //利用数据库保存时间、日记内容、字体、字号
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

            //更新顶部日记数量显示
            numberOfRows += 1;
            ui->diaryNumLabel->clear();
            ui->diaryNumLabel->setText(QString::fromLocal8Bit("您已累计写下了%1篇日记").arg(numberOfRows));

            //监听删除信号
            connect(diaryLog,&DiaryLog::deleteSignal,[=](){
                numberOfRows -= 1;
                ui->diaryNumLabel->clear();
                ui->diaryNumLabel->setText(QString::fromLocal8Bit("您已累计写下了%1篇日记").arg(numberOfRows));
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
    if( !db.open())         //这个db.open相当关键啊！没这一步后面写数据可失败。
    {
        qDebug() << "无法建立数据库连接";
    }
    else
    {
        qDebug()<<"数据库连接成功";
    }
}

// 换头像
bool UserWindow::eventFilter(QObject *obj, QEvent *event)
{
	// 只支持英文名称的图片
	if (qobject_cast<QLabel*>(obj) == ui->userLabel && event->type() == QEvent::MouseButtonRelease)
	{
		QString path = QFileDialog::getOpenFileName(this, "open the file", "C:\\Users\\lenovo\\Desktop");
		if (path == "") return true; // 中途退出选择图片操作，直接return掉
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
		// 重置diarylog的头像
		QPixmap tmpPix;
		tmpPix.load(path);
		for (vector<class DiaryLog*>::iterator it = diarylogList.begin(); it < diarylogList.end(); it++)
		{
			(*it)->proLabel->setScaledContents(true);
			(*it)->proLabel->setPixmap(tmpPix);
		}
		
		// 重置左上角人物头像
		ui->userLabel->setScaledContents(true);
		ui->userLabel->setPixmap(tmpPix);
		return true;
	}
	return false;
}

UserWindow::~UserWindow()
{
    qDebug()<<"调用userWindow析构";
    delete ui;
}


