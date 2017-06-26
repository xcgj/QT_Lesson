/*****************************************************************
 * 创建棋盘运行程序窗口框架
 *****************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chess.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);

    //将棋盘放入窗口中
    chess * ch;

signals:

public slots:
    //自定义槽函数
    void isnew();
    void issave();
    void isload();
    void isback();
};

#endif // MAINWINDOW_H
