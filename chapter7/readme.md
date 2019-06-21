## chapter7 类

[TOC]

## 练习

### 7.1.1 节练习

#### 练习7.1

- **使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程序编写一个新版本。**

```c++
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue){
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo)
				total.AddData(trans);
			else {
				total.Print();
				total = trans;
			}
		}
		total.Print();
	}else {
		cout << "No data?!" << endl;
		return -1;
	}return 0;
}
```

### 7.1.2 节练习

#### 练习7.2

- **曾在2.6.2节的练习（第76页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。**

```c++
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &rhs){
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
}
```

#### 练习7.3

- **修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。**

```c++
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				total.Print();
				total = trans;
			}
		}
		total.Print();
	}
	else {
		cout << "No data?!" << endl;
		return -1;
	}return 0;
}
```

#### 练习7.4

- **编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。**

```c++
#include <string>
using namespace std;
struct Peason{
	string Name;
	string Address;
};
```

#### 练习7.5

- **在你的Person类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是const的呢？解释原因。**

```c++
#include <string>
using namespace std;
struct Peason{
	string name;
	string address;
	string get_name() const { return name; }
	string get_address() const { return address; }
};
```

应该是const的，因为它们不会对类内内容进行任何修改，因此被定义为const成员函数更安全。

### 7.1.3节练习

#### 练习7.6

- **对于函数add、read、和print，定义你自己的版本。**

```c++
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " "<< item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
```

#### 练习7.7

- **使用这些新函数重写7.1.2节（第233页）练习中的交易处理程序。**

```c++
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cout << "No data?!" << endl;
		return -1;
	}return 0;
}
```

#### 练习7.8

- **为什么read函数将其Sales_data参数定义成普通的引用，而print函数将其参数定义成常量引用？**

因为read函数使用时，需要将输入流中获取到的数据复制给引用的对象，会改变其值。而print函数只需要获取其中的参数值，而不会对其有任何的修改。

会修改时，使用引用，获取修改权限；不修改时，使用常量引用，保护变量。

#### 练习7.9

- **对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。**

```c++
istream &read(istream &is, Peason &item) {
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, const Peason &item) {
	os << item.name << " " << item.address;
	return os;
}
```

#### 练习7.10

- **在下面这条if语句中，条件部分的作用是什么？**

```c++
if (read(read(cin, data1), data2))
```

因为read函数返回的类型是引用，可以返回结果可以作为实参被read函数继续使用。连续读取两个对象data1, data2。如果读取成功，条件判断正确， 否则条件判断错误。

### 7.1.4节练习

#### 练习7.11

- **在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。**

```c++
#include <iostream>
#include <string>
using namespace std;
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) { }
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { }
	Sales_data(istream &is);
    /*...*/
}
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
Sales_data::Sales_data(istream &is) { read(is, *this); }
////////////////main()
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data first;
	Sales_data second("123");
	Sales_data third("1234", 3, 2.22);
	Sales_data forth(cin);
	print(print(print(print(cout, first), second), third), forth);
}
```

#### 练习7.12

- **把只接受一个istream 作为参数的构造定义函数移到类的内部。**

```c++
#include <iostream>
#include <string>
using namespace std;
struct Sales_data;
istream &read(istream &is, Sales_data &item);

// own Sales_data
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	Sales_data(istream &is) { read(is, *this); }
}
//将Sales_data和read函数提前声明。
```

#### 练习7.13

- **使用istream构造函数重写第229页的程序。**

```c++
#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data total(cin);
	if (cin) {
		Sales_data trans(cin);
		do {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		} while (read(cin, trans));    //利用do while循环来完成构造函数后的第一次比较
		print(cout, total) << endl;
	}
	else {
		cout << "No data?!" << endl;
		return -1;
	}return 0;
}
```

#### 练习7.14

- **编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。**

```c++
Sales_data(): bookNo("123"), unsigned(0), revenue(0.0) {}
```

#### 练习7.15

- **为你的 Person 类添加正确的构造函数。**

