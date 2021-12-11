#ifndef TIMELISTWIDGET_H
#define TIMELISTWIDGET_H

#include <QWidget>

namespace Ui {
class timeListWidget;
}

class timeListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit timeListWidget(QWidget *parent = 0);
    ~timeListWidget();

    void databaseInit(QString str);

private:
    Ui::timeListWidget *ui;
};

#endif // TIMELISTWIDGET_H
