#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <userwindow.h>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <qlabel.h>
#include <map>
#include <string>

namespace Ui {
class MainWindow;
}
using namespace std;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);     //重写回车，当回车按下时激活登录按钮点击信号
	void getImgAdd();

    void setGif(void);                 //设置界面GIF

	map<string, string> userImg;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
