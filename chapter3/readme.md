# chapter3 字符串、向量和数组

[TOC]



## 笔记

### 3.1命令空间的using声明

- 利用`using`声明快捷访问命名空间中的名字，格式：`using namespace::name;`
  - 例子：`using std::cin;`,则可以直接使用`cin`而不用再使用作用域符`::`
- 每个名字都需要独立的using声明
  - 即，如`cin`和`cout`必须分别独立命名。
- 头文件不应包含`using`声明
  - 如果在头文件中使用`using`声明，那么使用该头文件的每一个文件都会有这个声明，可能引起冲突
- 声明整个命名空间：`using namespace std;`

### 3.2 标准库类型string

#### 3.2.1 定义和初始化string对象

```c++
string s1; //默认初始化，s1为一个空串
string s2(s1); string s2 = s1; //s2是s1的副本
string s3("value");string s3="value"; //s3是字面值"value"的副本（除字符串字面值最后那个空字符） 
string s4(n,'c'); //把s4初始化为由连续n个字符c组成的字符串

tips：使用等号('=')初始化一个变量，执行的是拷贝初始化；如果不使用等号，直接初始化，使用的是直接初始化。
```








## 练习

### 3.1节练习

#### 练习3.1

- **使用恰当的using声明重做1.4.1节和2.6.2节的练习。**

```using namespace std; ```

### 3.2.2节练习

#### 练习3.2

- **编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。**

``````c++
int main()
{
	std::string str;
	//getline可以接收两个参数，输入流和字符串，并将输入流写入字符串
	std::cout << "Now i can get the whole sentence." << std::endl;
	std::getline(std::cin, str);
	std::cout << str << std::endl;
	//cin是获取输入流，遇到空格等空白就会停止
	std::cout << "Now i can get one word." << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;
}
``````

#### 练习3.3

- **请说明string类的输入运算符和getline函数分别是如何处理空白字符的。**

在执行读取操作时string类的输入运算符会自动忽略开头的空白后开始读取，并在遇到下一个空白字符时停止。

getline函数从给定的输入流中读取字符直到遇到换行符\n为止（换行符也读取进来），然后把所读的内容存入到string对象中去（存的过程不包含换行符）。

因此，string对象遇到换行符停止，且得到的string对象不包含换行符，在换行符出现前的空白字符均正常读取。

#### 练习3.4

- **编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。**

```c++
#include <iostream>
#include <string>
int main()
{
	std::string str1, str2;
	std::cout << "please enter two strings." << std::endl;
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);

	if (str1 == str2) std::cout << "Two strings are equal." << std::endl;
	else if (str1 > str2)std::cout << str1 << std::endl;
	else std::cout << str2 << std::endl;

	if(str1.size() == str2.size()) std::cout << "Two strings have same length." << std::endl;
	else if (str1.size() > str2.size())std::cout << str1 << std::endl;
	else std::cout << str2 << std::endl;
}
```

#### 练习3.4

- **编写一段程序从标准输入中读入多个字符串并将他们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。**

```c++
#include <iostream>
#include <string>
int main()
{
	std::string str1, str2;
	std::cout << "please enter some strings." << std::endl;
	while (std::cin >> str2) str1 += str2;
	std::cout << str1 << std::endl;
    
	while (std::cin >> str2) str1 += str2 + " ";
	std::cout << str1 << std::endl;
}
```

### 3.2.3节练习

#### 练习3.6

- **编写一段程序，使用范围for语句将字符串内所有的字符用X代替。**

```c++
#include <iostream>
#include <string>
int main()
{
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	for (auto &c : str) c = 'X'; //用引用来修改其值
	std::cout << str << std::endl;
}
```

#### 练习3.7

- **就上一题完成的程序而言，如果将循环控制变量的类型设为char将发生什么？先估计一下结果，然后实际编程进行验证。**

无变化，单个字符本就是char类型。

#### 练习3.8

- **分别用while循环和传统的for循环重写练习3.6的程序，你觉得哪种形式更好呢？为什么？**

``````c++
decltype(str.size()) i=0;
for (i=0;i<str.size();i++) str[i] = 'X';
i=0;
while (i < str.size()) str[i++] = 'X';
//range for的形式更好，不用选择下标，更方便。
``````

#### 练习3.9

- **下面的程序有何作用？它合法吗？如果不合法，为什么？**

```c++
string s;
cout << s[0] <<endl;
//不合法，s为空字符串，使用下标访问空string会引发不可预知的错误。
```

#### 练习3.10

