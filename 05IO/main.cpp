#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QBuffer>  //内存文件 缓存

struct Stu
{
    QString name;
    int score;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //============简单数据类型的读写==============
    QString s = "阿斯顿";

    //关联文件
    QFile File("test.txt");

    //打开文件，指定读写方式
    File.open(QFile::WriteOnly);//只读
    //写文件
    File.write(s.toLocal8Bit());//将数据转成本地机器编码写入
    //Returns the local 8-bit representation of the string as a QByteArray.
    File.close();

    //读文件
    QByteArray t;
    File.open(QFile::ReadOnly);
    t = File.readAll();  //需要用字节数组接收，全部读取
    File.close();
    //将字节数组从机器编码转回QString======
    QString b = QString::fromLocal8Bit(t);
    qDebug() << b;

    //=============复杂数据类型的读写================
    Stu aaa;
    aaa.name = "aaa";
    aaa.score = 100;

    //写文件
    QFile ComFile("Stu.info");
    ComFile.open(QFile::WriteOnly);
    //使用序列化工具读写
    QDataStream ds(&ComFile);//文件指针初始化序列化对象，对象获取格式信息
    //写入文件
    ds << aaa.name << aaa.score;
    ComFile.close();

    //读文件
    Stu bbb;
    ComFile.open(QFile::ReadOnly);
    QDataStream qds(&ComFile);
    qds >> bbb.name >> bbb.score;   //输出格式顺序要和写入格式的顺序一样
    ComFile.close();
    qDebug() << bbb.name << bbb.score;

    //============内存当文件读写=================
    QBuffer bufFile;//内存文件类对象
    bufFile.open(QIODevice::WriteOnly);//QIODevice总的基类
    //在内存中写入数据
    bufFile.write("ccc");
    bufFile.write("ddd");
    bufFile.close();

    //从内存中读取刚刚写入的数据
    QByteArray Data = bufFile.buffer();
    qDebug() << Data;

    //=========内存拷贝效率==========
    QByteArray buf1(10000, 0);
    QByteArray buf2;
    buf2 = buf1;    // C++效率低下，Qt效率不低下，因为Qt内存共享


    Widget w;
    w.show();

    return a.exec();
}
