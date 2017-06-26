#include "widget.h"
#include "myapplication.h"

int main(int argc, char *argv[])
{
    //自定义QQApplication，继承于QApplication
    //重写notify函数
    myapplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
