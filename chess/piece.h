/*****************************************************************
 * 棋子
 *****************************************************************/
#ifndef PIECE_H
#define PIECE_H
#include "rowandclo.h"
#include <QPainter>

class piece
{
public:
    piece();

    //枚举列出棋子
    enum Type{JIANG, SHI, XIANG, CHE, MA, PAO, BING};

    int & d;
    int row;//棋子所在行，用来传入drawpiece函数画棋子
    int col;//棋子所在列，用来传入drawpiece函数画棋子
    int id;//0~15 红色 16～31黑色，棋子身份标识
    bool dead;//棋子活动状态
    Type type;

    //调用一次函数画一个棋子           被选中的棋子
    void drawpiece(QPainter & p, int selectId);
};

#endif // PIECE_H
