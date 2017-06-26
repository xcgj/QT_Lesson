#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "writefile.h"
#include "readfile.h"

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    //定义按钮类
    QPushButton * write;
    QPushButton * read;

    //定义窗口类
    writefile writewindow;
    readfile readwindow;

signals:

public slots:
    void showwrite();
    void showread();
};

#endif // WIDGET_H
