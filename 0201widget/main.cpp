
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QPushButton>


#include "widget.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    widget w;

#if 0 //直接在主函数添加窗口
    //创建窗体
    QWidget w;
    //加按钮控件
    QPushButton button;
    button.setParent(&w);
    button.setText("按钮");
    //设置窗口名字
    w.setWindowTitle("主窗口");
    //窗口坐标
    w.setGeometry(100, 100, 300, 200);
    //获取窗口名字
    QString s = w.windowTitle();
    qDebug() << s;
#endif

    w.show();
    return a.exec();
}
