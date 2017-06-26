#include "widget.h"
#include <QMouseEvent>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::mousePressEvent(QMouseEvent *e)
{
    //先设置保存截图的画板，长宽为当前需要截图的图片的长宽
    //只能截取当前窗口
    QPixmap map(width(), height());

    //截图函数render
    this->render(&map);

    //保存图片到桌面
    map.save("D:/1.png");
}
