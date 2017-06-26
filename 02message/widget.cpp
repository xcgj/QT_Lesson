#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
    qDebug() << "Widget释放";
}

void Widget::sendmessage()
{
    emit sigFunc();
}
