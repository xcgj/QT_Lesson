/*****************************************************************
 * 使用布局来实现登陆框
 *  定义两个标签：登录名 密码
 *  定义两个行编辑：登录名 密码，密码密文
 *  登陆按钮
 *  头像
 *****************************************************************/

#include <QApplication>
#include "widget.h"

int main(int argv, char * argc[])
{
    QApplication a(argv, argc);

    widget w;
    w.show();

    return a.exec();
}
