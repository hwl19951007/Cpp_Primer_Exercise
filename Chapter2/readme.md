# chapter2 变量和基本类型

[TOC]



## 笔记

### 2.1基本内置类型

#### 2.1.1算术类型

- 算术类型：整型（包括字符和bool），浮点型。

- 空类型：不对应具体值，仅用于某些特殊场合。如函数不返回任何值时使用空类型作为返回类型。

- 无符号类型中的所有比特都用来存储值。
- C++标准中约定，有符号数在表示范围内正值和负值的量应该平衡。

#### 2.1.2类别转换

- 非布尔型赋值给布尔型：非0为Ture，0为False。
- 布尔赋型值给非布尔型：Ture为1，False为0。
- 浮点型赋值整型：近似处理，结果值仅保留浮点数的整数部分。
- 整型转浮点型：小数部分取0。
- 当赋一个超出其范围的值给无符号类型时，结果为初始值对无符号类型表示数字总数取模后的余数。
- 当给带符号类型赋超过其表示范围的数值时，其结果是**未定义的**，可能导致程序崩溃。

- **切勿混用带符号类型和无符号类型**。当表达式中既有带符号类型又有无符号类型时，带符号数会自动转换成无符号数，程序会正确运行，但不会得到我们期望的结果。

#### 2.1.3字面值常量

- 整型字面值

  - 形式
    - 八进制：以0开头
    - 十进制：正常表示
    - 十六进制：以0x开头
- 浮点数字面值（默认double）

  - 形式
    - 小数：`3.14159`、 `0.`、 `.001`
    - 科学计数法：`3.14159E0` 、`0e0` 指数部分用E或e标识。
- 字符和字符串字面值

  - 形式
    - 字符字面值：用单引号括起来，'a'
    - 字符串字面值：用双引号括起来，"abc"
    - 注意：字符串字面值实际上是由常量字符构成的数组，在每个字符串结尾处添加空字符'\0'，**字符串字面值的实际长度比它的内容多1**。
