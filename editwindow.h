#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = 0);
    ~EditWindow();

    void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);     //重写回车，当回车按下时激活保存按钮信号

    QString diary;          //日记文本
    QFont font;             //字体记录
signals:
    void saveSignal(void);     //保存信号

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
