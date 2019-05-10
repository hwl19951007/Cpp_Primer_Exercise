# chapter6 函数

[TOC]

## 练习

### 6.1 节练习

#### 练习6.1

- **实参和形参的区别是什么？**

形参是函数内部被使用的参数。实参是形参的初始值，实参用于初始化形参。

#### 练习6.2

- **请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？**

```c++
(a) int f() {
    string s;
    //...
    return s;}    //返回值与函数返回类型不同，将函数返回类型从int改为string。
(b) f2(int i) { /*...*/ }    //没有定义函数返回类型。
(c) int calc(int v1, int v1) /*...*/ }    //形参不能同名，函数体没有被花括号包裹。
(d) double square(double x) return x * x;    //函数体没有被花括号包裹。
```

#### 练习6.3

- **编写你自己的fact函数，上机检查是否正确。**

```c++
#include <iostream>
using namespace std;
int fact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
int main()
{
	cout << fact(5);
}
```

#### 练习6.4

- **编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。**

```c++
#include <iostream>
using namespace std;
int fact1() {
	cout << "Please enter an integer:" << endl;
	int val;
	cin >> val;
	cout << "The factor of " << val;
	int ret = 1;
	while (val > 1)
		ret *= val--;
	cout << " is " << ret << endl;
	return 0;
}
int main()
{
	fact1();
}

```

#### 练习6.5

- **编写一个函数输出其实参的绝对值。**

```c++
#include <iostream>
using namespace std;
int abso(int val) {
	if (val > 0)
		return val;
	else return -val;
}
int main()
{
	cout << "Please enter an integer:" << endl;
	int val;
	cin >> val;
	cout << "The absolute value of " << val << " is " << abso(val) << endl;
}
```

### 6.1.1 节练习

#### 练习6.6

- **说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。**

形参是一种在函数内部被初始化和使用的参数，是一种局部变量。形参和函数体内部定义的变量统称为局部变量。局部静态变量能够在函数调用结束后仍不被销毁，存在至整个程序结束后才被销毁。

```c++
#include <iostream>
using namespace std;
int fact(int val) {    //形参
	static int ret = 1;    //局部静态变量
	int fac = 1;           //局部变量
	while (val > 1)
		fac *= val;
	ret += fac;
	return ret;
}
```

#### 练习6.7

- **编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。**

```c++
int ret1() {
	static int val = -1;
	return ++val;
}
```

### 6.1.2 节练习

#### 练习6.8

- **编写一个名为Chapter6.h 的头文件，令其包含6.1节练习（第184页）中的函数声明。**

```c++
#ifndef CHAPTER6_H
#define CHAPTER6_H
int fact1();
#endif
```

### 6.1.3 节练习

#### 练习6.9

- **编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。**

```c++
//fact.cpp
#include "Chapter6.h"
#include <iostream>
using namespace std;
int fact1() {
	cout << "Please enter an integer:" << endl;
	int val;
	cin >> val;
	cout << "The factor of " << val;
	int ret = 1;
	while (val > 1)
		ret *= val--;
	cout << " is " << ret << endl;
	return 0;
}
//factMain.cpp
#include "Chapter6.h"
using namespace std;
int main() {
	fact1();
}
```

### 6.2.1 节练习

#### 练习6.10

- **编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。**

```c++
#include <iostream>
using namespace std;
int change(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
	return 0;
}
int main() {
	int i = 5, j = 10;
	int *p = &i, *q = &j;
	cout << *p << ", " << *q;
	change(p, q);
	cout << " been changed as "<< *p << ", "<< *q;
}
```

### 6.2.2 节练习

#### 练习6.11

- **编写并验证你自己的reset函数，使其作用于引用类型的参数。**

```c++
#include <iostream>
using namespace std;
void reset(int &i) {
	i = 1;
}
int main() {
	int i = 5;
	reset(i);
	cout << i;
}
```

#### 练习6.12

- **改写6.2.1节中练习6.10（第188页）的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？**

```c++
#include <iostream>
using namespace std;
int change(int &i, int &j) {
	int temp = i;
	i = j;
	j = temp;
	return 0;
}
int main() {
	int i = 5, j = 10;
	cout << i << ", " << j;
	change(i, j);
	cout << " been changed as " << i << ", " << j;
}
```