- 转义序列

  - 有两类字符无法直接使用
    - 不可打印的字符
    - 在C++中有特殊含义的字符（引号双引号等）
    - 这些情况下需要用到转义序列（`\t`、`\n`等）
  - 泛化转义类型
    - `\x`后紧跟一个或多个十六进制数字
    - `\`后紧跟1个、2个、3个八进制数字。数字部分表示字符对应的数值。
- 指定字面值的类型
  - 通过添加前缀和后缀，我们可以改变字面值的默认类型。
    - 整型字面值：u或U表示unsigned，l或L表示有long，ll或LL表示longlong。
    - 浮点数字面值：f或F表示float，l或L表示double。
    - 字符和字符串：u表示Unicode16，U表示Unicode32，L表示宽字符，u8表示UTF-8(仅用于字符串字面常量)
- 布尔字面值和指针字面值
  - Ture和False是布尔类型的字面值。
  - nullptr是指针字面值。

### 2.2变量

变量提供一个具名的，可供程序操作的存储空间。

#### 2.2.1变量定义

- 定义形式：类型说明符后接一个或多个以逗号分割的变量名组成的列表，最后以分号结束。定义时可以为一个或多个变量赋值。
  - 例子：`int a;`
  - `int a,b,c=5;`
- 初始值
  - 对象在创建时获得了一个值，我们称其为**初始化**。
  - 定义完成的变量立刻就可以使用，因此在同一条定义语句中，可以用先定义的变量值去初始化后定义的其它变量。
    - 例子：`double price = 109.99, discount = price * 0.16;`
  - **初始化与赋值**：初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代。
- 列表初始化
  - 以**花括号**来来初始化变量的形式被称为列表初始化。
  - 例子：`int units_sold = {0};`以及`int units_sold{0};`
- 默认初始化
  - 在定义变量时没有指定初值，变量被默认初始化。**若内置类型的变量未被显示初始化，则它的值是由定义的位置决定的。定义于任何函数体之外的变量初始化为0；在函数体内部的变量不被初始化(即值未定义)，在拷贝或访问此类值时将引发错误。**因此，**建议初始化每一个内置类型的变量**。

#### 2.2.2变量声明和定义的关系

- 声明：使名字为程序所知，一个文件如果想使用别处定义的名字，则必须包含对那个名字的声明。
- 定义：负责创建与名字关联的实体。
- **变量的声明和定义都规定了变量的类型和名字，但是定义还可以申请存储空间，也可能为变量赋初值**。
- 声明：`extern int i;`如果想声明而非定义一个变量，就在变量名前添加关键字`extern`，而不要显式地初始化变量。
- 显式化的声明即为定义：`extern double pi = 3.14159;`
- **变量能且只能定义一次，但是可以被多次声明**。
- 在变量第一次被使用的附近定义它。

#### 2.2.3标识符

- 由字母、数字和下划线组成，必须以字母或下划线开头。对长度没有限制，对大小写敏感。
- 自定义标识符不能有连续两个下划线，不能以下划线加大些字母开头。定义在函数体外的标识符不能以下划线开头。
- 变量命名规范（用于提高可读性）：
  - 标识符要能体现实际含义。
  - 变量名一般用小写字母。
  - 自定义类名一般以大些字母开头。
  - 多个单词组成应采用下划线分隔，或采用驼峰法。
- 不能使用C++已有的关键字。

#### 2.2.4名字的作用域

- 同一个名字在不同的作用域可能指向不同的实体。作用域通常以花括号{}分隔。
- 外层作用域的变量内层可见，全局作用域的变量全局可见。
- **如果函数有可能用到某全局变量或外层作用域变量，则不宜再定义一个同名的局部变量**。

### 2.3复合类型

#### 2.3.1引用

- 引用为对象起了另外一个名字，定义引用时，程序把引用和它的初始值**绑定**在一起。一旦初始化完成，**引用和它的初始化对象**一直绑定在一起，因此**引用必须初始化**。
- 例子：`int i = 1024; int &r = i;`。一般以`&d`的形式进行，`d`为被引用的变量名。
- 引用类型要与之绑定的对象严格匹配。

#### 2.3.2指针

- 指针是指向另一种类型的符合类型。指针内存放着某个对象的地址。
  - 例子：`int *ip1, *ip2`

- **指针和引用的区别（补充）**
  - 指针本身是一个对象，引用只是对象的别名
  - 指针在其生命周期内可以先后指向不同的对象，引用在初始化完成后，即和它的初始化对象绑定在一起。
  - 指针无需在定义时赋初值，引用必须初始化。

- 获取对象的地址
  - 获取指针内存放着的某个对象的地址需要使用取址符：`&`。 
  - 例子：`int ival = 42; int *p2 = &ival;`
  - 指针类型要与之指向的对象严格匹配。
- 指针值有四种情况：
  - 1.指向一个对象。
  - 2.指向紧邻对象所占空间的下一个位置。
  - 3.空指针，意味着指针没有指向任何对象。
  - 4.无效指针，上述情况之外的其他值。
  - 访问无效指针将印发错误，使用第二第三种指针也是不被允许的。
- 利用指针访问对象
  - 用**解引用符**`*`可以访问指针所指向的对象。
  - 例子：`int ival = 42; int *p = &ival; cout << *p;`
- 空指针
  - 空指针不指向任何对象。
  - 初始化空指针的方式：`int *p1 = nullptr; int *p2 = 0;`
  - **建议初始化所有指针**。

#### 2.3.3理解复合类型的声明

- 定义多个变量
  - `int* p1, p2;`应理解为`int(* p1), p2;`p1是指针，p2是int。`*`仅仅修饰了`p1`而已。
- 指向指针的引用
  - `int *p; int *&r= p;` r为对指针p的引用
- **面对复杂的指针或声明语句，从右向左阅读是比较好弄清楚的方式**。

### 2.4 const限定符

- const的特点是const对象的值无法被改变，因此const对象也必须被初始化。
- 任何对const对象赋值的行为都会报错。只要不改变const对象的内容，其余操作基本都能够被进行。
- 例子：
  -  `int const i = 42;         //编译时初始化`
  - ` int const j = get_size(); //运行时初始化`

