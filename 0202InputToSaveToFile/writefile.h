#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class writefile : public QWidget
{
    Q_OBJECT
public:
    explicit writefile(QWidget *parent = 0);

    //定义行编辑，获得输入数据
    QLineEdit * name;
    QLineEdit * age;
    QLineEdit * score;

    //定义按钮，确定写入数据
    QPushButton * button;

signals:

public slots:
    //当按钮按下，执行数据保存操作
    void savedata();
};

#endif // WRITEFILE_H
