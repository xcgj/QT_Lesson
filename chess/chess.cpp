 /*****************************************************************
 * 棋盘界面程序
 *****************************************************************/
#include "chess.h"
#include <QPainter>  //画家
#include "rowandclo.h"
#include <QMouseEvent>
#include <QDebug>
#include <QFile>
#include <QDataStream>

//                                              获得棋盘边距
chess::chess(QWidget *parent) : QWidget(parent), d(rowandclo::d)
{
    init();
}

//重写绘图事件绘制棋盘，绘图事件会自动调用
void chess::paintEvent(QPaintEvent *event)
{
    //以当前棋盘部件为父组件进行绘制
    QPainter p(this);

    //绘制棋盘
    drawchessboard(p);

    //绘制棋子
    for (int i = 0; i < 32; ++i)
    {
        //需要棋子，产生棋子
        s[i].drawpiece(p, selectId);
    }

}

//绘制棋盘
void chess::drawchessboard(QPainter &p)
{
    //画横线
    for (int i = 1; i <= 10; ++i)
    {
        p.drawLine(QPoint(d, i*d), QPoint(9*d, i*d));
    }

    //画竖线
    for (int i = 1; i <=9; ++i)
    {
        //中间位置预留空间，楚河汉界
        //画两边
        if (i == 1 || i == 9)
        {
            p.drawLine(QPoint(i*d, d), QPoint(i*d, 10*d));
        }
        //画中间
        else
        {
            p.drawLine(QPoint(i*d, d), QPoint(i*d, 5*d));
            p.drawLine(QPoint(i*d,6*d), QPoint(i*d, 10*d));
        }
    }

    //画九宫格
    p.drawLine(QPoint(4*d, d), QPoint(6*d, 3*d));
    p.drawLine(QPoint(4*d, 3*d), QPoint(6*d, d));

    p.drawLine(QPoint(4*d, 8*d), QPoint(6*d, 10*d));
    p.drawLine(QPoint(4*d, 10*d), QPoint(6*d, 8*d));

    //画小L
    //传入行和列，0为起始
    drawL(p, 2, 1);
    drawL(p, 2, 7);
    drawL(p, 3, 0);
    drawL(p, 3, 2);
    drawL(p, 3, 4);
    drawL(p, 3, 6);
    drawL(p, 3, 8);

    drawL(p, 6, 0);
    drawL(p, 6, 2);
    drawL(p, 6, 4);
    drawL(p, 6, 6);
    drawL(p, 6, 8);
    drawL(p, 7, 1);
    drawL(p, 7, 7);
}

//画小L
void chess::drawL(QPainter &p, int row, int col)
{
    //获得棋盘交叉点在棋盘部件的窗口坐标
    QPoint center = rowandclo::chessPointToWidgetPoint(row, col);
    //直角点的坐标
    QPoint angle;

    //如果不是最后一列，那么就画右上角和右下角
    if (col != 8)
    {
        //画右上角
        //直角点==中心点加上偏移量
        angle = center + QPoint(d/6, d/6);
        //向右画
        p.drawLine(angle, angle + QPoint(d/3, 0));
        //向上画
        p.drawLine(angle, angle + QPoint(0, d/3));

        //画右下角
        //直角点==中心点加上偏移量
        angle = center + QPoint(d/6, -d/6);
        //向右画
        p.drawLine(angle, angle + QPoint(d/3, 0));
        //向下画
        p.drawLine(angle, angle + QPoint(0, -d/3));
    }

    //如果不是第一列，那么就画左上角和左下角
    if (col != 0)
    {
        //画左上角
        //直角点==中心点加上偏移量
        angle = center + QPoint(-d/6, d/6);
        //向左画
        p.drawLine(angle, angle + QPoint(-d/3, 0));
        //向上画
        p.drawLine(angle, angle + QPoint(0, d/3));

        //画左下角
        //直角点==中心点加上偏移量
        angle = center + QPoint(-d/6, -d/6);
        //向左画
        p.drawLine(angle, angle + QPoint(-d/3, 0));
        //向下画
        p.drawLine(angle, angle + QPoint(0, -d/3));
    }
}

