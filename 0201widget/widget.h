#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class widget : public QWidget
{
    Q_OBJECT
public:
    explicit widget(QWidget *parent = 0);

    //定义控件
    QPushButton *   button;
    QLabel *        label;
    QLineEdit *     lineEdit;
    QComboBox *     combox;


signals:

public slots:
    void dealSignal();
};

#endif // WIDGET_H
