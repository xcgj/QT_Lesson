#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class button : public QPushButton
{
    Q_OBJECT
public:
    explicit button(QWidget *parent = 0);

    ~button();

    void Print();

signals:

public slots:
    void dealmessage();//收到信号后被调用的函数
};

#endif // BUTTON_H