引用。引用就是变量的别名，不容易出错，而指针是地址，容易出错。引用可读性可更强。

#### 练习6.13

- **假设T是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。**

`void f(T)`是传值形参，T的值被拷贝给了形参。`void f(&T)`是引用形参，T被引用为形参。

#### 练习6.14

- **举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。**

将一个字符串内的每个字符变成两个。理论上什么情况下都可以是引用类型，如果不能改变实参的参数，也仅需使用常量引用。

#### 练习6.15

- **说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？**

s是字符串常量引用，因为它不需要被改变，因此是常量，而如果使用传值形参，那么可能会遇到字符串过大的情况，将消耗过多资源用于拷贝字符串。

c是字符，它仅作为比较的对象用，只需要它的字面值，因此用传值形参即可。

occurs是整型引用，它用作计算字符c出现的次数，可能被改变，则不能是常量引用。必须是引用，以在函数外部保留记数信息。

c不会被改变，不必引用。s避免拷贝运算，故用引用。occurs可能被改变，故用引用。

s是普通引用，则s可能被改变，容易引发不必要的错误。

occurs是常量引用的话，将无法起到统计字符c出现的次数的功能，因为它的值将无法被改变。

### 6.2.3 节练习

#### 练习6.16

- **下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。**

```c++
bool is_empty(string& s)
{ 
    return s.empty(); 
}
```

普通引用形参能获取的参数太少了，如常量对象，字面值对象，需要类型转换的对象均无法被传递给普通的引用形参。改为常量引用。

#### 练习6.17

- **编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全都改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？**

```c++
bool upper_in_string(const string & str) {
	bool tag = false;
	for (char c : str) {
		tag = isupper(c);
		if (tag == true) break;
	}
	return tag;
}
void string_to_lower(string & str) {
	for (char &c : str) c = tolower(c);
}
```

使用的形参不同，因为前者无需改变string对象内的元素，故使用常量引用。而后者需要将string对象中的字符改写为小写形式，不能使用常量引用，只能使用普通引用。

#### 练习6.18

- **为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。**
- (a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。
- (b) 名为 change_val 的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。

```c++
(a) bool (const matrix &m1, const matrix &m2);
比较两个matrix对象是否相同或是否前者比后者大。
(b) vector<int>::iterator change_val(int i, vector<int>::iterator);
改变指定向量指定位置的值，将其重新复制为i。
```

#### 练习6.19

- **假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。**

```c++
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
--------------------------------------------
(a) 不合法，实参数量和形参数量不匹配。
(b) 合法。
(c) 合法。
(d) 合法。cd均可由数据类型转换完成调用。
```

#### 练习6.20

- **引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？**

当引用的参数过大，不易于复制时，可以使用常量形参，避免拷贝带来的计算量和空间占用。

会有部分数据类型无法被传入引用中。会给使用者带来一种函数会修改引用的实参的误导。

### 6.2.4 节练习

#### 练习6.21

- **编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？**

```c++
int compare(const int i, const int *p){
	if (i > *p) return i;
	return *p;
}
```

指向常量整型的指针（`const int *`）。

#### 练习6.22

- **编写一个函数，令其交换两个int指针。**

```c++
void swap(int *p, int *q){
	int *temp = p;
	p = q;
	q = temp;
}
```

#### 练习6.23

- **参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:**
- **int i = 0, j[2] = { 0, 1 };**

```c++
#include <iostream>
using namespace std;
void print(const int *beg, const int *end) {
	while (beg != end) cout << *beg++ << endl;
}

void print(const int *arr, size_t size) {
	for (size_t i = 0; i != size; i++)
		cout << *(arr + i) << endl;
}
int main() {
	int i = 0, j[2] = { 0, 1 };
	print(&i, &i + 1);
	print(begin(j), end(j));
	print(&i, 1);
	print(j, 2);
}
```

#### 练习6.24

- **描述下面这个函数的行为。如果代码中存在问题，请指出并改正。**

```c++
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

函数希望将一个包含10个整数的数组一一打印。

`ia[10]`实际上是指向`ia`首个数字的指针，不包含数组元素数量的信息。应改为

`void print(const int (&ia)[10])`。

### 6.2.5 节练习

#### 练习6.25

- **编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。**

```c++
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	for (size_t i = 1; i < argc; ++i)
	{
		cout << argv[i];
	}
	cout << endl;
}
```

#### 练习6.26

- **编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参的内容。**

```c++
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	for (size_t i = 1; i < argc; ++i)
	{
		cout << argv[i] << ' ';
	}
	cout << endl;
}
```

### 6.2.6 节练习

#### 练习6.27

- **编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。**

```c++
int sum(initializer_list<int> il) {
	int sum = 0;
	for (const int i : il) sum += i;
	return sum;
}
```

#### 练习6.28

- **在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？**

const string.

#### 练习6.29

- **在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？**

视情况而定。在变量类型是字符串等大量占用空间的类型时，可以通过引用减少复制的开销。其他情况下，引用与否区别不大，因为initializer_list对象的元素都是常量，即使引用了也无法修改其值。

### 6.3.2 节练习

#### 练习6.30

- **编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。**

error C2561: “str_subrange”: 函数必须返回值。

#### 练习6.31

- **什么情况下返回的引用无效？什么情况下返回常量的引用无效？**

返回的引用是局部变量的引用是无效的。当希望修改引用的值的时候，返回常量的引用无效。

#### 练习6.32

- **下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。**

```c++
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

