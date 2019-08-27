## chapter14 重载运算与类型转换

[TOC]

## 练习

### 14.1 节练习

#### 练习14.1

- **在什么情况下重载的运算符和内置运算符有所区别？在什么情况下重载的运算符又与内置运算符一样？**

相同点：重载运算符与内置运算符的优先级和结合律是一致的。

不同点：可以直接调用重载运算符。重载运算符必须是类的成员，或至少包含一个类类型的参数。部分重载运算符无法保留求职顺序或短路求值属性，因此不适合被重载。

#### 练习14.2

- **为Sales_data类编写重载的输入、输出、加法和复合赋值运算符。**

```c++
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
// 已声明为友元函数，因此可以调用Sales_data类的private成员
istream& operator>>(istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

ostream& operator<<(ostream &vos, Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_prive();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data temp(lhs);
	temp += rhs;
	return temp;
}
```

#### 练习14.3

- **string和vector都定义了重载的`==`以比较各自的对象，假设svec1和svec2是存放string的vector，确定在下面的表达式中分别使用了哪个版本的`==`？**

```c++
(a) "cobble" == "stone"    (b) svec1[0] == svec2[0]
(c) svec1 == svec2         (d) "sevc1[0] == "stone"

(a) const char    // C++中被""包含的不是string，而是常量字符串
(b) string
(c) vector
(d) string
```

#### 练习14.4

- **如何确定下列运算符是否应该是类的成员？**

```c++
(a) % (b) %= (c) ++ (d) -> (e) << (f) && (g) == (h) ()
    否    是      是     是     否      否     否      是
// a f g对称，因此不该是成员。 d h 必须是成员。  b c改变对象状态，应该是成员   e 输入输出必须是非成员
```

#### 练习14.5

- **在7.5.1节的练习7.40中，编写了下列类中某一个的框架，请问在这个类中应该定义重载的运算符吗？如果是，请写出来。**

Tree  可以重载==。

### 14.2.1 节练习

#### 练习14.6

- **为你的Sales_data类定义输出运算符。**

见练习14.2。

#### 练习14.7

- **你在13.5节的练习中曾经编写了一个String类，为它定义一个输出运算符。**

```c++
// 此处略去了类内的友元声明
std::ostream& operator<<(std::ostream &os, const String  &str) {
	for (char* p = str.elements; p != str.end; p++)
		os << *p;
	return os;
}
```

#### 练习14.8

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，为它定义一个输出运算符。**

```c++
#include <iostream>
#include <string>
class Tree
{
	friend std::ostream& operator<<(std::ostream& os, const Tree& item);
private:
	std::string Name;
	unsigned Age = 0;
	double Height = 0;
public:
	Tree() = default;
	Tree(const std::string &n, unsigned a, double h)
		: Name(n), Age(a), Height(h) {}
};
std::ostream& operator<<(std::ostream& os, const Tree& item) {
	os << item.Name << " " << item.Age << " " << item.Height;
	return os;
}
```

### 14.2.2 节练习

#### 练习14.9

- **为你的Sales_data类定义输入运算符。**

见练习14.2。

#### 练习14.10

- **对于Sales_data的输入运算符来说如果给定了下面的输入将发生什么情况。**

```c++
(a) 0-201-99999-9 10 24.95    (b) 10 24.95 0-210-99999-9
```

(a) 正确获取输入，生成对应的类成员。

(b) 获取输入成功，但`.95`会被作为浮点数存储，因此最后的`0-210-99999-9`将被忽略，但 能够从输入中生成一个Sales_data类，其成员分别为`bookNo: 10, units_sold: 24, revenue: 0.95`。

#### 练习14.11

- **下面的Sales_data输入运算符存在错误吗？如果有，请指出来。对于这个输入运算符如果仍然给定上个练习的输入将发生什么情况。**

```c++
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```

没有输入错误的检查。当输入不规范，如无法转化为成员变量的输入时，将无法返回合法的结果。

进行上个练习的输入后得到的情况是一致的。

#### 练习14.12

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，为它定义一个输入运算符并确保该运算符可以处理输入错误。**

```c++
#include <iostream>
#include <string>
class Tree
{
	friend std::ostream& operator<<(std::ostream& os, const Tree& item);
	friend std::istream& operator>>(std::istream& is, Tree& item);
private:
	std::string Name;
	unsigned Age = 0;
	double Height = 0;
public:
	Tree() = default;
	Tree(const std::string &n, unsigned a, double h)
		: Name(n), Age(a), Height(h) {}
};
std::ostream& operator<<(std::ostream& os, const Tree& item) {
	os << item.Name << " " << item.Age << " " << item.Height;
	return os;
}
std::istream& operator>>(std::istream& is, Tree& item) {
	is >> item.Name >> item.Age >> item.Height;
	if (!is)
		item = Tree();
	return is;
}
```

