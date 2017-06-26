#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //当用户点击窗口时，mousePressEvent函数会被自动调用
    void mousePressEvent(QMouseEvent *event);

    //键盘
    void keyPressEvent(QKeyEvent *event);

    //计时器
    void timerEvent(QTimerEvent *event);

private:
    int tim1;
    int tim2;
};

#endif // WIDGET_H
