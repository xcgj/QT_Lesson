#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QMap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<int> v;
    v.push_back(10);
    v.push_front(20);
    v.insert(v.begin() + 2, 30);
    v[1] = 50;

    //for_each
    //foreach(auto a : v)
    foreach(auto a, v)
    {
        qDebug() << a;
    }


    QMap<QString, int> m;
    //  m.insert(make_pair("aaa", 10));
    //  m.insert(pair<string, int>("aaa", 10));
    //  m.insert(map<string, int>::type_value("aaa", 10);
    m.insert("aaa", 10);
    m["bbb"] = 20;
    m["ccc"] = 30;
    m["ddd"] = 40;

    m["bbb"] = 30;
    m["ddd"] += 5;

    //=====遍历
    //Returns a list containing all the keys in the map in ascending order.
    //Keys that occur multiple times in the map (because items were inserted with insertMulti(), or unite() was used)
    //also occur multiple times in the list.
    //keys()：返回map中所有的键，多重键出现几次返回几次
    foreach(QString a, m.keys())
    {
        qDebug() << a << m[a];
    }

    Widget w;
    w.show();

    return a.exec();
}