#### 2.4.1 const的引用

- 对const的引用简称常量引用，在初始化常量引用时允许用任意表达式作为初始值，允许为一个常量引用绑定非常量的对象、字面值、一般表达式。
- 常量引用不允许通过引用修改其绑定对象的值，但可以通过**其他途径**修改其绑定对象的值，如果被绑定的对象不是const对象的话。（直接修改绑定对象的值，通过其他非常量引用修改等）。

#### 2.4.2 指针和const

- **指向常量的指针**不能用于改变其所指对象的值，但可以指向一个非常量对象。
- ***可以这样理解，常量引用和指向常量的指针，不过是自己认为自己指向了一个常量，所以无法更改其值而已。***

- const指针
  - 常量指针必须被初始化，且初始化完成后其值就不能被改变。

#### 2.4.3 顶层const

- 定义
  - 顶层const（top-level const）：指针本身是个常量
  - 底层const（low-level const）：指针所指的对象是个常量

- 执行对象的拷贝操作时：
  - 1)**顶层const不受影响**；
  - 2)对于底层const而言:
    - 拷入和拷出的对象必须具有**相同的底层const资格**
    - 两个对象的数据类型必须能够转换。一般来说，**非常量可以转换为常量**，反之则不行。
- 用于声明引用的const都是底层const

#### 2.4.4 constexpr 和常量表达式

- 常量表达式：值不会改变并且在编译过程就能得到计算结果的表达式。
- constexpr变量：将变量声明为constexpr类型， 由编译器验证其值是否为常量表达式。
- constexpr定义的指针为顶层const。

### 2.5 处理类型

#### 2.5.1 类型别名

- 类型别名是一个名字，用于指代某种类型
  - 定义：`typedef： typedef double wages;` wages等同于double
  - 别名声明（alias declaration）：`using SI = Sales_item;` 等同于Sales_item

- 在复合类型或常量中，在定义了别名后不要试图替换为本来的样子进行理解会造成错误。

#### 2.5.2 auto类型说明符

- auto：让编译器代替分析表达式所属的类型。**通过初始值推算变量类型**
  - auto会忽略引用和顶层const，保留底层const
  - 在一条语句内定义多个变量时，初始值必须为同一类型

#### 2.5.3 decltype类型指示符

- decltype：在不用表达式的值初始化变量的情况下，从表达式的类型推断出要定义的变量的类型。**编译器分析表达式并得到他的类型，却不实际计算表达式的值**
- 如果表达式的内容是解引用操作，的decltype将得到引用类型。
- decltype的表达式如果有双层括号，则一定是个引用。













## 练习

### 2.1.1节练习

#### 练习2.1

- **类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？**

1）int占2个字节。long占4个字节。long long占8个字节。short占1个字节。其表示范围相应地有所不同。

2）无符号类型表示值大于等于0。带符号类型能表示负数。

3）float占32字节。double占64字节。double表示范围比float大。

<br>

#### 练习2.2

- **计算按揭贷款时，对于利率、本金和付款分别应该选择何种数据类型？说明你的理由。**

利率float。本金和付款为double，因为可能需要更多有效位数。付款方式char。

### 2.1.2节练习

#### 练习2.3

- 读程序写结果。

  ```c++
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;    // 输出32
  std::cout << u - u2 << std::endl;    //输出-32对int占位数得值的模
  
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;    //输出32
  std::cout << i - i2 << std::endl;    //输出-32
  std::cout << i - u << std::endl;    //输出0
  std::cout << u - i << std::endl;    //输出0
  ```

#### 练习2.4

- 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节知道弄明白问题所在。

### 2.1.3节练习

#### 练习2.5

- 指出下述字面值的数据类型并说明每一组内几种字面值的区别。

