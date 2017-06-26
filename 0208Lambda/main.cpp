/*****************************************************************
 * lambda表达式是一个匿名函数
 * []()->int{}
 *      []：捕获列表，捕获表达式之前的外部的变量，定义时传参，类型自动推导
 *      ()：参数列表，调用时传入参数，如果没有参数传入，可以省略
 *      ->type：返回类型，可以省略，自动推导
 *      {}：函数体
 * [=]：全部变量值捕获
 * [&]：全部变量引用捕获，引用捕获时，需要注意变量的生命周期
 * 如果捕获列表和参数列表有同名变量，则使用参数列表的变量
 *****************************************************************/
#include <iostream>
using namespace std;

#include <functional>

//全局函数声明
function<void()> f;

//给全局变量实现
void realizef()
{
    int a = 100;
    //最好不要引用，f被调用时a的生命周期结束，引用了非法地址
    //f = [&a]{a = 1000;cout << a << endl;};

    //安全，a已经拷贝了一份放在了f中
    f = [a]()mutable{a = 1000;cout << a << endl;};
}


int main(void)
{
    //最简单的lambda表达式
    []{}();
    [](){};
    []{};

    //auto 类型接收lambda表达式，从匿名变为有名
    auto a = []{cout << "a" << endl;};
    a();

    //函数模板
    //定义Lambda表达式
    function<void(int)> b = [](int ){cout << "b" << endl;};
    b(1);

    //const值传递，lambda表达式中不能改变外部变量的值
    int z = 1;
    function<void()> c = [z]{/*z = 2*/;cout << "c" << endl;};
    c();

    //引用传递，能改变外部变量
    int y = 1;
    function<void()> d = [&y]{y = 2;cout << "d" << endl;};
    d();
    cout << y << endl;

    //mutable，改变lambda中的值，不影响外部变量
    //必须要写参数列表()
    int x = 1;
    function<void()> e = [x]()mutable{x = 2;cout << "e" << endl;};
    e();
    cout << x << endl;

    //变量生命周期
    realizef();
    f();

    return 0;
}
