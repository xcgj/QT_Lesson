#include "widget.h"
#include <QPushButton>

widget::widget(QWidget *parent) : QWidget(parent)
{
    //设置主窗口大小
    this->resize(200, 70);

    //设置按钮信息
    write = new QPushButton("写文件", this);
    write->move(10, 10);
    read = new QPushButton("读文件", this);
    read->move(write->width() + 10, 10);

    //设置副窗口信息
    writewindow.setWindowTitle("写文件");
    writewindow.resize(200,300);
    readwindow.setWindowTitle("读文件");
    readwindow.resize(200,300);

    //将按钮和对应的窗口链接
    //当按钮按下，调用相应的槽函数，让窗口显示
    connect(write, SIGNAL(clicked()), this, SLOT(showwrite()));
    connect(read, &QPushButton::clicked, this, &widget::showread);
}

void widget::showwrite()
{
    writewindow.show();
}

void widget::showread()
{
    readwindow.show();
}
