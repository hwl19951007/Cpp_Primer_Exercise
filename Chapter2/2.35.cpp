#include <iostream>
int main()
{
    const int i = 42;
    auto j = i;//i为常量，auto判断会忽略顶层const，故j为int变量
    j = 0; //赋值成功，j为int型

    const auto &k = i; // 
    // k = 0; //赋值失败，因为k为const int&

    auto *p = &i;
    // *p = 0; //赋值失败，*p不可修改，因为p为const int *

    const auto j2 = i, &k2 = i; 
    // j2 = 0; //赋值失败，j2为const int，j2值不可修改
    // k2 = 0; //赋值失败，k2为const int&, k2值不可修改
}