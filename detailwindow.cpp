#include "detailwindow.h"
#include "ui_detailwindow.h"

DetailWindow::DetailWindow(QString diary,QString time,QString pointSize,QString family,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailWindow)
{
    ui->setupUi(this);


    QFont font;
    font.setFamily(family);
    font.setPointSize(pointSize.toInt());
    ui->textBrowser->setFont(font);

    ui->textBrowser->setText(diary);
    ui->timeEdit->setText(time);


    this->setWindowTitle(QString::fromLocal8Bit("Detail"));
}

DetailWindow::~DetailWindow()
{
    delete ui;
}
