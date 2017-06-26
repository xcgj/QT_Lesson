/*****************************************************************
 * 棋盘界面程序
 *****************************************************************/
#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include "piece.h"

//保存步骤信息——悔棋
struct step
{
    int moveid;
    int killid;
    int rowFrom;
    int colFrom;
    int rowTo;
    int colTo;
};

class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = 0);

    //=============创建棋盘棋子=============
    //重写绘图事件绘制棋盘，绘图事件会自动调用
    void paintEvent(QPaintEvent *event);
    //绘制棋盘
    void drawchessboard(QPainter & p);
    //画小L
    void drawL(QPainter & p, int row, int col);
    //初始化棋子
    void init();

    //================全局棋子走动===============
    //重写鼠标点击事件
    void mousePressEvent(QMouseEvent * ev);
    //判断点击的地方有没有棋子
    int getChessId(int row, int col);
    //判断红黑棋先走
    bool redturn;
    //选择棋子
    void selectpiece(int clickId);
    //移动棋子
    void movepiece(int selectId, int clickId, int row, int col);

    //=============每个棋子的走棋规则==============
    //能否移动的判断
    bool canmove(int select, int killId, int row, int col);

    bool canmoveJIANG(int select, int killId, int row, int col);
    bool canmoveSHI(int select, int killId, int row, int col);
    bool canmoveXIANG(int select, int killId, int row, int col);
    bool canmoveCHE(int select, int killId, int row, int col);
    bool canmoveMA(int select, int killId, int row, int col);
    bool canmovePAO(int select, int killId, int row, int col);
    bool canmoveBING(int select, int killId, int row, int col);

    // 必须是一条线，如果两个坐标不是一条线，返回-1
    // 如果是一条线，则返回两个点之间的棋子数量(0, 1, 2)
    int getchesscount(int row1, int col1, int row2, int col2);

    //============文件操作===========
    //保存
    void save(QString filename);

    //读盘
    void load(QString filename);

    //悔棋
    //QList记录悔棋信息
    QList<step *> steps;
    //添加走棋信息
    void addstep(int selectId,  int killId, int row, int col);
    //初始化清空步骤列表信息
    void clearsteps();
    //悔棋
    void backOneChesStep();

public:
    //棋盘间隔
    int & d;
    //需要棋子，产生棋子
    piece s[32];//32个棋子
    //棋局中间状态变量
    int selectId;// 如果selectId是-1，那么说明没有棋子被选中

signals:

public slots:
};

#endif // CHESS_H