void chess::init()
{
    //初始化步骤信息列表
    clearsteps();

    //棋子初始化列表
    static struct{
        piece::Type type;//名字
        int row;
        int col;
    }
    pie[16] = {
        {piece::CHE, 9, 8},
        {piece::MA, 9, 7},
        {piece::XIANG, 9, 6},
        {piece::SHI, 9, 5},
        {piece::JIANG, 9, 4},
        {piece::CHE, 9, 0},
        {piece::MA, 9, 1},
        {piece::XIANG, 9, 2},
        {piece::SHI, 9, 3},
        {piece::PAO, 7, 1},
        {piece::PAO, 7, 7},
        {piece::BING, 6, 0},
        {piece::BING, 6, 2},
        {piece::BING, 6, 4},
        {piece::BING, 6, 6},
        {piece::BING, 6, 8}
    };

    //初始化32个棋子
    for (int i = 0; i < 32; ++i)
    {
        s[i].id = i;
        s[i].dead = false;
        if (s[i].id < 16)
        {
            s[i].type = pie[i].type;
            s[i].row = pie[i].row;
            s[i].col = pie[i].col;
        }
        else
        {
            s[i].type = pie[i-16].type;
            s[i].row = 9-pie[i-16].row;
            s[i].col = 8-pie[i-16].col;
        }
    }

    //棋局中间状态变量，默认棋子没有被选中
    selectId = -1;
    redturn = true;
}

void chess::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)
    {
        return;
    }

    //========多个棋盘像素坐标转成棋盘坐标
    //获取点击的位置
    QPoint positionclick = ev->pos();
    int row = -1;
    int col = -1;
    if (rowandclo::getChessCoodination(positionclick, row, col) == false)
    {
        //点到棋盘外，点击作废
        return;
    }
    qDebug() << row << col;

    //判断点击的地方有没有棋子
    int clickId = getChessId(row, col);

    //获得id，判断是选择还是走棋
    if (selectId == -1)//说明没有选中任何棋子
    {
        selectpiece(clickId);
#if 0
        //选择对方的棋子无效
        //if (redturn && clickId > 15)return;
        //if (!redturn && clickId < 16)return;
        if (redturn != (clickId < 16))return;

        //将状态变为选中棋子
        selectId = clickId;
        update();
#endif
        //return;

    }
    else//说明之前已经有选中的棋子了
    {
        //防止同色残杀
        //点击有效并且是同色棋子就交换选中
        if (clickId != -1 && ((clickId < 16) == (selectId < 16)))
        {
            selectpiece(clickId);
#if 0
            selectId = clickId;
            update();
#endif
            return;
        }

        //先判断是否符合棋子的走棋规则
        if (canmove(selectId, clickId, row, col))
        {
            movepiece(selectId, clickId, row, col);
    #if 0
            //移动选中的棋子
            s[selectId].row = row;
            s[selectId].col = col;
            if (clickId != -1)//移动过去的位置有棋子
            {
                s[clickId].dead = true;//吃棋子
            }
            update();
            //初始化selectId
            selectId = -1;
            //改变走棋顺序
            redturn = !redturn;
    #endif
        }
    }
}

int chess::getChessId(int row, int col)
{
    //遍历棋子坐标与点击坐标（传入参数），并判断棋子活动状态
    for (int i = 0; i < 32; ++i)
    {
        if (s[i].row == row && s[i].col == col && !s[i].dead)
        {
            //返回棋子id
            return i;
        }
    }
    return -1;
}

//选择棋子
void chess::selectpiece(int clickId)
{
    if (redturn != (clickId < 16))return;

    //将状态变为选中棋子
    selectId = clickId;
    update();
    return;
}

//移动棋子
void chess::movepiece(int select, int kill, int row, int col)
{
    //记录步骤
    addstep(select, kill, row, col);

    //移动选中的棋子
    s[select].row = row;
    s[select].col = col;
    if (kill != -1)//移动过去的位置有棋子
    {
        s[kill].dead = true;//吃棋子
    }
    //初始化selectId
    selectId = -1;
    //改变走棋顺序
    redturn = !redturn;
    update();

    return;
}

//能否移动的判断，棋子走棋规则
bool chess::canmove(int select, int killId, int row, int col)
{
    //判断棋子类型，指定对应规则
    switch(s[select].type)
    {
    case piece::JIANG:
        return canmoveJIANG(select, killId, row, col);
        break;
    case piece::SHI:
        return canmoveSHI(select, killId, row, col);
        break;
    case piece::XIANG:
        return canmoveXIANG(select, killId, row, col);
        break;
    case piece::CHE:
        return canmoveCHE(select, killId, row, col);
        break;
    case piece::MA:
        return canmoveMA(select, killId, row, col);
        break;
    case piece::PAO:
        return canmovePAO(select, killId, row, col);
        break;
    case piece::BING:
        return canmoveBING(select, killId, row, col);
        break;
    }
    return true;
}

