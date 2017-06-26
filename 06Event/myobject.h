#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QEvent>

class myobject : public QObject
{
    Q_OBJECT
public:
    explicit myobject(QObject *parent = 0);

    //虚函数继承，事件处理
    bool event(QEvent *event);

signals:

public slots:
};

#endif // MYOBJECT_H