### 14.3 节练习

#### 练习14.13

- **你认为Sales_data类还应该支持哪些其他算术运算符？如果有的话，请给出它们的定义。**

无。

#### 练习14.14

- **你觉得为什么调用operator+=来定义operator+比其他方法更有效？**

简洁高效，可读性强，不复写代码。

#### 练习14.15

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有其他算术类型吗？如果是，请实现它们；如果不是，解释原因。**

可以拥有==和!=。

```c++
bool operator==(const Tree &lhs, const Tree &rhs) {
	return (lhs.Name == rhs.Name && lhs.Age == rhs.Age && lhs.Height && rhs.Height);
}
bool operator!=(const Tree &lhs, const Tree &rhs) {
	return !(lhs == rhs);
}
// 已添加友元
```

### 14.3.1 节练习

#### 练习14.16

- **为你的StrBlob类、StrBlobPtr类、StrVec类和String类分别定义相等和不相等运算符。**

略。

#### 练习14.17

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有相等运算符吗？如果是，请实现它；如果不是，解释原因。**

应该有，见练习14.15。

### 14.3.2 节练习

#### 练习14.18

- **为你的StrBlob类、StrBlobPtr类、StrVec类、String类定义关系运算符。**

略。

#### 练习14.19

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有关系运算符吗?如果是，请实现它；如果不是，解释原因。**

不，因为它含有Name, Age和Height三个参数，不存在一个逻辑可靠的<定义。

### 14.4 节练习

#### 练习14.20

- **为你的Sales_data类定义加法和复合赋值运算符。**

见练习14.2。

#### 练习14.21

- **编写Sales_data类的+和+=运算符，使得+执行实际的加法操作而+=调用+。相比于之前的定义，本题的定义有何缺点？试讨论之。**

```c++
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}
// 已声明为友元函数，因此可以调用Sales_data类的private成员

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data temp(lhs);
    temp.units_sold += rhs.units_sold;
	temp.revenue += rhs.revenue;
	return temp;
}
```

因为在这个情况下， `+=`运算符必须创建一个临时对象满足`+`运算符的两个形参的需求，多创建了一个临时对象。

#### 练习14.22

- **定义赋值运算符的一个新版本，使得我们能把一个表示ISBN的string赋值给一个Sales_data对象。**

```c++
Sales_data& Sales_data::operator=( const string &str ){
    bookNo = str;
    return *this;
}
```

#### 练习14.23

- **为你的StrVec类定义一个initializer_list赋值运算符。**

略了，书上500页已经有了。

#### 练习14.24

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有拷贝赋值和移动赋值运算符吗？如果是，请实现它们。**

不必含有拷贝赋值和移动赋值运算符。因为其三个成员都是内置类，已能满足要求。

#### 练习14.25

- **上题的这个类还需要定义其他赋值运算符吗？如果是，请实现它们；同时说明运算对象应该是什么类型并解释原因。**

    不必。

### 14.5 节练习

#### 练习14.26

- **为你的StrBlob类、StrBlobPtr类，StrVec类和String类定义下标运算符。**

略。

### 14.6 节练习

#### 练习14.27

- **为你的StrBlobPtr类添加递增和递减运算符。**

略。

#### 练习14.28

- **为你的StrBlobPtr类添加加法和减法运算符，使其可以实现指针的算术运算。**

略。

#### 练习14.29

- **为什么不定义const版本的递增和递减运算符？**

因为不管是递增还是递减版本的运算符，均会对对象本身造成改变，因此没必要定义const版本的。

### 14.7 节练习

#### 练习14.30

- **为你的StrBlob类和在12.1.6节练习12.22中定义的ConstStrBlobPtr类分别添加解引用运算符和箭头运算符。注意：因为ConstStrBlobPtr的数据成员指向const vector，所以ConstStrBlobPtr中的运算符必须返回常量引用。**

略。

#### 练习14.31

- **我们的StrBlobPtr类没有定义拷贝构造函数、赋值运算符和析构函数，为什么？**

对于StrBlobPtr类，它的数据成员有两个，分别是weak_ptr<vector<string>>和size_t类型的，前者定义了自己的拷贝构造函数、赋值运算符和析构函数，后者是内置类型，因此默认的拷贝语义即可，无须为StrBlobPtr定义拷贝构造函数、赋值运算符和析构函数。

