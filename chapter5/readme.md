# chapter5 语句

[TOC]

## 练习

### 5.1节练习

#### 练习5.1

- **什么是空语句？什么时候会用到空语句？**

空语句就是不执行任何内容的语句。仅包含一个分号。在语法上需要一条语句但在逻辑上不需要的时候，会用到空语句。

#### 练习5.2

- **什么是块？什么时候会用到块？**

块就是复合语句，用花括号括起来的（可能为空的）语句和声明的序列。在语法上需要一条语句，但在逻辑上需要多条语句的时候会用到块。

#### 练习5.3

- **使用逗号运算符（参见4.10节，第104页）重写1.4.1节（第10页）的 while 循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。**

```c++
while(val <= 10)
    sum += val, ++val;
```

可读性降低了。

### 5.2节练习

#### 练习5.4

- **说明下列例子的含义，如果存在问题，试着修改它。**

```c++
(a) while (string::iterator iter != s.end()) {/*...*/}
(b) while (bool status = find(word)) {/*...*/}
    if (!status) {/*...*/}
(a) 遍历字符串s。语法错误，while内的变量必须被初始化，而iter并没有初始化，应在外部初始化iter。
(b) 函数正确则死循环。status是while的内部变量，无法访问。应在外部初始化status。
```

### 5.3.1节练习

#### 练习5.5

- **写一段自己的程序，使用if else 语句实现把数字成绩转换为字母成绩的要求。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string lettergrade;
	int grade;
	while (cin >> grade)
	{
		if (grade < 60)
			lettergrade = scores[0];
		else
			lettergrade = scores[(grade - 50) / 10];
		cout << lettergrade << '\n';
	}
}
```

#### 练习5.6

- **写一段自己的程序，使用if else 语句实现把数字成绩转换为字母成绩的要求。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string lettergrade;
	int grade;
	while (cin >> grade)
	{
		grade < 60 ? lettergrade = scores[0] : lettergrade = scores[(grade - 50) / 10];
		cout << lettergrade << '\n';
	}
}
```

#### 练习5.7

- **改写下列代码段中的错误。**

```c++ 
(a) if (ival1 != ival2)
        ival1 = ival2
    else ival1 = ival2 = 0;
改为 if (ival1 != ival2)
        ival1 = ival2;    //原代码段此处缺少分号

    else else ival1 = ival2 = 0;
(b) if (ival < minval)
        minval = ival;
        occurs = 1;
改为 if (ival < minval){   //原代码段缺少花括号将两条赋值语句改为复合语句。
        minval = ival;
        occurs = 1;}

(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
改为 int ival = get_value();    //原代码段中，ival为第一个if的内部变量
     if (ival)
         cout << "ival = " << ival << endl;
     if (!ival)
         cout << "ival = 0\n";

(d) if (ival = 0)
        ival = get_value();
改为 if (ival == 0)    //原代码段其实可以执行，但根据一般语义来说，条件应该为判断是否相等而不是赋值
        ival = get_value();
```

#### 练习5.8

- **什么是“悬垂else”？C++语言是如何处理else子句的？**

在嵌套if语句中，if分支多于else分支的情况。C++的解决方法是规定else与离它最近的未匹配的if语句匹配。

### 5.3.2节练习

#### 练习5.9

- **编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。**

```c++
#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	char c;
	while (cin >> c) {
		if (c == 'a') count += 1;
		if (c == 'e') count += 1;
		if (c == 'i') count += 1;
		if (c == 'o') count += 1;
		if (c == 'u') count += 1;
	}
	cout << count << endl;
}
```

#### 练习5.10

- **我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计元音字母的大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。**

```c++
#include <iostream>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char c;
	while (cin >> c) {
		c = tolower(c);
		if (c == 'a') aCnt += 1;
		if (c == 'e') eCnt += 1;
		if (c == 'i') iCnt += 1;
		if (c == 'o') oCnt += 1;
		if (c == 'u') uCnt += 1;
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << endl;
}
```

