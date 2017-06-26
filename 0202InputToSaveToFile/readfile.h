#ifndef READFILE_H
#define READFILE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class readfile : public QWidget
{
    Q_OBJECT
public:
    explicit readfile(QWidget *parent = 0);

    //标签显示信息
    QLabel * name;
    QLabel * nameinfo;

    QLabel * age;
    QLabel * ageinfo;

    QLabel * score;
    QLabel * scoreinfo;

    //按钮读取信息
    QPushButton * button;

signals:

public slots:
    //读取数据
    void readdata();
};

#endif // READFILE_H