- **编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩下的部分。**

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	for (char &c : str) {
		if (!ispunct(c))
			cout << c;
	}
}
```

#### 练习3.11

- **下面的范围for语句合法吗？如果合法，c的类型是什么？**

```c++
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
//合法，c的类型为char，因为auto会忽略顶层const。
```

### 3.3.1节练习

#### 练习3.12

- **下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果，对于不正确的，说明其错误的原因。**

```c++
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");

(a) 正确，创建一个vector，该vector的元素是int型的vector对象 
(b) 错误，ivec和svec对象类型不同，svec的元素是string对象，ivec的元素是int型的vector对象 
(c) 正确，创建一个vector，svec的元素是string对象，并对其初始化，svec含有10个元素，每个的值都是"null"
```

#### 练习3.13

- **下列的vector对象各包含多少个元素？这些元素的值分别是多少？**

```c++
(a) vector<int> v1;
(b) vector<int> v2(10);
(c) vector<int> v3(10,42);
(d) vector<int> v4{10};
(e) vector<int> v5{10,42};
(f) vector<string> v6{10}; 
(g) vector<string> v7{10,"hi"};

(a) v1是一个空vector，不含任何元素；
(b) v2是一个含有10个元素的vector，每个元素的值被默认初始化为0
(c) v3是一个含有10个元素的vector，每个元素的值为42
(d) v4是一个含有1个元素的vector，该元素值为10
(e) v5是一个含有2个元素的vector，元素值分别为10，42
(f) v6是一个含有10个元素的vector，v6的元素是空string对象
(g) v7是一个含有10个元素的vector，v6的元素是string对象，每个元素的值为"hi"
tips：v7的花括号中提供的元素值不能作为元素的初始值，在确认无法执行列表初始化后，编译器会尝试用默认值初始化vector对象。
(g) vector<string> v7{10,"hi"}; -> 无法列表初始化，等价于 <=> vector<string> v7(10,"hi");
```

### 3.3.2节练习

#### 练习3.14

- **编写一段程序，用cin读入一组整数并把它们存入一个vector对象。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	std::vector<int> v;
	int i;
	while (cin >> i) v.push_back(i);
}
```

#### 练习3.15

- **改写上题的程序，不过这次读入的是字符串。**

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> v;
	string s;
	while (true) {
		cin >> s;
		v.push_back(s);
	}
}
```

### 3.3.3节练习

#### 练习3.16

- **编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不对，回过头重新学习3.3.1节（第87页）知道弄明白错在何处为止。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> v1;                    //没有包含元素
    for (auto i : v1)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v2(10);              //包含10个元素,所有的元素值为0
    for (auto i : v2)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v3(10, 42);          //包含10个元素,所有的元素值为42
    for (auto i : v3)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v4{10};              //包含1个元素，值为10
    for (auto i : v4)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v5{10, 42};          //包含2个元素，值为10和42
    for (auto i : v5)
        cout << i << '\t';
    cout << "\n============\n";
    vector<string> v6{10};          //包含10个元素,所有的元素值为空字符串
    for (auto i : v6)
        cout << i << '\t';
    cout << "\n============\n";
    vector<string> v7{10, "hi"};    //包含10个元素,所有的元素值为字符串“hi”
    for (auto i : v7)
        cout << i << '\t';
    cout << "\n============\n";
    return 0;
}
```

#### 练习3.17

- **从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写成大写形式。输出改变后的结果，每个词占一行。**

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> v;
	string str;
	while (cin >> str) {
		for (auto &c : str) c = toupper(c);
		v.push_back(str);
	}
	for (auto s : v) cout << s << '\n';
}
```

#### 练习3.18

- **下面的程序合法吗？如果不合法，你准备如何修改？**

```c++
vector<int> ivec;
ivec[0] = 42;

不合法，因为ivec为空vector，vector的下标只能用于访问已存在的元素，且不能使用下标形式添加元素，只能使用push_back添加

改为：
vector<int> ivec;
ivec.push_back(42);
```

#### 练习3.19

- **如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请列举出三种不同的实现方法。那种方法更好呢？为什么？**

```c++
vector<int> v1(10, 42);
vector<int> v2(v1);
vector<int> v3;
for (int i=0; i < 10; i++) v3.push_back(42);
//圆括号法，简单便捷。
```

#### 练习3.20

- **读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int i;
	while (cin >> i) v.push_back(i);
	int len = v.size();
	for (i = 0; i < len - 1; i++)   //相邻整数
		cout << v[i] + v[i + 1] << ' ';
	cout << '\n';
	for (i = 0; i < len >>1; i++)  //头尾整数
		cout << v[i] + v[len - i - 1] << ' ';
}
```