#### 练习5.11

- **修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。**

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, nCnt = 0;    //最后三个为空格，制表符，换行符
	string str;
	char c;
	while (getline(cin, str)) {
		c = tolower(str[0]);
		if (c == 'a') aCnt += 1;
		if (c == 'e') eCnt += 1;
		if (c == 'i') iCnt += 1;
		if (c == 'o') oCnt += 1;
		if (c == 'u') uCnt += 1;
		if (c == ' ') sCnt += 1;    //cin 无法获取空格和制表符，改用getline
		if (c == '\t') tCnt += 1;
		if (c == '\n') nCnt += 1;    //getline 也无法获取到换行符，只能改用从文本文件的输入流中获取
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of vowel space: \t" << sCnt << '\n'
		<< "Number of vowel tab: \t" << tCnt << '\n'
		<< "Number of vowel newline: \t" << nCnt << endl;
}
```

#### 练习5.12

- **修改统计元音字母的程序，使其能统计含以下两个字符的字符序列的数量： ff、fl和fi。**

```c++
#include <iostream>
using namespace std;
int main()
{
	unsigned  ffCnt = 0, flCnt = 0, fiCnt = 0;
	char c;
	char temp = ' ';
	while (cin >> c) {
		if (temp == 'f')
			if (c == 'f') ffCnt += 1;
			else if (c == 'l') flCnt += 1;
			else if (c == 'i') fiCnt += 1;
		temp = c;
	}
	cout << "Number of vowel ff: \t" << ffCnt << '\n'
		<< "Number of vowel fl: \t" << flCnt << '\n'
		<< "Number of vowel fi: \t" << fiCnt << endl;
}
```

#### 练习5.13

- **下面显示的每个程序都含有一个常见的编码错误，指出错误在哪里，然后修改它们。**

```c++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;}
首先没有写break，其次default情况下，任意字符均会使iouCnt++，逻辑错误。
修正如下：
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': 
        aCnt++;
        break;
    case 'e':
        eCnt++;
        break;
    case 'i': case 'o': case 'u':
        iouCnt++;
        break;
    default: 
        break;
}
```

```c++
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();    //将该语句移至switch结构体之前。
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec [ ix ] = index;}
执行switch语句时，可能跳过ix的定义。改为在switch外部定义即可。
```

```c++
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1,3,5,7,9:    //改为case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2,4,6,8,10:    //改为case 0: case 2: case 4: case +: case 8:
            evencnt++;
            break;
    }
case写法错误，同时在switch内部的变量名称大小写也错误了。以及不应该存在10的情况，应改为0。
```

```c++
(d) unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
case 标签必须是整型常量表达式。而不能是变量。
将首部初始化语句修改为constexpr unsigned ival = 512, jval = 1024, kval = 4096;
```

### 5.4.1节练习

#### 练习5.14

- **编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是：**

    **how now now now brown cow cow**
    **那么输出应该表明单词now连续出现了3次。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vstr;
	string str;
	int count = 0;
	while (cin >> str)
		vstr.push_back(str);
	auto beg = vstr.begin();
	while (beg + 1 != vstr.end()) {
		if (*beg == *(beg + 1)) count++;
		beg++;
	}
	cout << count;
}
```

### 5.4.2节练习

#### 练习5.15

- **说明下列循环的含义并改正其中的错误。**

```c++
(a) for (int ix = 0; ix != sz; ++ix) { /*...*/ }
    if (ix != sz)
        // ...
(b) int ix;
    for (ix != sz; ++ix) { /*...*/ }
(c) for (int ix = 0; ix != sz; ++iz， ++ sz) { /*...*/ }

(a) 遍历结构体。if的含义不明。错误为for语句头中定义的对象只在for循环体内可见。故在if语句中ix是未定义的。
(b) 遍历结构体。for语句的头一句应该是初始化，缺少分号。改为 for (;ix != sz; ++ix) 
(c) 遍历结构体。将会导致死循环。删除sz自增的表达式。
```

