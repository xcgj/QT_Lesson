#include <QCoreApplication>
//#include <QObject>    //在"myobject"中已经包含
#include "myobject.h"

//声明事件函数
void makeEvent(QObject * obj);

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //myobject继承于QObject，父类指针指向子类对象
    //myobject * mo = new myobject;
    QObject * mo = new myobject;

    //makeEvent发送事件给myobject, myobject处理事件
    makeEvent(mo);

    return a.exec();
}