```c++
#include <iostream>
#include <string>
using namespace std;
struct Peason{
	string name;
	string address;
	Peason() = default;
	Peason(const string s1, const string s2) :name(s1), address(s2) { }
	Peason(istream &is);
}
istream &read(istream &is, Peason &item) {
	is >> item.name >> item.address;
	return is;
}
Peason::Peason(istream &is) {
	read(is, *this);
}
```

### 7.2节练习

#### 练习7.16

- **在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？**

在类的定义中对于访问说明符出现的位置和次数没有限制。

一般来说，构造函数和部分成员函数作为接口程序，应该定义在public说明符之后。而数据成员和作为实现部分的函数则应该被定义在private说明符之后。

#### 练习7.17

- **使用class和struct时有区别吗？如果有，是什么？**

有区别。两者的默认访问权限不同。class关键字下，定义在第一个访问说明符之前的成员是private的，而在struct关键字下，定义在第一个访问说明符之前的成员则是public的。

#### 练习7.18

- **封装是何含义？它有什么用处？**

封装的含义是隐藏了内部的实现细节，仅仅将接口提供给其他函数调用或访问。

封装的优点，一是确保用户代码不会无意间破坏封装对象的状态。二是被封装的类的具体实现细节可以随时改变，而无需调整用户级别的代码。

#### 练习7.19

- **在你的Person类中，你将把哪些成员声明成public的？哪些声明成private的？解释你这样做的原因。**

将数据成员声明成private，避免数据被外部修改。将成员函数声明成public，供外部调用。

### 7.2.1节练习

#### 练习7.20

- **友元在什么时候有用？请分别列举出使用友元的利弊。**

友元在有其他类或函数访问它的非公有成员时，可以令其获得访问的权限。但可能破坏类的封装。

#### 练习7.21

- **修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。**

```c++
#include <iostream>
#include <string>
using namespace std;
class Sales_data;
istream &read(istream &is, Sales_data &item);

class Sales_data {
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) { }
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { }
	Sales_data(istream &is) { read(is, *this); }
	void CalcRevenue(double price);
	double CalcAveragePrice();
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	friend istream &read(istream &is, Sales_data &item);
	friend ostream &print(ostream &os, const Sales_data &item);
};
/*...*/
```

#### 练习7.22

- **修改你的Person类使其隐藏实现的细节。**  

```c++
#include <iostream>
#include <string>
using namespace std;
class Peason{
public:
	Peason() = default;
	Peason(const string s1, const string s2) :name(s1), address(s2) { }
	Peason(istream &is);
	string get_name() const { return name; }
	string get_address() const { return address; }
private:
	string name;
	string address;
	friend istream &read(istream &is, Peason &item);
	friend ostream &print(ostream &os, const Peason &item);
};
istream &read(istream &is, Peason &item) {
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, const Peason &item) {
	os << item.name << " " << item.address;
	return os;
}
Peason::Peason(istream &is) {
	read(is, *this);
}
```

### 7.3.1节练习

#### 练习7.23

- **编写你自己的Screen类。**

```c++
#include <string>
using namespace std;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
	char get() const { return contents[cursor]; }
	char get(pos row, pos col) { return contents[row * width + col]; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};
```

#### 练习7.24

- **给你的Screen类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。**

```c++
#include <string>
using namespace std;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { };
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
	char get() const { return contents[cursor]; }
	char get(pos row, pos col) { return contents[row * width + col]; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};
```

#### 练习7.25

- **Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？**

Screen类中的四个成员对象都是内置类型，因此能够安全地依赖于拷贝和赋值操作的默认版本。

#### 练习7.26

- **将Sales_data::avg_price定义成内联函数。**

```c++
inline double Sales_data::avg_prive() const
{
	if (units_sold != 0)
		return revenue / units_sold;
	else
		return 0.0;
}
```

### 7.3.2节练习

#### 练习7.27

- **给你自己的Screen类添加move、set、和display函数，通过执行下面的代码检验你的类是否正确。**

- ```c++
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout<< "\n";
    ```

```c++
#include <string>
using namespace std;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { };
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
	char get() const { return contents[cursor]; }
	char get(pos row, pos col) { return contents[row * width + col]; }
	Screen &move(pos, pos);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os) { do_display(os); return *this; }
	const Screen &display(ostream &os) const { do_display(os); return *this; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream &os) const { os << contents; }
};
inline Screen &Screen::move(pos row, pos col) {
	pos rows = row * width;
	cursor = rows + col;
	return *this;
}
inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos row, pos col, char c) {
	contents[row * width + col] = c;
	return *this;
}
```