/*
只能走一步
只能走九宫
照面吃子
*/
bool chess::canmoveJIANG(int select, int killId, int row, int col)
{
    //照面吃子
    if (killId != -1 && s[killId].type == piece::JIANG)
    {
        int ret = getchesscount(s[select].row, s[select].col, row, col);
        if (ret == 0)
        {
            return true;
        }
    }

    //只能走一步
    int drow = qAbs(s[select].row - row);
    int dcol = qAbs(s[select].col - col);
    if (drow + dcol != 1)
    {
        return false;
    }

    //只能走九宫
    if (col < 3 || col > 5)return false;
    if (s[select].id < 16)//红棋
    {
        if (row < 7 || row > 9)
        {
            return false;
        }
    }
    else
    {
        if(row < 0 || row > 2)//黑棋
        {
            return false;
        }
    }
    return true;
}

/*
写着走
只能走九宫
*/
bool chess::canmoveSHI(int select, int killId, int row, int col)
{
    //只能走九宫
    if (col < 3 || col > 5)return false;
    if (s[select].id < 16)//红棋
    {
        if (row < 7 || row > 9)
        {
            return false;
        }
    }
    else
    {
        if(row < 0 || row > 2)//黑棋
        {
            return false;
        }
    }

    //斜着走
    int drow = qAbs(s[select].row - row);
    int dcol = qAbs(s[select].col - col);
    if (drow * 10 + dcol != 11)//错位算法
    {
        return false;
    }
    return true;
}

/*
不能过河
田
象眼不能有子
*/
bool chess::canmoveXIANG(int select, int killId, int row, int col)
{
    //不能过河
    if (s[select].id < 16)//红棋
    {
        if(row < 5)//跨河
        {
            return false;
        }
    }
    else//黑棋
    {
        if(row > 4)//跨河
        {
            return false;
        }
    }

    //田
    int drow = qAbs(s[select].row - row);
    int dcol = qAbs(s[select].col - col);
    if (drow * 10 + dcol != 22)//错位算法
    {
        return false;
    }

    //象眼不能有子
    int eyerow = (s[select].row + row) / 2;
    int eyecol = (s[select].col + col) / 2;
    //获取象眼位置有无棋子
    int eye = getChessId(eyerow, eyecol);
    if (eye != -1)
    {
        return false;
    }
    return true;
}

/*
走直线
直线内不能有子
*/
bool chess::canmoveCHE(int select, int killId, int row, int col)
{
    int ret = getchesscount(s[select].row, s[select].col, row, col);
    if (ret != 0)
    {
        return false;
    }

    return true;
}

/*
日
不能压马腿
*/
bool chess::canmoveMA(int select, int killId, int row, int col)
{
    //日
    int drow = qAbs(s[select].row - row);
    int dcol = qAbs(s[select].col - col);
    int d = drow * 10 + dcol;
    if (d != 21 && d != 12)//错位算法
    {
        return false;
    }

    //马腿位置
    if(d == 21)//行相差是2
    {
        int lrow = (s[select].row + row) / 2;
        int lcol = s[select].col;
        //判断有没有棋子在上面
        if (getChessId(lrow, lcol) != -1)
        {
            return false;
        }
    }
    else
    {
        int eRow = s[select].row;
        int eCol = (s[select].col + col) / 2;
        if(getChessId(eRow, eCol) != -1) return false;
    }

    return true;
}

/*
炮在移动，getchesscount返回值为0；
炮在吃子，getchesscount返回值为1；
*/
bool chess::canmovePAO(int select, int killId, int row, int col)
{
    //移动
    if (killId == -1)
    {
        int ret = getchesscount(s[select].row, s[select].col, row, col);
        if (ret != 0)
        {
            return false;
        }
    }
    else//吃子
    {
        int ret = getchesscount(s[select].row, s[select].col, row, col);
        if (ret != 1)
        {
            return false;
        }
    }
    return true;
}