```c++
(a)'a', L'a', "a", L"a" 
(b)10, 10u, 10L, 10uL, 012, 0xC
(c)3.14, 3.14f, 3.14L
(d)10, 10u, 10., 10e-2

(a)'a'     //char字符型，字面值为a
   L'a'    //long char 宽字符型，字面值为a
   "a"     //string字符串型，字面值为a\0
   L"a"    //long string宽字符串型，字面值为a\0
(b)10      //int整型，10
   10u     //unsigned int无符号整型，10
   10L     //long长整型，10
   10uL    //unsigned long无符号长整型，10
   012     //八进制int，字面值为八进制的12，十进制的10
   0xC     //十六进制int，字面值为十六进制的C，十进制的10
(c)3.14    //double浮点数,3.14
   3.14f   //float浮点数,3.14
   3.14L   //long double拓展精度浮点数,3.14
(d)10      //int整型，10
   10u     //unsigned int无符号整型，10
   10.     //double浮点数,10.
   10e-2   //double浮点数,科学计数法表示，10e-2(0.01)
```

#### 练习2.6

- 下面两组定义是否有区别，如果有，请叙述之：

```c++
int month = 9, day = 7;
int month = 09, day = 07;
//有区别，前一组定义的是day是十进制，后一组day定义的是八进制。
```

#### 练习2.7

- 下述字面值表达何种含义？它们各自的数据类型是什么？

```c++
(a)"Who goes with F\145rgus?\012"
(b)3.14e1L            (c)1024f        (d)3.14L

(a)"Who goes with Fergus?"加一个换行  string字符串  //\145为八进制下的e，\12为换行符
(b)31.4 long double 拓展精度浮点数
(c)1024 float 浮点数
(d)3.14 long double 拓展精度浮点数
```

#### 练习2.8

- 请利用转义序列编写一段程序，要求先输出2M，然后转到新一行。修改程序使其先输出2，然后输出制表符，再输出M，最后转到新一行。

```c++
int main()
{
	std::cout << "2\115\n" << std::endl;
	std::cout << "2\t\115\n" << std::endl;
	return 0;
}
```

### 2.2.1节练习

#### 练习2.9

- 解释下列定义的含义。对于非法的定义，请说明在何处并将其改正。

```c++
(a) std::cin >> int input_value;                    (b) int i = { 3.14 };
(c) double salary = wage = 9999.99;                 (d) int i = 3.14;

(a)获取int输入。非法。变量需先定义，后使用。 改为：
    int input_value{0};
    std::cin >> input_value;
(b)令整型数i初始化为 3.14 。非法。使用float进行列表初始化int会丢失数据，因此会被编译器拒绝。改为：
    int i = 3.14;
(c)初始化salary wage 为9999.99。非法。这段代码应解释为，将9999.99赋值给wage，并将wage的值作为初值，对salary进行初始化。而wage并未被定义，未被初始化。改为：
    double wage = 0;
    double salary = wage = 9999.99;
(d)令整型数i初始化为 3.14 。合法。但会自动转换，丢弃小数点后的信息。
```

#### 练习2.10

- 下列变量的初值分别是什么？

```c++
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
global_str的初值为空串。global_int的初值为0。local_int和local_str在main函数内，则不被初始化，初值为未定义。
```

### 2.2.2节练习

#### 练习2.11

- 指出下面的语句是声明还是定义：

```c++
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;

(a)显示的声明即为定义，赋初始值的行为抵消了extern的声明作用。
(b)声明并定义。
(c)声明。
```

### 2.2.3节练习

#### 练习2.12

- 请指出下面的名字中哪些是非法的？

```c++
(a) int double = 3.14;    //非法。使用了C++已有的关键字
(b) int _;                //合法
(c) int catch-22;         //非法。标识符只能由数字，字母，下划线组成
(d) int 1_or_2 = 1;       //非法。标识符必须以下划线或字母开头
(e) double Double = 3.14; //合法
```

### 2.2.4节练习

#### 练习2.13

- 下面程序中`j`的值是多少？

```c++
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

100。局部变量`i`覆盖了全局变量`i`。

#### 练习2.14

- 下面的程序合法吗？如果合法，它将输出什么？

```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; i++)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

合法，输出`100 45`。

### 2.3.1节练习

#### 练习2.15

- 下面的哪个定义是不合法的？为什么？