#### 练习7.28

- **如果move、set和display函数的返回类型不是Screen&而是Screen，则在上一个练习中将会发生什么？**

Screen对象将cursor移动到了20的位置，后续的操作都将与新返回的副本进行。'#'被赋值到了副本中。第一个display展示的是被赋值过有的副本。第二个display展示的是全X。

#### 练习7.29

- **修改你的Screen 类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？**

    正确

#### 练习7.30

- **通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。**

通过this指针访问成员的优点是可以非常明确地指出访问的是对象的成员，并且可以在成员函数中使用与数据成员同名的形参；缺点是显得多余，代码不够简洁。

### 7.3.3节练习

#### 练习7.31

- **定义一对类X和Y，其中X 包含一个指向 Y 的指针，而Y包含一个类型为 X 的对象。**

```c++
int main()
	{
	class Y;
	class X {
		Y *py;
	};
	class Y {
		X x;
	};
	}a
```

### 7.3.4节练习

#### 练习7.32

- **定义你自己的Screen 和 Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。**

```c++
#include <string>
using namespace std;
class Screen;    //Windows_mgr含有Screen对象，因此得先声明
class Window_mgr {  //先定义Window_mgr类
public:
	using ScreenIndex = vector<Screen>::size_type;    //Screen坐标
	void clear(ScreenIndex i);  //声明函数，但不定义
private:
	vector<Screen> screens;//{Screen(24, 80, ' ')};直接调用Screen的构造函数将会报错
};
class Screen {  //后声明并定义Screen类
public:
	friend void Window_mgr::clear(ScreenIndex i);   //并声明友元函数
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { };
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
    //...
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};
//...
inline void Window_mgr::clear(ScreenIndex i) {  //最后定义clear函数
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}
```

### 7.4节练习

#### 练习7.33

- **如果我们给Screen 添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。**

```c++
pos Screen::size() const
{
    return height * width;
}
//返回类型错误，在Screen类型外没有pos这样的数据类型。数据类型将未知。应改为：
Screen::pos Screen::size() const
//...
```

### 7.4.1节练习

#### 练习7.34

- **如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？**

pos将是未定义的标志符，导致编译失败。

#### 练习7.35

- **解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。**

```c++
typedef string Type;    //定义Type类型为string
Type initVal();    // 全局函数声明，返回类型为string
class Exercise
{
public:
    typedef double Type;    //定义Type类型为double
    Type setVal(Type);    //成员函数，返回类型，形参为double
    Type initVal();       //成员函数，返回类型为double（隐藏了同名的函数）
private:
    int val;
};

Type Exercise::setVal(Type parm)    //成员函数的定义，返回类型为string 参数类型为double
{
    val = parm + initVal();    //成员函数为initVal()
    return val;
}
//setVal函数返回值的类型和返回类型不符，改为：
Exercise::Type Exercise::setVal(Type parm)
```

### 7.5.1节练习

#### 练习7.36

- **下面的初始值是错误的，请找出问题所在并尝试修改它。**

```c++
struct X{
    X (int i, int j): base(i), rem(base % j) {}
    int rem, base;
};
根据类定义内出现的顺序，rem将被优先初始化，而此时base未被初始化，因此错误。改为：
    int base, rem;
```

#### 练习7.37

- **使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。**

```c++
Sales_data first_item(cin);    // Salas_data(std::istream &is) 用户输入的值
int main() {
    Sales_data next;    // Sales_data(std::string s = "")  bookNo="",cnt=0,rev=0.0
    // Sales_data(std::string s = "") bookNo="9-999-99999-9",cnt=0,rev=0.0
    Sales_data last("9-999-99999-9");
}
```

#### 练习7.38

- **有些情况下我们希望提供cin作为接受istream& 参数的构造函数的默认实参，请声明这样的构造函数。**

```c++
Sales_data(std::istream &is = std::cin) { read(is, *this)}
//该构造函数已有了默认构造函数的功能，为避免二义性，因将原构造函数删除
```