/*
只能走一步
过河前不能平移后退
过河后不能后退可平移
*/
bool chess::canmoveBING(int select, int killId, int row, int col)
{
    //红棋
    if (s[select].id < 16)
    {
        //不能后退，目标行大于棋子行
        if (row > s[select].row)
        {
            return false;
        }
        //没过河
        if (s[select].row >= 5)
        {
            //平移
            if (s[select].row == row)
            {
                return false;
            }
        }
    }
    else//黑棋
    {
        //不能后退，目标行大于棋子行
        if (row < s[select].row)
        {
            return false;
        }
        //没过河
        if (s[select].row <= 4)
        {
            //平移
            if (s[select].row == row)
            {
                return false;
            }
        }
    }

    //只能走一步
    int drow = qAbs(s[select].row - row);
    int dcol = qAbs(s[select].col - col);
    if (drow + dcol != 1)
    {
        return false;
    }
    return true;
}

// 必须是一条线，如果两个坐标不是一条线，返回-1
// 如果是一条线，则返回两个点之间的棋子数量(0, 1, 2)
int chess::getchesscount(int row1, int col1, int row2, int col2)
{
    int count = 0;

    if(row1 != row2 && col1!=col2) return -1;

    //行相等，遍历列
    if (row1 == row2)
    {
        //找出较小的你那个列
        if (col1 > col2)
        {
            int tmp = col1;
            col1 = col2;
            col2 = tmp;
        }

        //开始找棋子数量，遍历不包含col1和col2的位置
        for(int col = col1+1; col < col2; ++col)
        {
            if(getChessId(row1, col) != -1) count++;
        }
    }
    else//列相等，遍历行
    {
        if(row1 > row2)
        {
            int tmp = row1;
            row1 =row2;
            row2 = tmp;
        }
        for(int row = row1+1; row < row2; ++row)
        {
            if(getChessId(row, col1) != -1) count++;
        }
    }

    return count;
}

//保存文件
void chess::save(QString filename)
{
    QFile file(filename);
    file.open(QFile::WriteOnly);

    QDataStream ds(&file);
    //保存下棋状态
    ds << selectId << redturn;
    //保存棋子状态
    for(int i=0; i<32; ++i)
    {
        int type = (int)s[i].type;
        ds << s[i].col << s[i].row << s[i].id << s[i].dead << type;
    }

    //保存步骤信息
    ds << steps.size();
    foreach(step* val, steps)
    {
        ds << val->colFrom << val->colTo << val->killid <<
              val->moveid << val->rowFrom << val->rowTo;
    }

    file.close();
}

//读盘
void chess::load(QString filename)
{
    QFile file(filename);
    file.open(QFile::ReadOnly);

    QDataStream ds(&file);
    //保存下棋状态
    ds >> selectId >> redturn;
    //保存棋子状态
    for(int i=0; i<32; ++i)
    {
        int type;
        ds >> s[i].col >> s[i].row >> s[i].id >> s[i].dead >> type;
        s[i].type = (piece::Type)type;
    }

    //读出棋盘步骤
    int size;
    ds >> size;
    for (int i = 0; i < size; ++i)
    {
        step * ste = new step;
        ds >> ste->colFrom >> ste->colTo >> ste->killid >>
                ste->moveid >> ste->rowFrom >> ste->rowTo;

        //读出来的信息存到步骤列表
        steps.push_back(ste);
    }

    file.close();
    update();
}

//添加走棋信息
void chess::addstep(int selectId, int killId, int row, int col)
{
    step * ste = new step;
    ste->moveid = selectId;
    ste->killid = killId;
    ste->rowTo = row;
    ste->colTo = col;
    ste->rowFrom = s[selectId].row;
    ste->colFrom = s[selectId].col;

    //将信息放入列表
    steps.append(ste);
}

//初始化清空步骤列表信息
void chess::clearsteps()
{
    //如果步骤列表不为空，清空列表
    while(steps.size())
    {
        //挨个删除
        step * ste = steps.first();//辅助变量
        delete ste;
        steps.removeFirst();
    }
}

//悔棋
void chess::backOneChesStep()
{
    //判断列表是否为空
    if (steps.size() == 0)
    {
        return;
    }

    //把最后一步棋的信息拿出来。恢复了再刷新棋盘
    step * ste = steps.last();
    steps.removeLast();

    //上一步棋子操作复位
    s[ste->moveid].row = ste->rowFrom;
    s[ste->moveid].col = ste->colFrom;
    //被吃棋子状态复位
    if(ste->killid != -1)
    {
        s[ste->killid].dead = false;
    }
    //出手顺序复位
    redturn = !redturn;
    //取消棋子选择，如果有
    selectId = -1;

    delete ste;
    update();
}
