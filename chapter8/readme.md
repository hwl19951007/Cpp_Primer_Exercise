## chapter8 IO库

[TOC]

## 练习

### 8.1.2 节练习

#### 练习8.1

- **编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。**

```c++
#include <iostream>
#include <string>
using namespace std;
istream& func(istream &is) {
	string str;
	while (!is.eof() && is >> str ) {    //优先判断是否输入结束标识符
		cout << str;
	}
	is.clear();
	return is;
}
int main() {
	func(cin);
}
```

#### 练习8.2

- **测试函数，调用参数为cin。**

如上。

#### 练习8.3

- **什么情况下，下面的while循环会终止？**

```c++
while (cin >> i) /*...*/
```

当输入的是一个错误的状态时，循环会终止；如eofbit,failbit和badbit。

输入的不是类型i时，输入文件停止符时，输入终止符时等。

### 8.2.1 节练习

#### 练习8.4

- **编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。**

```c++
#include <fstream>
int main(int argc,char *argv[]){
    ifstream in(argv[1]);
    vector<string> v;
    if (in){
        string s;
        while(getline(in, s)){
            v.push_back(s);
        }else{
            cerr << "got wrong filename." << endl;
        }
    }
    return 0;
}
```

#### 练习8.5

- **重写上面的程序，将每个单词作为一个独立的元素进行存储。**

```c++
#include <fstream>
int main(int argc,char *argv[]){
    ifstream in(argv[1]);
    vector<string> v;
    if (in){
        string s;
        while(in >> s){
            v.push_back(s);
        }else{
            cerr << "got wrong filename." << endl;
        }
    }
    return 0;
}
```

#### 练习8.6

- **重写7.1.1节的书店程序(第229页)，从一个文件中读取交易记录。将文件名作为一个参数传递给main（参见6.2.5节，第196页）。**

```c++
int main(int argc,char *argv[]){
    Sales_data total;
    ifstream in(argv[1]);
    if (in){
		if (read(in, total)) {
			Sales_data trans;
			while(read(in ,trans)) {
				if(total.isbn() == trans.isbn())
					total.combine(trans);
				else {
					print(cout, total) << endl;
					total =trans;
				}
			}
			print(cout, total)<<endl;
		}
		else {
			cerr<<" No data?!"<<endl;
		}
    }
    return 0;
}
```

### 8.2.2 节练习

#### 练习8.7

- **修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。**

```c++
int main(int argc,char *argv[]){
    Sales_data total;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if (in){
		if (read(in, total)) {
			Sales_data trans;
			while(read(in ,trans)) {
				if(total.isbn() == trans.isbn())
					total.combine(trans);
				else {
					print(out, total) << endl;
					total =trans;
				}
			}
			print(out, total)<<endl;
		}
		else {
			cerr<<" No data?!"<<endl;
		}
    }
    return 0;
}
```

#### 练习8.8

- **修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。**

```c++
int main(int argc,char *argv[]){
    Sales_data total;
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    if (in){
		if (read(in, total)) {
			Sales_data trans;
			while(read(in ,trans)) {
				if(total.isbn() == trans.isbn())
					total.combine(trans);
				else {
					print(out, total) << endl;
					total =trans;
				}
			}
			print(out, total)<<endl;
		}
		else {
			cerr<<" No data?!"<<endl;
		}
    }
    return 0;
}
```

### 8.3.1 节练习

#### 练习8.9

- **使用你为8.1.2节（第281页）第一个练习所编写的函数打印一个istringstream对象的内容。**

#### 练习8.10

- **编写程序，将来自一个文件中的行保存在一个vector<string>中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。**

```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	vector<string> v;
	fstream in(argv[1]);
	if (in) {
		string line;
		while (getline(in, line)) {
			cout << line << endl;
			v.push_back(line);
		}
	}
	string oneWord;
	for (const string& s : v) {
		istringstream word(s);
		while (word >> oneWord) {
			cout << oneWord << endl;
		}
	}
}

```

#### 练习8.11

- **本节的程序在外层while循环中定义了istringstream 对象。如果record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。**

```c++
struct PersonInfo {
	string name;
	vector<string> phones;
};
int main(int argc, char const *argv[]) {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	return 0;
}

```

#### 练习8.12

- **我们为什么没有在PersonInfo中使用类内初始化。**

每个人的号码数量不同，默认初始化有利于后续添加号码，减少计算开销。

### 8.3.3 节练习

#### 练习8.13

- **重写本节的电话号码程序，从一个命名文件而非cin读取数据。**

```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const string& str) {
	return (str.size() > 0) ? true : false;
}
string format(const string& str) {
	return str;
}
int main(int argc, char const *argv[]) {
	string line, word;
	vector<PersonInfo> people;
	ifstream in(argv[1]);
	while (getline(in, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	ostringstream os;
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			os << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
	cout << os.str() << endl;
	return 0;
}

```

#### 练习8.14

- **我们为什么将entry和nums定义为const auto&？**

避免不必要的string类型的复制，同时因为是引用，需要加上常量避免被误操作修改原string。