#### 练习7.39

- **如果接受string的构造函数和接受 istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？**

不合法。此时使用构造函数且不输入参数，则两个构造函数都可以为其进行默认构造，将无法选择使用哪个函数，引起二义性。

#### 练习7.40

- **从下面的抽象概念中选择一个（或者你自己指定一个 ，思考这样的类需要哪些数据成员， 提供一组合理的构造函数并阐明这样做的原因。**

```c++
(a) Book           (b) Data           (c) Employee
(d) Vehicle        (e) Object        (f) Tree
```

```c++
class Tree
{
private:
	std::string Name;
	unsigned Age = 0;
	double Height = 0;
public:
	Tree() = default;
	Tree(const std::string &n, unsigned a, double h)
		: Name(n), Age(a), Height(h)
};
```

### 7.5.2节练习

#### 练习7.41

- **使用委托构造函数重新编写你的Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建Sales_data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。**

```c++
#include <iostream>
#include <string>
using namespace std;
class Sales_data;
istream &read(istream &is, Sales_data &item);
class Sales_data {
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { cout << "3 parameter" << endl; }
	Sales_data() : Sales_data("", 0, 0.0) { cout << "0 parameter" << endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0.0) { cout << "1 parameter" << endl; }
	Sales_data(istream &is):Sales_data() { read(is, *this); cout << "istream parameter" << endl; }
    friend istream &read(istream &is, Sales_data &item);
};
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
int main(int argc, char const * argv[])
{
	Sales_data s1;
	Sales_data s2("cin");
    Sales_data s3("cin", 5, 8);
    return 0;
}
```

将会优先调用被委托的构造函数，及其函数体，再返回至调用函数的函数体。

#### 练习7.42

- **对于你在练习7.40 （参见7.5.1节，第261 页）中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。**

```c++
class Book
{
private:
	string Name, ISBN, Author, Publisher;
	double Price = 0;
public:
	Book(const string & n, const string &I, double pr, const string & a, const string & p)
		: Name(n), ISBN(I), Price(pr), Author(a), Publisher(p) { }
	Book() : Book("", "", 0, "", "") { }
	Book(std::istream & is) : Book() { is >> *this; }
};
```

### 7.5.3节练习

#### 练习7.43

- **假定有一个名为NoDefault 的类，它有一个接受int的构造函数，但是没有默认构造函数。定义类C, C 有一个NoDefault 类型的成员，定义C 的默认构造函数。**

```c++
using namespace std;
class NoDefault {
public:
	NoDefault(int i) : val(i) {};
private:
	int val;
};
class C {
public:
	C(int i = 0) : A(i) {}
private:
	NoDefault A;
};
int main(){
	C();
}
```

#### 练习7.44

- **下面这条声明合法吗？如果不，为什么？**

```c++
vector<NoDefault> vec(10);
```

这条语句的意思是初始化一个`vector`，其中包含10个`NoDefault`类（由其自身默认初始化）。而该类型不存在默认构造函数，无法成功构造因此不合法。

#### 练习7.45

- **如果在上一个练习中定义的vector 的元素类型是C，则声明合法吗？为什么？**

合法，C可以默认初始化。

#### 练习7.46

