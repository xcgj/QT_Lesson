#ifndef SLO_H
#define SLO_H

#include <QObject>

class slo : public QObject
{
    Q_OBJECT
public:
    explicit slo(QObject *parent = 0);

signals:

public slots:
    void dealsig();
};

#endif // SLO_H
