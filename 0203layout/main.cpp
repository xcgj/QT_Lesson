/*****************************************************************
 * 使用布局管理器类对标签进行布局设计
 *****************************************************************/

#include <QApplication>
#include "widget.h"

int main(int argv, char * argc[])
{
    QApplication a(argv, argc);

    widget w;
    w.show();

    return a.exec();
}
