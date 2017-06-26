#include "slo.h"
#include <QDebug>

slo::slo(QObject *parent) : QObject(parent)
{

}

void slo::dealsig()
{
    //信号发出者
    //QObject * s = sender();
    qDebug() << "收到信号，已处理" << QObject::sender();
}
