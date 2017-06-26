/*****************************************************************
 * 棋盘的点和棋盘窗口的点的转换
 *****************************************************************/
#ifndef ROWANDCLO_H
#define ROWANDCLO_H

#include <QPoint>
#include <QRect>

class rowandclo
{
public:
    rowandclo();

    //设定棋盘长宽
    static int d;

    //通过棋盘上的行和列获得 点 在棋盘部件窗口的位置
    static QPoint chessPointToWidgetPoint(int row, int col);

    //通过棋盘上的行和列获得 点 在棋盘部件窗口的位置，并返回以交点为中心的矩形左上角的点
    static QRect chessRectPoint(int row, int col);

    //多个棋盘像素坐标转成棋盘坐标
    static bool getChessCoodination(QPoint pt, int &row, int &col);
    //                              点击的窗口坐标
};

#endif // ROWANDCLO_H