```c++
(a) int ival = 1.01;      //合法，但小数点部分会被舍弃
(b) int &rvall = 1.01;    //不合法，引用类型的初始值必须是一个对象
(c) int &rval2 = ival;    //合法
(d) int &rval3;           //不合法，引用类型必须有初始值
```

#### 练习2.16

- 考查下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操做？

```c++
int i = 0, &r1 = i;
double d = 0, &r2 = d;
(a) r2 = 3.14159;    //合法，给r2(d)赋值为3.14159
(b) r2 =r1;          //合法，给r2(d)赋值r1(i)的值0
(c) i =r2;           //合法，给i赋值r2(d)的值0
(d) r1 = d;          //合法，给r1(i)赋值d的值0
```

#### 练习2.17

- 执行下面的代码段将输出什么结果？

```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

`10 10`

### 2.3.2节练习

#### 练习2.18

- 编写代码分别更改指针的值以及指针所指向对象的值。

```c++
int main()
{
	int i = 100, j = 200, *p = &i;
	p = &j;    //更改指针的值
	*p = 100;  //更改指针所指向对象的值
	return 0;
}
```

#### 练习2.19

- 说明指针和引用的主要区别。

```c++
- 指针本身是一个对象，引用只是对象的别名
- 指针在其生命周期内可以先后指向不同的对象，引用在初始化完成后，即和它的初始化对象绑定在一起。
- 指针无需在定义时赋初值，引用必须初始化。
```

#### 练习2.20

- 请叙述下面这段代码的作用。

```c++
int i = 42;
int *p1 = &i;     // 初始化指针p1指向i
*p1 = *p1 * *p1;  // 将指针p1指向的对象值变为它的平方，即p1现在所指的对象值为1764。
```

#### 练习2.21

- 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？

```c++
int i = 0;
(a) double* dp = &i;    //非法。类型不匹配
(b) int *ip = i;        //非法。指针指向的是变量的地址，不是变量本身。需用取址符&取其地址。
(c) int *p = &i;        //合法
```

#### 练习2.22

- 假设p是一个int型指针，请说明下述代码的含义。

```c++
if (p)    // 判断指针是否为空指针
if (*p)   // 判断指针指向的对象的值是否为0
```

#### 练习2.23

- 给定指针p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能知道。因为指针可以任意指向一个地址，即使有时候可能看似正确，但依然不能保证它是无害的，指针的意义就是它的值是内存地址，它将按它指向的类型的信息来解释那片空间。而那片空间是否合法，是由程序员保证，而不是指针本身。

#### 练习2.24

- 在下面这段代码中为什么p合法而lp不合法？

```c++
int i = 42;         void *p = &i;         long *lp = &i;
```

`void*`指针可以指向任何值，因此`p`合法。`long `为`long int`类型，与`i`的`int`类型不匹配。故非法。

### 2.3.3练习

#### 练习2.25

- 说明下列变量的类型和值。

```c++
(a) int* ip,i, &r = i;    //ip，int指针，值不确定。i，int指针，值不确定。r，int引用，值不确定。
(b) int i, *ip = 0;       //i int，值不确定。 ip，int指针，空指针。
(c) int* ip, ip2;         //ip int指针，值不确定。ip2，int，值不确定。
```

### 2.4节练习

#### 练习2.26

- 下面哪些句子是合法的？如果有不合法的句子，请说明为什么？

```c++
(a) const int buf;         //不合法，未初始化
(b) int cnt = 0;           //合法
(c) const int sz = cnt;    //合法
(d) ++cnt; ++sz;           //后一个不合法，const不允许被赋值（++内含赋值）
```

### 2.4.2节练习

#### 练习2.27

- 下面的哪些初始化是合法的？请说明原因。

```c++
(a) int i = -1, &r =0;            //不合法，引用必须绑定对象
(b) int *const p2 = &i2;          //如果i2是int则合法
(c) const int i = -1, &r =0;      //合法。常量引用允许绑定任何值
(d) const int *const p3 = &i2;    //如果i2是const int则合法
(e) const int *p1 = &i2;          //如果i2是int则合法
(f) const int &const r2;          //不合法，引用必须先初始化
(g) const int i2 = i, &r = i;     //如果i是int则合法

