#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    //行编辑
    QLineEdit * ename;
    QLineEdit * ecode;

signals:

public slots:
    void myslot();
};

#endif // WIDGET_H