#### 练习14.32

- **定义一个类令其含有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符。**

```c++
class MyClass{
public:
	std::string* operator->() const{
        return ptr;}
private:
	StrBlobPtr *ptr;
}
```

### 14.8 节练习

#### 练习14.33

- **一个重载的函数调用运算符应该接受几个运算对象？**

依据需求而定，可以是0个以及任何正整数个。

#### 练习14.34

- **定义一个函数对象类，令其执行`if-then-else`的操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参的值，如果不成功返回第三个形参的值。**

```c++
class MyClass {
	int operator()(bool i, int j, int k) {
		i ? j : k;
	}
}
```

#### 练习14.35

- **编写一个类似PrintString的类，令其从istream中读取一行输入，然后返回一个表示我们所读内容的string。如果读取失败，返回空string。**

```c++
#include <iostream>
#include <string>
class InputString {
public:
	InputString(std::istream &i = std::cin) : is(i) {}
	std::string operator()() {
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream &is;
};
```

#### 练习14.36

- **使用前一个练习定义的类读取标准输入，将每一行保存为vector的一个元素。**

```c++
#include <iostream>
#include <string>
#include <vector>
class InputString {
public:
	InputString(std::istream &i = std::cin) : is(i) {}
	std::string operator()() {
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream &is;
};
int main() {
	InputString i;
	std::vector<std::string> v;
	for (std::string temp; !(temp = i()).empty(); v.push_back(temp))
		for (auto str : v) std::cout << str << std::endl;
}
```

#### 练习14.37

- **编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。**

```c++
#include <iostream>
#include <vector>
#include <algorithm>
class IsEqual {
	int value;
public:
	IsEqual(int i) : value(i) {}
	bool operator()(int i) {
		return i == value;
	}
};
int main() {
	std::vector<int> v = { 1,2,3,3,3,4,5 };
	std::replace_if(v.begin(), v.end(), IsEqual(3), 5);
	for (int i : v) std::cout << i << " ";
}
```

### 14.8.1 节练习

#### 练习14.38

- **编写一个类令其检查某个给定的string对象的长度是否与一个阀值相等。使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个、长度为2的单词有多少个、……、长度为10的单词又有多少个。**

```c++
class checklength {
	size_t sz;
public:
	checklength(size_t n) : sz(n) {}
	bool operator()(const string &str) {
		return str.size() == sz;
	}
}
//主函数略
```

#### 练习14.39

- **修改上一题的程序令其报告长度在1至9之间的单词有多少个、长度在10以上的单词又有多少个。**

```c++
//主函数部分修改，以count统计长度在1-9之间的单词有多少个等。或修改类为边界统计形式
class IsInRange(){
    size_t max,min;
    public:
    IsInRange(size_t i, size_t j) : min(i), max(j) {}
    bool operator()(const string& str){
        return str.size() >= min && str.size() <= max;
    }
}
//主函数略
```

#### 练习14.40

- **重新编写10.3.2节的biggies函数，使用函数对象替换其中的lambda表达式。**

略。

#### 练习14.41

- **你认为C++11新标准为什么要增加lambda？对于你自己来说，什么情况下会使用lambda，什么情况下会使用类？**

因为lambda很方便，无需具体实现一个函数对象或函数，也无需为其命名等。

在该函数使用不频繁的情况下，可以使用lambda以图便利。常使用的情况下，或实现较为复杂的话，应当将其实现为函数对象来方便调用。

### 14.8.2 节练习

#### 练习14.42

- **使用标准库函数对象及适配器定义一条表达式，令其**
    - **(a)统计大于1024的值有多少个。**
    - **(b)找到第一个不等于pooh的字符串。**
    - **(c)将所有的值乘以2.**

```c++
count_if(vec.begin(), vec.end(), bind(greater<int>(), placeholders::_1, 1024));
find_if(vec.begin(), vec.end(), bind(not_equal_to<string>(), placeholders::_1, "pooh"));
transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), placeholders::_1, 2));
```

#### 练习14.43

- **使用标准库函数对象判断一个给定的int值是否能被int容器中的所有元素整除。**

```c++
bool divideByAll(vector<int> &ivec, int dividend)
{
	return count_if(ivec.begin(), ivec.end(), bindlst(modulus<int>, dividend)) == 0;
}
```

### 14.8.3 节练习

#### 练习14.44

- **编写一个简单的桌面计算器使其能处理二元运算。**

