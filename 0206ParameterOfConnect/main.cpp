/*****************************************************************
 * 1 connect是QObject的静态函数
 * 2 connect有两种信号和槽链接方式，有5个参数
     [static] QMetaObject::Connection QObject::connect(
     const QObject *sender,                         //发送者
     const char *signal,                            //信号
     const QObject *receiver,                       //接收者
     const char *method,                            //槽
     Qt::ConnectionType type = Qt::AutoConnection)  //链接类型
 * 方式一：
 *  QObject::connect(&send, SIGNAL(sendsig(), &rece, SLOT(dealsig());
 * 方式二：
 *  QObject::connect(&send, &sig::sendsig, &rece, &slo::dealsig);
 * 3 信号发送模式和函数执行顺序
 *   自动链接方式先执行槽函数，主函数再继续往下执行
 *   队列连接方式先执行主函数，再执行槽函数，先入先出，要注意变量的主函数生命周期
 *****************************************************************/

#include <QApplication>
#include "sig.h"
#include "slo.h"
#include <QObject>
#include <QDebug>

int main(int argv, char * argc[])
{
    QApplication a(argv, argc);

    //定义信号和槽对象
    sig send;
    slo rece;

    //方式一：
    //自动连接方式
    //QObject::connect(&send, SIGNAL(sendsig()), &rece, SLOT(dealsig()), Qt::AutoConnection);
    //队列连接方式
    //QObject::connect(&send, SIGNAL(sendsig()), &rece, SLOT(dealsig()), Qt::QueuedConnection);
    //方式二：
    //自动连接方式
    //QObject::connect(&send, &sig::sendsig, &rece, &slo::dealsig, Qt::AutoConnection);
    //队列连接方式
    QObject::connect(&send, &sig::sendsig, &rece, &slo::dealsig, Qt::QueuedConnection);

    //执行顺序与connect连接方式的研究
    qDebug() << "开始发送信号";
    emit send.sendsig();
    qDebug() << "信号发送完毕";

    return a.exec();
}
