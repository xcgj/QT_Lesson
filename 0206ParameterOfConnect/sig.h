#ifndef SIG_H
#define SIG_H

#include <QObject>

class sig : public QObject
{
    Q_OBJECT
public:
    explicit sig(QObject *parent = 0);

signals:
    void sendsig();

public slots:
};

#endif // SIG_H
