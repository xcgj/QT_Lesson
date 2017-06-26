#include <QCoreApplication>
#include <QObject>
#include <QEvent>

void makeEvent(QObject * obj)
{
    //产生一个应用程序对象
    //应用程序是单例，这里的progma和主函数的a用的是同一个地址
    QCoreApplication * progra = QCoreApplication::instance();//获得应用程序地址

    //给QObject的对象obj发送事件，如果传入myobject的对象，会让myobject的对象处理事件
    //多态
    progra->sendEvent(obj, new QEvent(QEvent::User));
}
