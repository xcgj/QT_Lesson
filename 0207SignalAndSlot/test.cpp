
#include <QApplication>
#include "widget.h"

int main(int argv, char * argc[])
{
    QApplication a(argv, argc);

    widget w;
    w.show();

    return a.exec();
}
