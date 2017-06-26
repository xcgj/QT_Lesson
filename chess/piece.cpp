/*****************************************************************
 * 棋子
 *****************************************************************/
#include "piece.h"


piece::piece():d(rowandclo::d)
{
    //初始化棋子活动状态
    dead = false;
    //初始化d
}

//调用一次函数画一个棋子
void piece::drawpiece(QPainter & p, int selectId)
{
    //死掉的棋子不画
    if (dead == true)
    {
        return;
    }

    //先画圆
    //画笔
    p.setPen(QPen(Qt::black));
    //选中填充灰色，不选中的填充黄色
    if (id == selectId)
    {
        p.setBrush(Qt::gray);
    }
    else
    {
        p.setBrush(Qt::yellow);
    }
    //圆心
    QPoint center = rowandclo::chessPointToWidgetPoint(row, col);
    //画圆
    p.drawEllipse(center, d/2, d/2);

    //再画字
    QString text = "帅仕相车马炮兵将士象車馬炮卒";
    int index = 7 * (id > 16) + (int)type;//区分黑白棋，type和text对应文字下标一样
    //获得字符
    QChar ch = text.at(index);
    //设置字体
    p.setFont(QFont("宋体", d/2));
    if (id<16)
    {
        p.setPen(QPen(Qt::red));
    }
    else
    {
        p.setPen(QPen(Qt::black));
    }
    p.drawText(rowandclo::chessRectPoint(row, col), Qt::AlignCenter, QString(ch));
    //                                                  居中
}
