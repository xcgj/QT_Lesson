#include "widget.h"
#include <QLineEdit>
#include <QDebug>

widget::widget(QWidget *parent) : QWidget(parent)
{
    QLineEdit *le = new QLineEdit(this);

    connect(le, &QLineEdit::cursorPositionChanged, [](int a, int b)
    {
       qDebug() << a << b;
       //a：光标移动前的“光标前的字符的下标”
       //b：光标移动后的“光标前的字符的下标”
       //第一个字符前的光标位置为0
    });

}
