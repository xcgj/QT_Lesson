#include "widget.h"
#include <QApplication>
#include "button.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //基类对象以子类对象作为父对象的释放问题
    Widget * base = new Widget;
    button * derive = new button;
    base->setParent(derive);

    delete derive;//base也被释放了

    //信号与槽
    Widget send;
    button receve;

    //send发出信号，receve接收信号后调用处理函数执行相关操作
    //QObject::connect(&send, &Widget::sigFunc, &receve, &button::dealmessage);
    QObject::connect(&send, SIGNAL(sigFunc()),&receve, SLOT(dealmessage()));

    //调用函数发出信号
    send.sendmessage();

    Widget w;
    w.show();

    return a.exec();
}