```c++
#include <functional>..
map<string, function<int(int, int)>> binOps = {
	{"+", plus<int>()},
	{"-", minus<int>()},
	{"*", multiplies<int>()},
	{"/", divides<int>()},
	{"%", modulus<int>()}
}
```

### 14.9.1 节练习

#### 练习14.45

- **编写类型转换运算符将一个Sales_data对象分别转换成string和double，你认为这些运算符的返回值应该是什么？**

string：bookNo。

double：revenue。

#### 练习14.46

- **你认为应该为Sales_data类定义上面两种类型转换运算符吗？应该把它们声明成explicit的吗？为什么？**

应该不要，主要是这样的信息并不是很实用，且容易导致未知的结果。如以一个Sales_data对象去加一个string对象等。因此如果要定义它们，则一定要声明成explicit的。

#### 练习14.47

- **说明下面这两个类型转换运算符的区别。**

```c++
struct Integral {
	operator const int();
	operator int() const;
};
```

第一个我认为会返回const int。github上说无意义，编译器会忽略它（？）。

第二个将返回整型，但不会改变类对象的内容。

#### 练习14.48

- **你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有bool的类型转换运算符吗？如果是，解释原因并说明该运算符是否应该是explicit的；如果不是，也请解释原因。**

应该有，因为我们可以依靠bool的类型转换运算符来判断类对象是否为空。

应该是explicit的，因为我们仅希望将其用来作为判断使用。

#### 练习14.49

- **为上一题提到的类定义一个转换目标是bool的类型转换运算符，先不用在意这么做是否应该。**

```c++
	explicit operator bool() const {
		return !Name.empty() && Age != 0 && Height != 0;
	}
```

### 14.9.2 节练习

#### 练习14.50

- **在初始化ex1和ex2的过程中，可能用到哪些类类型的转换序列呢？说明初始化是否正确并解释原因。**

- ```c++
    struct LongDouble {
    	LongDouble(double = 0.0);
    	operator double();
    	operator float();
    };
    LongDouble ldObj;
    int ex1 = ldObj;
    float ex2 ldObj;
    ```

ex1因为类型与可转换类型不一致，因此既可以通过double也可以通过float进行二次转换达成int。因此具有二义性，初始化不正确。

ex1具有匹配的类型转换运算符，因此会直接调用float的类型转换符，正确地完成初始化。

#### 练习14.51

- **在调用calc的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数是如何选拔出来的。**

- ```c++
    void calc(int);
    void calc(LongDouble);
    double dval;
    calc(dval);    // 哪个calc？
    转换匹配顺序:
    1 精确匹配
    2 常量版本
    3 类型提升
    4 算数转换或指针转换           *//所以调用calc(int)最佳*
    5 类类型转换
    ```

1. double->int
2. double->LongDouble

此处会调用`void calc(int)`函数。因为double->int是算术类型转换，而转换为LongDouble是用户自定义的类类型转换，因此优先级较低，故会调用前者。转换匹配顺序如上。

### 14.9.3 节练习

#### 练习14.52

- **在下面的加法表达式中分别选用了哪个operator？列出候选函数、可行函数及为每个可行函数的实参执行的类型转换。**

- ```c++
    struct longDouble {
    	//用于演示的成员operator+; 在通常情况下+是个非成员
    	longDouble operator+(const SmallInt&);
    	//其他成员与14.9.2节一致
    };
    longDouble operator+(longDouble&, double);
    SmallInt si;
    longDouble ld;
    ld = si + ld;
    ld = ld + si;
    ```

`ld = si + ld`是非法的。首先两者类型无法互相转换，因此无法通过重载的+运算符来实现。其次，SmallInt可以转换为int，而LongDouble可以转换为float和double。而int可以与float以及double执行内置加法运算，因此将导致二义性。

`ld = ld + si`是可行的。因为si在ld的右侧，这就导致了LongDouble的成员函数可以执行。另外，其非成员函数也可以执行，但需要经过一重转换（SmallInt->double），因此会执行其成员函数。

#### 练习14.53

- **假设我们已经定义了如第522页所示的SmallInt，判断下面的加法表达式是否合法。如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法？**

- ```c++
    SamllInt sl;
    double d = s1 + 3.14;
    ```

不合法。因为s1可以转换为int，执行内置加法（int,double），可以加将3.14转化为SmallInt类，执行内置加法。都只执行了一层转换，因此具有相同优先级，导致了二义性。

修改为`double d = s1 + SmallInt(3.14);`