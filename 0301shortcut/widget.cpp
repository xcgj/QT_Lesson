#include "widget.h"
#include <QMouseEvent>
#include <QDebug>

#define cout qDebug()<< "[" << __FILE__ << ":" << __LINE__ << "]:"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //启动计时器
    tim1 = startTimer(1000);
    tim2 = startTimer(5000);
}

Widget::~Widget()
{

}

void Widget::mousePressEvent(QMouseEvent *ev)
{
    //鼠标和键盘连按快捷键
    Qt::KeyboardModifiers m = ev->modifiers();
    if (m == Qt::ShiftModifier)
    {
        cout << "shift 被按下";
    }
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    // 当按下字符时，返回的都是大写的字符
    char a = e->key();
    cout << a;

    //按键联动
    cout << e->modifiers();

    //连按
    cout << e->isAutoRepeat();

}

void Widget::timerEvent(QTimerEvent *ev)
{
    //检测计时器事件
    if (tim1 == ev->timerId())
    {
        cout << "tim1";
    }

    if (tim2 == ev->timerId())
    {
        cout << "tim2";
        //取消计时器
        killTimer(tim2);
    }
}
