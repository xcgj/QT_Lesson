#include "widget.h"
#include <QEvent>
#include <QDebug>

#define cout  qDebug()<< "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent): QWidget(parent){}

Widget::~Widget(){}

// event函数可以处理自定义消息
// event函数可以截取消息,只能截取这个对象的消息
// 如果需要截取全部对象的消息，需要改写notify
bool Widget::event(QEvent *e)
{
    //判断event函数接收到的事件属于哪一类事件，以便进行处理
    if (e->type() == QEvent::MouseButtonPress)
    {
        cout << "event函数收到了鼠标点击事件";

        //截断鼠标按压消息
        return true;
        //e->ignore();
    }

    //把其他消息交还给父类，继续传播
    return QWidget::event(e);
}

//单击
void Widget::mousePressEvent(QMouseEvent *e)
{
    cout << "单击";
}

//双击
void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
    cout << "双击";
}


