#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>  //水平
#include <QVBoxLayout>  //垂直
#include <QGridLayout>  //网格

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    //定义标签类
    QLineEdit * le1;
    QLineEdit * le2;
    QLineEdit * le3;

    //布局操作函数
    void hbox();
    void vbox();
    void gbox();

signals:

public slots:
};

#endif // WIDGET_H