合法，因为返回的引用是对指针解引用后的值的引用,解引用后的值是非局部变量。

#### 练习6.33

- **编写一个递归函数，输出vector对象的内容。**

```c++
void print(vector<int>::iterator vi, vector<int>::iterator end) {
	if (vi != end) { 
		cout << *vi << endl;
		print(++vi, end);
	}
}
```

#### 练习6.34

- **如果factorial 函数的停止条件如下所示，将发生什么情况？**

```c++
if (val != 0)
```

当输入负数实参时，死循环，函数栈溢出。

#### 练习6.35

- **在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？**

`val--`将返回`val`，不符合阶乘的逻辑，对函数而言会造成死循环，函数栈溢出。可以用`--val`代替。

### 6.3.3 节练习

#### 练习6.36

- **编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名。**

```c++
string (&func())[10];
```

#### 练习6.37

- **为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？**

```c++
using arr = string(&)[10];
arr func();
auto func() -> string(&)[10];
string arr[10];
decltype(arr) &func();
```

尾置返回类型，直观。

#### 练习6.38

- **修改arrPtr函数，使其返回数组的引用。**

```c++
decltype(odd) &arrPtr(int i)
```

### 6.4 节练习

#### 练习6.39

- **说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。**

```c++
(a) int calc(int, int);
int calc(const int, const int);
(b) int get();
double get();
(c) int *reset(int *);
double *reset(double *);
```

（a）calc()形参常量版。非法，顶层const形参无法与没有顶层const的形参区分开来。

（b）get()返回类型double版。非法，与原版仅有返回类型不同。

（c）reset()double类型版。

### 6.5.1 节练习

#### 练习6.40

- **下面的哪个声明是错误的？为什么？**

```c++
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);
```

(b)错误，因为一旦某个形参被赋予了默认值，那么它后面的所有形参都必须有默认值。

#### 练习6.41

- **下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？**

```c++
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24, 10);
(c) init(14, '*');
```

(a)是非法的，缺少实参。

(c)调用合法但与程序员初衷不符。因为`*`字符将被转化为int，赋值给wd，而不是bckgrnd。

#### 练习6.42

- **给make_plural函数（参见6.3.2节，第201页）的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。**

```c++
#include <iostream>
#include <string>
using namespace std;
string make_plural(size_t ctr, const string &word, const string &ending = "s") {
	return (ctr > 1) ? word + ending : word;
}
int main()
{
	cout << make_plural(1, "success") << '\n' << make_plural(2, "success", "es") << '\n'
		<< make_plural(1, "failure") << '\n' << make_plural(2, "failure");
}
```

### 6.5.2 节练习

#### 练习6.43

- **你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？**

