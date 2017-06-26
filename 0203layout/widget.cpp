#include "widget.h"
#include <QPushButton>

widget::widget(QWidget *parent) : QWidget(parent)
{
    //hbox();
    //vbox();
    gbox();
}

void widget::hbox()
{
    //布局管理器指定父窗口，其上的控件就无需指定
    QHBoxLayout * h = new QHBoxLayout(this);

    le1 = new QLineEdit("l1");
    le2 = new QLineEdit("l2");
    le3 = new QLineEdit("l3");

    h->addStretch(1);   //弹簧，比重为1
    h->addWidget(le1);
    h->addSpacing(10);  //增加控件间隔
    h->addWidget(le3);
    h->addWidget(le2);
    h->setMargin(0);    //和父窗口边框的距离
    h->setSpacing(0);   //layout内部控件的间隔
 /*****************************************************************
 * 控件的顺序和addWidget的顺序有关
 * 可以有比重，默认的比重是0，如果有其他控件比重非0，比重为0的控件，为默认大小
 * 控件可加弹簧
 * spacing:控件间的间隙
 * margin:控件和布局管理器间的间隙
 *****************************************************************/
}

void widget::vbox()
{
    QVBoxLayout * v = new QVBoxLayout;
    this->setLayout(v);

    le1 = new QLineEdit("l1");
    le2 = new QLineEdit("l2");
    le3 = new QLineEdit("l3");

    v->addStretch(1);   //弹簧，比重为1
    v->addWidget(le1);
    v->addSpacing(10);  //增加控件间隔
    v->addWidget(le3);
    v->addWidget(le2);
    v->setMargin(0);    //和父窗口边框的距离
    v->setSpacing(0);   //layout内部控件的间隔
}

void widget::gbox()
{
    QGridLayout * g = new QGridLayout(this);

    le1 = new QLineEdit("l1");
    le2 = new QLineEdit("l2");
    le3 = new QLineEdit("l3");

    //网格排序和增加顺序无关
    g->addWidget(le1, 1, 1, 1, 2);  //起始位置在第一行第1列，占位一行2列
    g->addWidget(le3, 2, 1);        //起始位置在d第二行第1列
    g->addWidget(le2, 2, 2);        //起始位置在d第二行第1列
    g->setSpacing(1);
    g->setMargin(0);

    //在上下左右个加一个弹簧，比重为1，把标签挤在中间
    g->setRowStretch(0, 1);
    g->setRowStretch(4, 1);
    g->setColumnStretch(0, 1);
    g->setColumnStretch(3, 1);

    //layout里面可以嵌套layoout===============
    QHBoxLayout * h = new QHBoxLayout;//不指定父组件，等待被添加
    QPushButton * button = new QPushButton("确定");

    //将按钮放在水平管理器中
    h->addStretch(1);       //弹簧比重为1
    h->addWidget(button, 1);//按钮比重为1

    //将水平管理器放在网格管理器中
    g->addLayout(h, 3, 1, 1, 2);//起始位置在第3行第1列，占位一行2列

}