### 3.4.1节练习

#### 练习3.21

- **请使用迭代器重做3.3.3节（第94页）的第一个练习（练习3.16）。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v1;                    //没有包含元素
	for (auto it = v1.cbegin(); it != v1.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v2(10);              //包含10个元素,所有的元素值为0
	for (auto it = v2.cbegin(); it != v2.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v3(10, 42);          //包含10个元素,所有的元素值为42
	for (auto it = v3.cbegin(); it != v3.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v4{ 10 };              //包含1个元素，值为10
	for (auto it = v4.cbegin(); it != v4.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v5{ 10, 42 };          //包含2个元素，值为10和42
	for (auto it = v5.cbegin(); it != v5.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<string> v6{ 10 };          //包含10个元素,所有的元素值为空字符串
	for (auto it = v6.cbegin(); it != v6.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<string> v7{ 10, "hi" };    //包含10个元素,所有的元素值为字符串“hi”
	for (auto it = v7.cbegin(); it != v7.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	return 0;
}
```

#### 练习3.22

- **修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后再输出它。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> text;
	string str;
	while (cin >> str)
		text.push_back(str);
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (auto &c : *it) c = toupper(c);
		cout << *it << endl;
	}
}
```

#### 练习3.23

- **编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v(10,2);
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << '\t';
	cout << endl;
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it *= 2;
		cout << *it << '\t';
	}
}
```

### 3.4.2节练习

#### 练习3.24

- **请使用迭代器重做3.3.3节（第94页）的最后一个练习（练习3.20）。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int i;
	while (cin >> i) v.push_back(i);
	auto begin = v.begin(), end = v.end() - 1;
	for (auto it = begin; it < end; it++)   //相邻整数
		cout << *it + *(it + 1) << ' ';
	cout << '\n';
	for (;begin < end; begin++, end--)  //头尾整数
		cout << *begin + *end << ' ';
}
```

#### 练习3.25

- **3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto begin = scores.begin();
	while (cin >> grade) {
		if (grade <= 100)
			++*(begin + grade / 10);
	}
}
```



#### 练习3.26

- **在100页的二分搜索程序中，为什么用的是mid = beg + (end - beg) / 2，而非mid = (beg + end) / 2？**

迭代器之间没有定义`+`运算符。但可以加一个整数，来获取位移过后的迭代器。

### 3.5.1节练习

#### 练习3.27

- **假设txt_size是一个无参数的函数，它的返回值是int。请问下列哪个定义是非法的？为什么？**

```c++
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";

(a) 非法，buf_size为非常量表达式
(b) 合法
(c) 非法。若text_size()为常量表达式（constexpr）时，在编译时确定具体指并替换，则正确；否则错误
(d) 非法，溢出，字符数组利用字符串字面值进行初始化时'\0'会包含
```



#### 练习3.28

- **下列数组中的元素值是什么？**

```c++
string sa[10];
int ia[10];
int main(){
    string sa2[10];
    int ia2[10];
}
sa和ia位于定义于任何函数体之外，sa为空字符串；ia数组内每个值均初始化为0。
sa2和ia2在函数体内部，srting类规定没有指定初值则声称一个空串；ia2不被初始化，其中的值未定义。

综上，sa和sa2初始化为空串；ia数组内每个值均为0，ia2中值未定义。
```



#### 练习3.29

- **相比于vector 来说，数组有哪些缺点，请例举一些。**

数组没有vector灵活，数组的大小确定不变，不能随意向数组内增加元素。数组的运算符少，内置函数也少，缺少比较方法等。也不能复制。

### 3.5.2节练习

#### 练习3.30

- **指出下面代码中的索引错误。**

```c++
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;

int ia[10]中存放ia[0]~is[9]的值，for循环中，ix可以为10，访问了ia[10]，导致下标越界。
```

#### 练习3.31

- **编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。**

```c++
int main()
{
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
}
```

#### 练习3.32

- **将上一题刚刚创建的数组拷贝给另外一个数组。利用vector重写程序，实现类似的功能。**

```c++
#include <vector>
using namespace std;
int main()
{
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	int ib[10];
	for (int i = 0; i < 10; i++) ib[i] = ia[i];
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(ia[i]);
}
```

#### 练习3.33

- **对于104页的程序来说，如果不初始化scores将发生什么。**

数组会默认初始化，而数组内的值将不进行初始化，即不被定义。

### 3.5.3节练习

#### 练习3.34

- **假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？**

```c++
p1 += p2 - p1;
将p1指向p2所指向的元素。若p1和p2指向的元素不再一个数组内，该程序是违法的。
```

#### 练习3.35

- **编写一段程序，利用指针将数组中的元素置为0。**

```c++
int main()
{
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int *p = ia; p!=&ia[10]; p++)
		*p = 0;
}
```

#### 练习3.36

- **编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。**

```c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int ia[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int ib[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bool equal = true;
	if (sizeof(ia) == sizeof(ib)) {
		auto len = end(ia) - ia;
		for (int i = 0; i < len; i++)
			if (ia[i] != ib[i]){
				equal = false;
				break;
			}
	}
	if (equal) cout << "This two arrays is equal" << endl;
	else cout << "This two arrays is not equal" << endl;
	vector<int> v1 = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v2 = { 0,1,2,3,4,5,6,7,8,9 };
	if (v1 == v2)cout << "This two vectors is equal" << endl;
	else cout << "This two vectors is not equal" << endl;
}
```

### 3.5.4节练习

#### 练习3.37

- **下面的程序是何定义，程序的输出结果是什么？**

```c++
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while(*cp){
    cout << *cp <<endl;
    ++cp;
}

程序不会报错，但会一直在地址中向后寻找到一个空字符'\0'才停止。
正确写法为const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
程序会一在输出hello后继续输出内存中存在的信息，直到'\0'。
```

#### 练习3.38

- **在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有意义？**

指针中存储的值是内存地址，两个地址相加无法估计结果，也没有逻辑上的意义。

#### 练习3.39

- **编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。**

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "A string example";
	string str2 = "A dofferent example";
	if (str1 == str2) cout << "str1 equal to str2" << endl;
	else if (str1 < str2) cout << "str1 litter than str2" << endl;
	else cout << "str1 greater than str2" << endl;

	const char ca1[] = "A string example";
	const char ca2[] = "A different example";
	if (strcmp(ca1, ca2) == 0) cout << "str1 equal to str2" << endl;
	else if (strcmp(ca1, ca2) < 0) cout << "str1 litter than str2" << endl;
	else cout << "str1 greater than str2" << endl;
}
```

#### 练习3.40

- **编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。**

```c++
#include <iostream>
using namespace std;
int main()
{
	const char ca1[] = "Hello";
	const char ca2[] = " world!";
	char ca3[13];
	strcpy(ca3, ca1);
	strcat(ca3, ca2);
	cout << ca3 << endl;
}
```

### 3.5.5节练习

#### 练习3.41

- **编写一段程序，用整型数组初始化一个vector对象。**

```c++
#include <vector>
using namespace std;
int main()
{
	int arr[] = { 1,2,3,4,5 };
	vector<int> v(begin(arr), end(arr));
}
```

#### 练习3.42

- **编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。**

```c++
#include <vector>
using namespace std;
int main()
{
	vector<int> v{1,2,3,4,5};
	int arr[5];
	for (int i = 0; i < v.size(); i++) arr[i] = v[i];
}
```

### 3.6节练习

#### 练习3.43

- **编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通的for语句，其中版本2要求用下标运算符，版本3要求用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。**

```c++
#include <iostream>
using namespace std;
int main()
{
	cout << "Version1:" << endl;
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int(&p)[4] : ia)
		for (int q : p) cout << q << ' ';
	cout << '\n' << "Version2:" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cout << ia[i][j] << ' ';
	cout << '\n' << "Version3:" << endl;
	for (int *p = ia[0]; p < ia[3]; p++)
		cout << *p << ' ';
}
```

#### 练习3.44

- **改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。**

```c++
#include <iostream>
using namespace std;
int main()
{
	cout << "Version1:" << endl;
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	using ref4 = int(&)[4];
	for (ref4 p : ia)
		for (int q : p) cout << q << ' ';
	cout << '\n' << "Version2:" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cout << ia[i][j] << ' ';
	cout << '\n' << "Version3:" << endl;
	for (int *p = ia[0]; p < ia[3]; p++)
		cout << *p << ' ';
}
```

#### 练习3.45

- **改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。**

```c++
#include <iostream>
using namespace std;
int main()
{
	cout << "Version1:" << endl;
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto &p : ia)
		for (auto q : p) cout << q << ' ';
	cout << '\n' << "Version2:" << endl;
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 4; j++)
			cout << ia[i][j] << ' ';
	cout << '\n' << "Version3:" << endl;
	for (auto *p = ia[0]; p < ia[3]; p++)
		cout << *p << ' ';
}
```







