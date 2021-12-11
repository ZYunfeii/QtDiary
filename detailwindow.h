#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QWidget>

namespace Ui {
class DetailWindow;
}

class DetailWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DetailWindow(QString diary,QString time,QString pointSize,QString family,QWidget *parent = 0);
    ~DetailWindow();

private:
    Ui::DetailWindow *ui;
};

#endif // DETAILWINDOW_H
