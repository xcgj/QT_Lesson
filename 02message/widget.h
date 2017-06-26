#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //执行发出信号的函数
    void sendmessage();

signals:
    void sigFunc(); //发出信号

};

#endif // WIDGET_H
