#include "button.h"
#include <QDebug>

button::button(QWidget *parent) : QPushButton(parent)
{

}

button::~button()
{
    qDebug() << "button";
}

void button::Print()
{
    qDebug() << "deal message";
}

void button::dealmessage()
{
    Print();
}