```

#### 练习2.28

- 说明下面的这些定义是什么意思，挑出其中不合法的。

```c++
(a) int i, *const cp;         //定义int i，后半句不合法，常量必须被初始化
(b) int *p1, *const p2;       //定义int指针 p1，后半句不合法，常量必须被初始化
(c) const int ic, &r = ic;    //不合法，常量必须被初始化。后半句合法，对int常量ic的引用
(d) const int *const p3;      //不合法，常量必须被初始化
(e) const int *p;             //合法，定义指向int常量的指针p
```

#### 练习2.29

- 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。

```c++
(a) i = ic;      //合法，将int常量ic的值赋值给int i
(b) p1 = p3;     //不合法，指针类型不同
(c) p1 = &ic;    //不合法，普通指针p1无法指向常量
(d) p3 = &ic;    //不合法，p3是常量指针，无法改变其值
(e) p2 = p1;     //不合法，p2是常量指针，无法改变其值
(f) ic = *p3;    //不非法，ic是常量int，无法改变其值
```

### 2.4.3节练习

#### 练习2.30

- 对于下面的这些语句，请说明对象被申明成了顶层const还是底层const？

```c++
const int v2 = 0;        int v1 = v2;             //v2顶层const
int *p1 = &v1, &r1 = v1;                          
const int *p2 = &v2, *const p3 = &i, &r2 = v2;    //p2底层const，p3两者都有，r2底层const
```

#### 练习2.31

- 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。

```c++
r1 = v2;    //合法，拷贝时顶层const无影响
p1 = p2;    //不合法，底层const只能拷贝给拥有同样底层const
p2 = p1;    //合法，int*可以转换成const int*
p1 = p3;    //不合法，底层const只能拷贝给拥有同样底层const
p2 =p3;     //合法，拥有同样底层const
```

### 2.4.4节练习

#### 练习2.32

- 下面的代码是否合法？如果非法，请设法将其修改正确。

```c++
int null = 0, *p = null;
```

不合法，null是个整型，p是个int 指针，二者虽然字面值是一样的，均为0，但类型不同，不可混用。改为：

```c++
int null = 0, *p = nullptr;
```

### 2.5.2节练习

#### 练习2.33

- 利用本节定义的变量，判断下列语句的运行结果。

```c++
a = 42; b = 42; c = 42;    //成功赋值
d = 42; e = 42; g = 42;    //赋值失败
```

#### 练习2.34

- 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例知道你明白错在何处为止。

```c++
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
```

#### 练习2.35

- 判断下列定义推断出的类型是什么，然后编写程序进行验证。

```c++
const int i  = 42;             //const int整型常量
auto j = i;                    //int整型
const auto &k = i;             //int整型的常量引用
auto *p = &i;                  //指向常量整型的指针
const auto j2 = i, &k2 = i;    //j2 int整型常量，k2 int整型的常量引用

Code:
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
```

### 2.5.3节练习

#### 练习2.36

- 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。

```c++
int a =3, b =4;
decltype(a) c = a;
decltype((b)) d =a;
++c;
++d;    //d是对a的引用，自增使得a和d均加1
//a,4,int b,4,int c,4,int, d,4,int&
```

#### 练习2.37

- 赋值时会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果`i`是`int`，这表达式`i=x`的类型是`int&`。根据这一特点，请指出下面的代码中的每一个变量的类型和值。

```c++
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d =a; //decltype只推断类型，没有进行赋值操作

//a,int,3 b,int,4 c,int,3 d,int&,3
```

#### 练习2.38

- 说明由decltype指定类型和由auto指定类型那个有何区别。请举出一个例子，decltype指定的类型和auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。

```c++
//auto必须初始化，decltype不用。auto的结果与表达形式无关，decltype结果类型与表达式形式有关
 
//decltype指定的类型与auto指定的类型一样：auto (x)=a; decltype(x)=a;
 
//decltype指定的类型与auto指定的类型不一样：auto (x)=a; decltype((x))=a;
 
