//#include <iostream>
//using namespace std;

//#pragma pack(2)
//class A
//{
//        int i;
//        union U
//        {
//                char buff[13];
//                int i;
//        }u;
//        void foo(){    }
//        typedef char* (*f)(void*);
//        enum{red, green, bule} color;
//}a;
//int main()
//{
//    cout << sizeof(a);
//}
#include <stdio.h>
//#define SUB( X,Y ) (X+1)*Y
//int main( )
//{
//    int a=3,b=4;
//    printf( "%d\n" ,SUB( a++ ,b++ ) );
//}
int main()
{
     int a[5]={1,2,3,4,5};
     int *p=(int *)(&a+1);
     printf("%d",*(p-1));
}
