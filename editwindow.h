#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>

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

    QString diary;          //日记文本
    QFont font;             //字体记录
signals:
    void saveSignal(void);     //保存信号

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
