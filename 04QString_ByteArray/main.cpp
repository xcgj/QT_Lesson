#include "widget.h"
#include <QApplication>
#include <QString>      //字符串
#include <QByteArray>   //字节数组
#include <QDebug>

/*
 * 在C语言中， 字符串==字节数组
 * GB2312 中文字符编码定义： 0x1872 中  0x1782 国  2个字符，4个字节
 * 在C语言中,要表示中国 "0x18 0x72 0x17 0x82"    字符和字节都是4个
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString s = "自行车";
    QByteArray b = "自行车";
    qDebug() << s.size() << b.size();

    //==============QString==============
    //查找，返回下标,没有返回-1
    qDebug() << s.indexOf("啊");
    qDebug() << s.indexOf("车");

    //字符串转数字
    s = "12345";
    qDebug() << s.toInt();

    s = "12345678912345678912345689";
    qDebug() << s.toInt();  //越界，输出0

    //数字转字符串
    s = QString::number(98765);
    qDebug() << s;

    s = QString::number(12345678923532546433232123456);
    qDebug() << s;  //太长了输出异常，接收的时候就出错了

    s.sprintf("%d", 1234567);
    qDebug() << s;

    s = QString("%2, %3, %1").arg(100).arg(200).arg(300);
    qDebug() << s;

    //去掉头尾空格
    s = "\t\n  123\r\n\t";
    qDebug() << s.trimmed();

    //============QByteArray========
    // 封装的是内存，内存的属性：起始地址，长度
    // ba中是“中文”字符串，编码格式取决于源代码文档的编码，mingw的QtCreator是Utf8
    // QByteArray的对象就是一块内存的名字，不是一个C风格是字符串，结尾没有\0
    QByteArray buf(10, 0);//buf分配了10个字节的内存，每个字节的值都是0
    qDebug() << buf.size();
    qDebug() << buf;

    //获得buf的首地址
    char* p = buf.data();   //获取buf首地址
    strcpy(p, "abc");
    qDebug() << p;  //打出来是个字符串
    qDebug() << buf;//da打出来是内存空间的值


    //Widget w;
    //w.show();

    return a.exec();
}
