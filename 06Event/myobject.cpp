#include "myobject.h"
#include <QDebug>
#include <QObject>

myobject::myobject(QObject *parent) : QObject(parent)
{

}

bool myobject::event(QEvent *event)
{
    //处理事件
    if (event->type() == QEvent::User)
    {
        qDebug() << "收到了User的事件";
    }

    //其余事件不做处理，
    //返回给myobject处理
    //return myobject::event(event);
    //返回给QObject处理
    return QObject::event(event);
}
