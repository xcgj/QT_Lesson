#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    //重写鼠标事件，鼠标点击截屏
    void mousePressEvent(QMouseEvent *e);
};

#endif // WIDGET_H
