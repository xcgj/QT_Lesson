
#include <QApplication>
#include "widget.h"

int main(int argv, char * argc[])
{
    QApplication a(argv, argc);
    widget w;

    w.show();

    return a.exec();
}
/* 思路
 * 主窗口类选择写文件还是读文件
 *
 * 写文件
 * 定义窗口类
 * 定义控件，获得输入
 * 定义结构体，将输入结果保存
 * 序列化写入文件
 *
 * 读文件
 * 打开文件，序列化读文件
 * 显示文件内容
 */
