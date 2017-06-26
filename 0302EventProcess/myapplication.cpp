
//好像已经修复了双击出现单击的bug？

#include "myapplication.h"

#include <QDebug>

#define cout  qDebug()<< "[" << __FILE__ << ":" << __LINE__ << "]"

myapplication::myapplication(int argc, char *argv[]):
    QApplication(argc, argv)
{

}

//所有消息，都是通过notify函数来分发的
bool myapplication::notify(QObject *ob, QEvent *ev)
{
    //拦截消息，拦截Widget的消息，widget就是ob
    //myapplication对象x在widget对象y之前创建，但是y在创建的时候已经向x注册过了
    if (this->topLevelWidgets().size() != 0)//顶级（无父组件）窗口列表不为空
    {
        //获取y对象
        //QObject * mainWidget = static_cast<QObject *>(this->topLevelWidgets()[0]);
        QObject * mainWidget = (QObject *)(this->topLevelWidgets()[0]);
        if (ob == mainWidget)
        {
            if (ev->type() == QEvent::MouseButtonPress)
            {
                cout << "notify函数收到了鼠标点击事件";

                //截断所有组件的鼠标按压事件？
                //所有组件（包括mainWidget）都收不到鼠标按压事件？
                //return true;
            }
        }
    }

    //重载函数处理完毕，把消息返回给父类处理
    return QApplication::notify(ob, ev);
}
