/*****************************************************************
 * 棋盘的点和棋盘窗口的点的转换
 *****************************************************************/
#include "rowandclo.h"

rowandclo::rowandclo()
{

}

//设定棋盘长宽
int rowandclo::d = 40;

//通过棋盘上的行和列获得 点 在棋盘部件窗口的位置
QPoint rowandclo::chessPointToWidgetPoint(int row, int col)
{
    int x = col * d + d;
    int y = row * d + d;

    return QPoint(x, y);
}

//通过棋盘上的行和列获得 点 在棋盘部件窗口的位置，并返回以交点为中心的矩形左上角的点
QRect rowandclo::chessRectPoint(int row, int col)
{
    //先获得点 在棋盘部件窗口的位置
    QPoint center = chessPointToWidgetPoint(row, col);

    //再获得矩形左上角的点
    center += QPoint(-d/2, -d/2);
    return QRect(center.x(), center.y(), d, d);
}

//多个棋盘像素坐标转成棋盘坐标
bool rowandclo::getChessCoodination(QPoint pt, int &row, int &col)
{
    //除数值参数表
    int t[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};

    //获得对应下标
    int colindex = pt.x() / (d/2);
    int rowindex = pt.y() / (d/2);

    //判断位置合法性
//    if (rowindex == 0 || rowindex > 20 || colindex == 0 || colindex > 18)
//    {
//        return false;
//    }
    if (rowindex == 0) return false;
    if (rowindex > 20) return false;
    if (colindex == 0) return false;
    if (colindex > 18) return false;

    //获得鼠标点击所在列
    col = t[colindex];
    row = t[rowindex];

    return true;
}
