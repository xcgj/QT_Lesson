
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    //主窗口框架
    mainwindow window;
    window.show();

    return a.exec();
}
