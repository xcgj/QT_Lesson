#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //打印信息
    qDebug("xcgj");
    qDebug("sdfdskl  %d\n", 12);
    //错误信息
    qWarning("aaa");
    qCritical() << "haksfdljh";
    Widget w;
    w.show();

    return a.exec();
}