#### 练习5.16

- **while 循环特别适用于那种条件不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于哪种？为什么？**

```c++
#include <iostream>
using namespace std;
int main()
{
	int i = 0, sum = 0;
	while (i <= 100){
		sum += i;
		++i;
	}
	for (int i = 0; i != 100; ++i)
		sum += i;
}
while循环。括号内更简洁，循环使用的变量结束循环后仍可使用。
```

#### 练习5.17

- **假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果为真。**

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v1 = { 0,1,1,2 }, v2 = { 0,1,1,2,3,5,8 };
	auto beg1 = v1.begin(), beg2 = v2.begin();
	string tag = "True";
	while (beg1 != v1.end() && beg2 != v2.end()) {
		if (*beg1 != *beg2) {
			tag = "False";
			break;
		}
		++beg1; ++beg2;
	}
	cout << tag;
}
```

### 5.4.4节练习

#### 练习5.18

- **说明下列循环的含义并改正其中的错误。**

```c++
(a) do 
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
(b) do {
        // . . .
    } while (ival = get_response());
(c) do {
        ival = get_response();
    } while (ival);

(a) 循环内有多条语句时，应使用花括号括起来，形成复合语句。
(b) 不允许在条件语句内定义变量，它将在被定义先被使用，这是不合理的。
(c) 条件语句使用的变量必须定义在循环体之外。而ival在循环体内被定义。不合法。
```

#### 练习5.19

- **编写一段程序，使用do while 循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。**

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string rsp;
	do {
		string str1 = "", str2 = "";
		cout << "Please enter two string:" << endl;
		cin >> str1 >> str2;
		if (str1.size() > str2.size()) cout << str2 << " is shorter." << "\n\n";
		else cout << str1 << " is shorter." << "\n\n";
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
}
```

### 5.5.1节练习

#### 练习5.20

- **编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。**

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vstr;
	string str;
	string exist_str;
	while (cin >> str) {
		vstr.push_back(str);
		if (exist_str == str)
			break;
		exist_str = str;
	}
	str = vstr[0];
	auto beg = vstr.begin() + 1;
	bool tag = false;
	while (beg != vstr.end()){
		if (str == *beg) {
			tag = true;
			break;
		}
		str = *beg;
		++beg;
	}
	if (tag) cout << str;
	else cout << "no repeat word.";
}
```

### 5.5.2节练习

#### 练习5.21

- **修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。**

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vstr;
	string str;
	string exist_str;
	while (cin >> str) {
		vstr.push_back(str);
		if (exist_str == str)
			break;
		exist_str = str;
	}
	str = vstr[0];
	auto beg = vstr.begin() + 1;
	bool tag = false;
	while (beg != vstr.end()){
		if (!isupper(str[0])) {   //不管首字母是否大写，迭代器必须继续指向下一个元素。
			str = *beg;
			++beg;
			continue;
		}
		if (str == *beg) {
			tag = true;
			break;
		}
		str = *beg;
		++beg;
	}
	if (tag) cout << str;
	else cout << "no repeat word.";
}
```

### 5.5.3节练习

#### 练习5.22

- **本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务，重写这段代码，注意不再使用goto语句。**

```c++
#include <iostream>
using namespace std;
int main()
{
	int sz = get_size();
	while (sz <= 0) sz = get_size();
}
```

### 5.6.3节练习

#### 练习5.23

- **编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。**

```c++
#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	cout << num1 / num2;
}
```

#### 练习5.24

- **修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？**

```c++
#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	if (num2 == 0) 
		throw runtime_error("ERROR! Division by zero!");
	cout << num1 / num2;
}
```

编译器提示该异常没有被处理，程序暂停。

#### 练习5.25

- **修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。** 

```c++
#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	while(cin >> num1 >> num2)
	    try {
		    if (num2 == 0) throw runtime_error("ERROR!Division by zero!");
		    cout << num1 / num2;
	    }catch (runtime_error err) {
			cout << err.what() << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') break;
	    }
}
```