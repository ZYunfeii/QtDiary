#include "editwindow.h"
#include "ui_editwindow.h"
#include <QPainter>
#include <QDebug>
#include <QFontComboBox>

EditWindow::EditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    //初始化字体
    font = (ui->fontComboBox->currentFont());
    font.setPointSize(ui->comboBox->currentText().toInt());
    ui->textEdit->setFont(font);

    //字体风格监控
    connect(ui->fontComboBox,&QFontComboBox::currentFontChanged,[=](){
        font = (ui->fontComboBox->currentFont());
        ui->textEdit->setFont(font);
    });

    //字体大小监控
    connect(ui->comboBox,&QComboBox::currentTextChanged,[=](){
        font.setPointSize(ui->comboBox->currentText().toInt());
        ui->textEdit->setFont(font);
    });


    //保存按钮
    connect(ui->saveButton,&QToolButton::clicked,[=](){
       diary = ui->textEdit->toPlainText();              //获取书写的日记内容
       emit this->saveSignal();                           //发出保存信号
    });

    //返回上一级按钮
    connect(ui->actionBack,&QAction::triggered,[=](){
        this->close();
    });
}

void EditWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/IMG_5.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

EditWindow::~EditWindow()
{
    qDebug()<<"editWindow被析构";
    delete ui;
}


