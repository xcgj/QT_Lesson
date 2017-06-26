/*****************************************************************
 * 创建棋盘运行程序窗口
 *****************************************************************/

#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(500, 470);
    //创建棋盘对象
    this->ch = new chess;
    //将棋盘放入窗口中
    this->setCentralWidget(ch);

    //组件菜单栏
    QMenuBar * bar = menuBar();
    QMenu * menu = bar->addMenu("文件");
    menu->addAction("重新开始", this, SLOT(isnew()));//自定义槽函数
    menu->addAction("保存", this, SLOT(issave()));
    menu->addAction("读档", this, SLOT(isload()));
    menu->addAction("悔棋", this, SLOT(isback()));
    menu->addSeparator();//分割线
    menu->addAction("退出", this, SLOT(close()));
}

void mainwindow::isnew()
{
    //初始化棋盘
    ch->init();
    //更新绘图
    ch->update();
}

void mainwindow::issave()
{
    //文件路径
    QString filename = QFileDialog::getSaveFileName(
                this,
                "保存",
                "D:\\",
                "chess(*.chess)");

    if (filename.length() > 0)
    {
        //调用文件保存函数
        ch->save(filename);
    }
}

void mainwindow::isload()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                "打开",
                "D:\\",
                "chess(*.chess)");

    if (filename.length() > 0)
    {
        //调用文件打开函数
        ch->load(filename);
    }
}

void mainwindow::isback()
{
    //悔棋函数
    ch->backOneChesStep();
}
