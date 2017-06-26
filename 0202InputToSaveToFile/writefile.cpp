#include "writefile.h"
#include "data.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>

writefile::writefile(QWidget *parent) : QWidget(parent)
{
    name = new QLineEdit(this);
    name->move(10, 40);
    name->setPlaceholderText("请输入姓名");

    age = new QLineEdit(this);
    age->move(10, 110);
    age->setPlaceholderText("请输入姓名");

    score = new QLineEdit(this);
    score->move(10, 180);
    score->setPlaceholderText("请输入姓名");

    button = new QPushButton("确定", this);
    button->move(100, 240);
    //当按钮按下，执行数据保存操作
    connect(button, &QPushButton::pressed, this, &writefile::savedata);

    //关闭窗口
    connect(button, &QPushButton::clicked, this, &writefile::close);
}

void writefile::savedata()
{
    //定义结构体，保存数据
    DATA d;
    d.nam = name->text();
    d.ag = age->text().toInt();
    d.scor = score->text().toInt();
    qDebug() << d.nam;

    //打开文件
    QFile file("data.info");
    file.open(QFile::WriteOnly);

    //序列化写入
    QDataStream ds(&file);
    ds << d.nam << d.ag << d.scor;

    //关闭文件
    file.close();

    qDebug() << "数据保存成功";
}