- **下面哪些论断是不正确的？为什么？**
- ( a ） 一个类必须至少提供一个构造函数。
    ( b ）默认构造函数是参数列表为空的构造函数。
    ( c ） 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
    ( d ）如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。

（a）错误。见（d）

（b）错误。默认构造函数也可以有参数，为对应的成员提供默认初始化。

（c）错误。一般情况下，类需要一个默认构造函数来初始化其成员。

（d）错误。只要类内有了构造函数，编译器就不会再为其生成构造函数。

### 7.5.4节练习

#### 练习7.47

- **说明接受一个string 参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。**

应该是explicit的，这样可以防止编译器自动的把一个string对象转换成Sales_data对象，这样可能会导致意想不到的后果。

使用explicit的优点是避免因隐式转换而带来的意想不到的错误，缺点是用户的确需要这样的类类型转换时，不得不使用略显繁琐的方式来实现。

#### 练习7.48

- **假定Sales_data 的构造函数不是explicit 的，则下边定义将执行什么样的操作？如果Sales_data 的构造函数是explicit 的，又会发生什么呢？**

```c++
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
不是explicit。
Sales_data item1(null_isbn);//定义了一个Sales_data对象，该对象利用null_isbn转换得到的临时对象通过构造函数进行初始化
Sales_data item2("9-999-99999-9");//定义了一个Sales_data对象，该对象使用字符串字面值转换得到的临时对象通过构造函数进行初始化
是explicit同上。
```

#### 练习7.49

- **对于combine 函数的三种不同声明，当我们调用i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个string对象。**

```c++
(a)Sales_data & combine(Sales_data);
(b)Sales_data & combine(Sales_data &);
(c)Sales_data & combine(const Sales_data &) const;
```

（a）正确。s隐式调用了Sales_data的构造函数，生成临时对象并传递给combine的形参。

（b）错误。因为combine成员函数的形参是非常量引用，但是s自动创建的Sales_data临时对象无法传递给combine所需的非常量引用。（PS：隐式转换生成的无名的临时对象是const的）

（c）编译无法通过。因为我们把combine成员函数声明成了常量成员函数，所以该函数无法修改数据成员的值。

#### 练习7.50

- **确定在你的Person 类中是否有一些构造函数应该是explicit 的。**

将构造函数Person(std::istream & is)定义为explicit。

#### 练习7.51

- **vector 将其单参数的构造函数定义成explicit 的，而string 则不是，你觉得原因何在？**

如果vector单参数构造函数不是explicit的，那么对于这样的一个函数void fun(vector<int> v)来说，可以直接以这样的形式进行调用fun(5)，这种调用容易引起歧义，无法得知实参5指的是vector的元素个数还是只有一个值为5的元素。而string类型不是一个容器，不存在这样的歧义问题。

### 7.5.5节练习

#### 练习7.52

- **使用2.6.1节（第64页）的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。**

```c++
Sales_data item = {"987-0590353403", 25, 15.99};
```

将Sales_data的bookNo成员初始化为"978-0590353403"，将units_sold初始化为25，将revenue初始化为15.99

### 7.5.6节练习

#### 练习7.53

- **定义你自己的Debug。**

略。

#### 练习7.54

- **Debug 中以set_开头的成员应该被声明成constexpr吗？如果不，为什么？**

不能。constexpr函数有且只能包含一条return语句。

#### 练习7.55

- **7.5.5节（第266页）的 Data 类是字面值常量类吗？请解释原因。**

不是。s的数据类型string不是字面值类型。数据类型都是字面值类型的聚合类是字面值常量类。

### 7.6节练习

#### 练习7.56

- **什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？**

静态成员是指声明语句之前带有关键字static的类成员，静态成员不是任意单独对象的组成部分，而是由该类的全体对象所共享。

静态成员的优点包括：作用域位于类的范围之内，避免与其他类的成员或者全局作用域的名字冲突；可以是私有成员，而全局对象不可以；通过阅读程序可以非常容易地看出静态成员与特定类关联，使得程序的含义清晰明了。

静态成员与普通成员的区别主要体现在普通成员与类的对象关联，是某个具体对象的组成部分；而静态成员不从属于任何具体的对象，它由该类的所有对象共享。另外，还有一个细微的区别，静态成员可以作为默认参数，而普通成员不能作为默认参数。

#### 练习7.57

- **编写你自己的Account 类。**

```c++
class Account
{
private:
	string strName;
	double dAmount = 0.0;
	static double dRate;
};
```

#### 练习7.57

- **下面的静态数据成员的声明和定义有错误吗？请解释原因。**

```c++
//example.h
class Example{
public:
    static double rate = 6.5;     //不是字面值常量类型的常量表达式的静态数据成员不允许在类内初始化
    //正确，但是在类外应该在定义一下，比如：const int Example::vetSize
    static const int vecSize = 20;
    //错误，constexpr static数据成员必须是字面值类型，vector非字面值类型，不允许类内初始化
    static vector<double> vec(vecSize);
};
//example.C
#include “example.h”           //两者在上面都错了，需要重新给出初始值
double Example::rate;
vector<double> Example::vec;
```

