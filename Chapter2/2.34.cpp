#include <iostream>
int main()
{
	int i = 0, &r = i;
    auto a = r;
    cout << a <<endl;
    // r是i的别名，i是一个整数，故a为一个整数
    a = 42; //accept
    cout << a << endl;

    const int ci = i, &cr = ci;
    auto b = ci; //ci为一个常量，但是auto会忽略const，故b为一个int变量
    cout << b << endl;
    b = 42;
    cout << b << endl;

    auto c = cr; //cr是ci的别名，ci为常量，auto忽略const，故b为一个int变量
    cout << c << endl;
    c = 42;
    cout << c << endl;

    auto d = &i; //&i为i的地址，故d为一个指向int变量的指针
    cout << d << endl;
    //d = 42; //赋值失败，d内存储的为一个int变量的地址

    auto e = &ci; //&ci为常量ci的地址，故e本来应该为指向常量的指针，但是auto忽略顶层const，故e为一个指向int变量的指针
    cout << e << endl;

    auto &g = ci; //ci为一个常量， 故g为一个常量引用
    cout << g << endl;
    // 等式右边为常量引用，左边也必须定义为常量形式
}