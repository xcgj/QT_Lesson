#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>

class myapplication : public QApplication
{
    Q_OBJECT
public:
    myapplication(int argc, char *argv[]);

    //重写notify
    bool notify(QObject *, QEvent *);

signals:

public slots:
};

#endif // MYAPPLICATION_H
