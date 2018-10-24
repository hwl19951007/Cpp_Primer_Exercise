# 笔记
---
1. **<<** 运算符为输出运算符。接受左右两个对象，左边必须是一个ostream对象，右边则是要打印的值。在 **<<** 运算符的链中，左侧对象始终是第一个接收的对象。

   **>>** 运算符为输入运算符，在 **>>** 运算符的链中，逻辑同输出运算符。

举例如下：

```c++
std::cout << "Enter two numbers:" << std::endl;
```

实际上等价于：

```c++
std::cout << "Enter two numbers:";
std::cout << std::endl;
```

前一句将字符串打印到输出中，第二句将打印句结束。

Std是标准库的简写，std::cout指的是在标准库这个命名空间下的cout对象。
<br>

2. 后续介绍的主要是一些基础语句，如for循环，while循环，if语句，以及类的简介。

# 练习
---
#### 练习1.3：编写程序，在标准输出上打印Hello, world。
```c++
#include <iostream>
int main()
{
    std::cout << "Hello World!\n" << std::endl; 
}
```
<br>

#### 练习1.4：我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。
```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl;
    return 0;
}
```
<br>

#### 练习1.5：我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。
```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```
<br>

#### 练习1.6：解释下面程序片断是否合法：
```c++
std::cout << "The sum of " << v1;
<< " and " << v2;
<< " is " << v1 + v2 << std::endl;
```
不合法，因为在语句中加了分号，使语句逻辑破碎了。解决方法：
```c++
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```
<br>

#### 练习1.7：编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。
```c++
1>c:\users\hwl1995\c++projects\helloworld\helloworld\helloworld.cpp(10): warning C4138: 在注释外找到“*/”
1>c:\users\hwl1995\c++projects\helloworld\helloworld\helloworld.cpp(10): error C2059: 语法错误:“/”
```
<br>

#### 练习1.8： 指出下列哪些输出语句是合法的（如果有的话）：
```c++
std::cout << "/*"; //合法 输出/*
std::cout << "*/"; //合法	输出*/
std::cout << /* "*/" */;	//非法	可修改为std::cout << /* " */"/* */;
std::cout << /* "*/" /* "/*" */;	//合法 构成了两个完整的/**/注释界定符。只有" /* "没有落在注释界定符中， 得以正常输出。
（C++中可以在句中包含注释。）
```
<br>


#### 练习1.9：编写程序，使用while循环将50到100的整数相加。
```c++
#include <iostream>
int main()
{
    int i=50, sum=0;
    while (i <= 100) {
	sum += i, ++i;
 }
    std::cout << sum;
    return 0;
}
```
<br>

#### 练习1.10：除了++运算符将运算对象的值增加1之外，还有一个递减运算符（--）实现将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
```c++
#include <iostream>
int main()
{
    int i = 10;
　  while (i >= 0) {
  　    std::cout << " " << i;
 　     --i;
 }
    return 0;
}

```
<br>

#### 练习1.11：编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
```c++
#include <iostream>
int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    while (v2 - v1 >= 0) { //默认v2 > v1
        std::cout << " " << v1;
        ++v1;
    }
    return 0;
}
```
<br>

#### 练习1.12：下面的for循环完成了什么功能？sum的终值是多少？
```c++
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```
完成了从-100到100 的整数相加的过程。终值为0。
<br>

#### 练习1.13：使用for 循环重做练习1.9，1.10，1.11。
```c++
1.9
#include <iostream>
int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;
    std::cout << sum;
    return 0;
}
1.10
#include <iostream>
int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << " " << i;
    return 0;
}
1.11
#include <iostream>
int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    for (;v2 - v1 >= 0; ++v1)	//默认v2>v1
        std::cout << " " << v1;
    return 0;
}
```
<br>

#### 练习1.14：对比for循环和while循环，两种形式的优缺点各是什么？

1、在for循环中，循环控制变量的初始化和修改都放在语句头部分，形式较简洁，且特别适用于循环次数已知的情况。
2、在while循环中，循环控制变量的初始化一般放在while语句之前，循环控制变量的修改一般放在循环体中，形式上不如for语句简洁，但它比较适用于循环次数不易预知的情况（用某一条件控制循环）。

3、两种形式各有优点，但它们在功能上是等价的，可以相互转换。
<br>

#### 练习1.16：编写程序，从cin读取一组数，输出其和。
```c++
#include <iostream>
int main()
{
    int value = 0, sum = 0;
    std::cout << "Enter some numbers:" << std::endl;
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "The sum of numbers is:" << sum << std::endl;
    return 0;
}
```
<br>

#### 练习1.17：如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎么样？

1）没有输出。2）每输入一个不同的值，就会输出前一个值出现了一次的信息（xxx occurs 1 times）。
<br>

#### 练习1.18：编译并运行本节的程序，给它输入全都相等的值。再次运行程序，输入没有重复的值。
<br>

#### 练习1.19：修改你为练习1.11所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。
```c++
#include <iostream>
int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    if (v1 > v2){
        int t;
        t = v2;
        v2 = v1;
        v1 = t;
    }
    while (v2 - v1 >= 0) {
        std::cout << " " << v1;
        ++v1;
    }
    return 0;
}
```
<br>

#### 练习1.20：在网站http://www.informit.com/title/0321714113上，第一章的代码目录中包含了头文件Sales_item.h。将它拷贝到你自己的工作目录中，用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item;
    while (std::cin >> item)
        std::cout << item << std::endl;
    return 0;
}
```
<br>

#### 练习1.21：编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。
```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cout << "Please enter two items that have same ISBN: " << std::endl;
    std::cin >> item1 >> item2;
    std::cout << "The sum is :" << item1 + item2 << std::endl;
    return 0;
}
```
<br>

#### 练习1.22：编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和。
```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin >> item1;
    while (std::cin >> item2 and item1.isbn()==item2.isbn()) {
        item1 += item2;
    }
    std::cout << "The sum is :" << item1 << std::endl;
    return 0;
}
```
<br>

#### 练习1.23：编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。
```c++
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    int count = 1;
    std::cin >> item1;
    while (std::cin >> item2) {
        if (item1.isbn() == item2.isbn()) {
            count += 1;
        }
        else {
            std::cout << item1.isbn() << " have " << count << " sale records." << std::endl;
            item1 = item2;
            count = 1;
           }
       }
    return 0;
}
```
<br>

#### 练习1.24：输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起。
<br>

#### 练习1.25：借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。