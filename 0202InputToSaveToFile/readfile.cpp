#include "readfile.h"
#include "data.h"
#include <QFile>
#include <QDataStream>
#include <QDebug>

readfile::readfile(QWidget *parent) : QWidget(parent)
{
    name =      new QLabel("姓名：", this);
    name->move(10, 40);

    nameinfo =  new QLabel(this);
    nameinfo->move(name->width(), 40);
    nameinfo->resize(50, 10);


    age =       new QLabel("年龄：", this);
    age->move(10, 110);

    ageinfo =   new QLabel(this);
    ageinfo->move(age->width(), 110);
    ageinfo->resize(50, 10);


    score =     new QLabel("分数：", this);
    score->move(10, 180);

    scoreinfo = new QLabel(this);
    scoreinfo->move(score->width(), 180);
    scoreinfo->resize(50, 10);


    button = new QPushButton("查看信息", this);
    button->move(100, 240);

    //当按下按钮，调用槽函数读取文件，显示信息
    connect(button, SIGNAL(clicked()), this, SLOT(readdata()));
}

void readfile::readdata()
{
    //临时数据对象
    DATA d;

    //打开文件
    QFile file("data.info");
    file.open(QFile::ReadOnly);

    //序列化读取
    QDataStream ds(&file);
    ds >> d.nam >> d.ag >> d.scor;

    qDebug() << d.nam;
    qDebug() << d.ag;
    qDebug() << d.scor;

    //关闭文件
    file.close();

    //输出信息
    nameinfo->setText(d.nam);
    ageinfo->setText(QString("%1").arg(d.ag));
    scoreinfo->setText(QString("%1").arg(d.scor));
}
