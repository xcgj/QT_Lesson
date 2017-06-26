#include <iostream>
#include <functional>
using namespace std;

//自定义函数
void myfunc(int a, char b, double c)
{
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    //定义函数对象
    //function<void()>
    function<void(int, char, double)> a;//代替函数指针
    a = myfunc;
    a(1, 'a', 3.3);

    //当函数对象参数与自定义函数参数不匹配时，用适配
    function<void(double, char, int)> b;
    b = bind(myfunc, placeholders::_3, placeholders::_2, placeholders::_1);
    b(5.5,'b', 6);


//void myfunc(int a, char b, double c)


    function<void(char, double, int)> c;
    c = bind(myfunc, placeholders::_3, placeholders::_1, placeholders::_2);
    c('c',3.3,6);


    function<void(double, int, char)> d;
    d = bind(myfunc, placeholders::_2, placeholders::_3, placeholders::_1);
    d(3.3, 6, 'd');
/*****************************************************************
 * placeholders：占位参数
 * _3：表示myfunc函数的第一个参数去b函数的第三个位置找
 * _1：表示myfunc函数的第三个参数去b函数的第一个位置找
 * _2：表示myfunc函数的第二个参数去b函数的第二个位置找
 *****************************************************************/

    function<void(char, double)> e;
    e = bind(myfunc, 100, placeholders::_1, placeholders::_2);
    e('e', 3.3);

    function<void(char, int)> f;
    f = bind(myfunc, placeholders::_2, placeholders::_1, 6.6);
    f('f', 1000);

    //=============固定中间的参数==============
    function<void(double, int)> g;
    g = bind(myfunc, placeholders::_2, 'g', placeholders::_1);
    g(7.7, 200);

    return 0;
}