int i = 0, &r = i;
// same
auto a = i;
decltype(i) b = i;
// different
auto c = r;
decltype(r) d = r;

```

### 2.6.1节练习

#### 练习2.39

- 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关信息，以后可能会用。

```c++
struct Foo { /* 此处为空 */} //注意：没有分号
int main()
{
    return 0;
}
//error C2628: “Foo”后面接“int”是非法的(是否忘记了“;”?)
```

#### 练习2.40

- 根据自己的理解写出Sales_data类，最好与书中的例子区别。

```c++
struct Sale_data {
	std::string bookno;
	std::string bookname;
	double price = 0.0;
	int num = 1;
};
int main() {
	return 0;
}
```

### 2.6.2节练习

#### 练习2.41

- 使用你自己的Sales_item类重写1.5.1节、1.5.2节和1.6节的练习。眼下先把Sales_data类的定义和main函数放在同一个文件里。

1.5.1

```c++
#include <iostream>
#include <string>
 
struct Sale_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;
 
    return 0;
}
```

1.5.2

```c++
#include <iostream>
#include <string>
 
struct Sale_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
 
int main()
{
    Sale_data book1, book2;
    double price1, price2;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.revenue = book1.units_sold * price1;
    book2.revenue = book2.units_sold * price2;
 
    if (book1.bookNo == book2.bookNo) {
        unsigned totalCnt = book1.units_sold + book2.units_sold;
        double totalRevenue = book1.revenue + book2.revenue;
        std::cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
 
        return 0;
    }
    else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;  // indicate failure
    }
}
```

1.6

```c++
#include <iostream>
#include <string>
 
struct Sale_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
 
int main()
{
    Sale_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.revenue = total.units_sold * totalPrice;
 
        Sale_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.revenue = trans.units_sold * transPrice;
 
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;
 
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
 
        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
 
        return 0;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}

```

### 2.6.3节练习

#### 练习2.42

- 根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节练习。

Sales_data.h

```c++
#include <iostream>
#include <string>
 
// own Sales_data
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
 
    void CalcRevenue(double price);
    double CalcAveragePrice();
    void SetData(Sales_data data);
    void AddData(Sales_data data);
    void Print();
};
 
void Sales_data::CalcRevenue(double price)
{
    revenue = units_sold * price;
}
 
void Sales_data::SetData(Sales_data data)
{
    bookNo = data.bookNo;
    units_sold = data.units_sold;
    revenue = data.revenue;
}
 
void Sales_data::AddData(Sales_data data)
{
    if (bookNo != data.bookNo) return;
    units_sold += data.units_sold;
    revenue += data.revenue;
}
 
double Sales_data::CalcAveragePrice()
{
    if (units_sold != 0)
        return revenue / units_sold;
    else
        return 0.0;
}
 
void Sales_data::Print()
{
    std::cout << bookNo << " " << units_sold << " " << revenue << " ";
    double averagePrice = CalcAveragePrice();
    if (averagePrice != 0.0)
        std::cout << averagePrice << std::endl;
    else
        std::cout << "(no sales)" << std::endl;
}

```

1.5.1

```c++
#include <iostream>
 
#include "2.42-Sales_data.h"
 
int main()
{
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.CalcRevenue(price);
    book.Print();
 
    return 0;
}

```

1.5.2

```c++
#include <iostream>
 
#include "2.42-Sales_data.h"
 
int main()
{
    Sales_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.CalcRevenue(totalPrice);
 
        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.CalcRevenue(transPrice);
 
            if (total.bookNo == trans.bookNo) {
                total.AddData(trans);
            }
            else {
                total.Print();
                total.SetData(trans);
            }
        }
 
        total.Print();
 
        return 0;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
}

```

1.6

```c++
#include <iostream>
 
#include "2.42-Sales_data.h"
 
int main()
{
    Sales_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.CalcRevenue(totalPrice);
 
        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.CalcRevenue(transPrice);
 
            if (total.bookNo == trans.bookNo) {
                total.AddData(trans);
            }
            else {
                total.Print();
                total.SetData(trans);
            }
        }
 
        total.Print();
 
        return 0;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
}

```