```c++
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

(a) 声明和定义都放在头文件中。内联函数的多个定义必须完全一致，因此通常放在头文件中。

(b)声明放在头文件中，定义放在源文件中。可以让编译器协助检查。

#### 练习6.44

- **将6.2.2节（第189页）的isShorter函数改写成内联函数。**

```c++
inline bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
```

#### 练习6.45

- **回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。**

如果是规模较小、流程直接、频繁调用的函数，应该是内联函数。否则不应改为内联函数，因为过大的函数在原地内联展开，容易出现错误等，其减少的计算消耗相比函数本身的消耗也不重要，因此不必改为内联函数。

#### 练习6.46

- **能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constexpr函数；如果不能，说明原因。**

不能。constexpr函数要求形参和返回类型都得是字面值类型。而`s1.size() < s2.size()`不构成一个常数表达式，故也不能返回字面值类型。

### 6.5.3 节练习

#### 练习6.47

- **改写6.3.2节（第205页）练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。**

```c++
#include <iostream>
#include <vector>
#define NDEBUG
using namespace std;
void print(vector<int>::iterator vi, vector<int>::iterator end) {
	if (vi != end) {
		cout << *vi << endl;
		print(++vi, end);
	}
}
int main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7 };
#ifndef NDEBUG    //if not define
	cout << "vector have " << v1.size() << "elements." << endl;
#endif
	print(v1.begin(), v1.end());
}
```

#### 练习6.48

- **说明下面这个循环的含义，它对assert的使用合理吗？**

```c++
string s;
while (cin >> s && s != sought) { } // 空函数体
assert(cin);
```

持续读取cin到s中，直到输入字符串为sought为止。

不合理，当assert读取到cin时，cin只可能是空或sought。那么assert将毫无意义。

### 6.6 节练习

#### 练习6.49

- **什么是候选函数？什么是可行函数？**

候选函数：与被调用的函数同名，且其声明在调用点可见。

可行函数：形参与被调用函数提供的实参数量相等，且每个实参的类型与形参的类型相同，或能转换成形参的类型。

#### 练习6.50

- **已知有第217页对函数f的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？**

```c++
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```

（a）不合法，具有二义性。

（b）合法。最佳匹配为`void f(int);`

（c）合法。最佳匹配为`void f(int, int);`

（d）合法。最佳匹配为`void f(double, double = 3.14);`

#### 练习6.51

- **编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错在何处。**

```c++
#include <iostream>
using namespace std;
void f()
{cout << "调用" << __func__ << "()" << endl;}
void f(int)
{cout << "调用" << __func__ << "(int)" << endl;}
void f(int, int)
{cout << "调用" << __func__ << "(int, int)" << endl;}
void f(double, double = 3.14)
{cout << "调用" << __func__ << "(double, double = 3.14)" << endl;}
int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}
```

### 6.6.1 节练习

#### 练习6.52

- **已知有如下声明：**

```c++
void manip(int , int);
double dobj;
```

请指出下列调用中每个类型转换的等级（参见6.6.1节，第219页）。

```c++
(a) manip('a', 'z');
(b) manip(55.4, dobj);
```

（a）通过类型提升实现的匹配。

（b）通过算数类型转换实现的匹配。

#### 练习6.53

- **说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。**

```c++
(a) int calc(int&, int&);
int calc(const int&, const int&);
(b) int calc(char*, char*);
int calc(const char*, const char*);
(c) int calc(char*, char*);
int calc(char* const, char* const);
```

（a）对函数重载。

（b）对函数重载。

（c）不合法，拥有顶层const的形参和没有顶层const的形参无法被区分。

### 6.7 节练习

#### 练习6.54

- **编写函数的声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。**

```c++
int fun(int, int);
vector<int(*)(int, int)> v;
```

#### 练习6.55

- **编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。**

```c++
#include <vector>
using namespace std;
int fun1(int i, int j) { return i + j; }
int fun2(int i, int j) { return i - j; }
int fun3(int i, int j) { return i * j; }
int fun4(int i, int j) { return i / j; }
int main()
{
	vector<int(*)(int, int)> v = {fun1, fun2, fun3, fun4};
}
```

#### 练习6.56

- **调用上述vector对象中的每个元素并输出结果。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int fun1(int i, int j) { return i + j; }
int fun2(int i, int j) { return i - j; }
int fun3(int i, int j) { return i * j; }
int fun4(int i, int j) { return i / j; }
int main()
{
	vector<int(*)(int, int)> v = {fun1, fun2, fun3, fun4};
	for (auto i : v)
		cout << i(10, 5) << endl;
}
```

15
5
50
2