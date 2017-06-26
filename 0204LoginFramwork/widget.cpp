#include "widget.h"

/*****************************************************************
 * 使用布局来实现登陆框
 *  定义两个标签：登录名 密码
 *  定义两个行编辑：登录名 密码，密码密文
 *  登陆按钮
 *  头像
 *****************************************************************/

widget::widget(QWidget *parent) : QWidget(parent)
{
    //标签类
    QLabel * head = new QLabel;
    head->setPixmap(QPixmap("D:/Code/Qt_practice/1.jpg"));
    QLabel * lname = new QLabel("登录名：");
    QLabel * lcode = new QLabel("密码：");

    //按钮
    QPushButton * button = new QPushButton("确定");

    //行编辑
    ename = new QLineEdit;
    ename->setPlaceholderText("请输入登录名");
    ecode = new QLineEdit;
    ecode->setPlaceholderText("请输入密码");
    ecode->setEchoMode(QLineEdit::Password);

    //布局管理器
    QGridLayout * g = new QGridLayout(this);//全局
    QVBoxLayout * v = new QVBoxLayout;  //中心
    QHBoxLayout * h1 = new QHBoxLayout;
    QHBoxLayout * h2 = new QHBoxLayout;
    QHBoxLayout * h3 = new QHBoxLayout;
    QHBoxLayout * h4 = new QHBoxLayout;

    //先设全局布局管理器=============
    //上下左右加弹簧，中间加垂直布局管理器
    g->setRowStretch(0, 1);
    g->setRowStretch(2, 1);
    g->setColumnStretch(0, 1);
    g->setColumnStretch(2, 1);
    g->addLayout(v, 1, 1);

    //设置垂直布局管理器
    v->addLayout(h1, 10);   //为什么这里调比重没效果？
    v->addLayout(h2, 1);
    v->addLayout(h3, 1);
    v->addLayout(h4, 1);

    //设置水平布局管理器
    h1->addStretch(1);
    h1->addWidget(head,2);
    h1->addStretch(1);

    h2->addWidget(lname, 1);
    h2->addWidget(ename, 2);

    h3->addWidget(lcode, 1);
    h3->addWidget(ecode, 2);

    h4->addStretch(1);
    h4->addWidget(button);

    //信号和槽================
    connect(button, &QPushButton::clicked, this, &widget::myslot);

}

void widget::myslot()
{
    QString name = ename->text();
    QString code = ecode->text();
    if (name.length() == 0 || code.length() == 0)
    {
        qDebug() << "输入错误";
        return;
    }
    else    //用户名密码验证
    {
        qDebug() << name << code;
    }
}
