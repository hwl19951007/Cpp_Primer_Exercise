## chapter12 动态内存

[TOC]

## 练习

### 12.1.1 节练习

#### 练习12.1

- **在此代码的结尾，b1 和 b2 各包含多少个元素？**

- ```c++
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    ```

b1原智能指针销毁，改为指向b2指向的动态内存。和b2一样包含4个元素。

#### 练习12.2

- **编写你自己的StrBlob 类，包含const 版本的 front 和 back。**

```c++
#include <string>
#include <vector>
#include <memory>
#include <exception>

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加删减元素
	void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() {check(0, "pop_back on empty StrBlob");
	data->pop_back();}
	// 元素访问
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
private:
	std::shared_ptr < std::vector<std::string>> data;
	// 如果data[i]不合法，抛出一个异常
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
```

#### 练习12.3

- **StrBlob 需要const 版本的push_back 和 pop_back吗？如果需要，添加进去。否则，解释为什么不需要。**

可以，但不需要。

先说可以，因为类的数据成员仅是一个智能指针，因此当使用常量版本时，该指针是固定的，但其指向的内容依然是可以改变的，因此const版本的写入操作是可以实行的。因此，是可以添加const版本的上述两个函数的。

而看待该题需从类的使用者角度来考虑。

对于用户来说，他顶一个一个const版本的类对象，则理应无法对该对象进行写入操作。因此不需要const版本的写入函数，以免对使用者带来多余的困扰。

豆瓣讨论链接：https://www.douban.com/group/topic/61573279/

#### 练习12.4

- **在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？**

因为size_type是无符号类型，一定大于等于0。

#### 练习12.5

- **我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。**

优点：可以进行隐式转换，使用时更灵活。

缺点：可能会让使用者误以为可以数据成员的类型比实际上的多。隐式转换将会多消耗一部分资源。

### 12.1.2 节练习

#### 练习12.6

- **编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。**

```c++
#include <iostream>
#include <vector>
using namespace std;

vector<int>* build() {
	vector<int> *p(new vector<int>());
	return p;
}
vector<int>* write(vector<int> *p) {
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void read(vector<int> *p) {
	for (int i : *p)
		cout << i << endl;
	delete p;
}
int main() {
	read(write(build()));
	return 0;
}
```

#### 练习12.7

- **重做上一题，这次使用 shared_ptr 而不是内置指针。**

```c++
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> build() {
	auto p = make_shared<vector<int>>();
	return p;
}
shared_ptr<vector<int>>  write(shared_ptr<vector<int>> p) {
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void read(shared_ptr<vector<int>> p) {
	for (int i : *p)
		cout << i << endl;
}
// 使用智能指针则无需注重释放内存，在read函数内，p作为函数内的局部变量，将被自动销毁
int main() {
	read(write(build()));
	return 0;
}
```

#### 练习12.8

- **下面的函数是否有错误？如果有，解释错误原因。**

- ```c++
    bool b() 
    {
        int* p = new int;
        // ...
        return p;
    }
    ```

有错误。p在被转化成bool类型后，将没有机会再被释放。将会导致内存泄露。

#### 练习12.9

- **解释下面代码执行的结果。**

- ```c++
    int *q = new int(42), *r = new int(100);
    r = q;
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;
    ```

r指向的动态内存保留，但指针被销毁，因此将会导致动态内存泄露。

r2被赋值给q2之后，r2指向的动态内存计数器清零，动态内存被销毁。

### 12.1.3 节练习

#### 练习12.10

- **下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？**

- ```c++
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    ```

正确的。`share_ptr<int>(p)`的作用将返回一个p的临时拷贝，而此时计数器会相应得增加到2。离开函数空间后，局部变量将被销毁，计数器也降回至1。

#### 练习12.11

- **如果我们像下面这样调用 process，会发生什么？**

- ```c++
    process(shared_ptr<int>(p.get()));
    ```

将会构造一个由get初始化的share_ptr对象。由于这个对象是由get获得的内置指针构造的，因此两者的计数器是分开的，因此当离开函数局部空间后，动态内存将被delete，导致p成为空置指针。而在程序运行完毕后，p将被编译器自动再次delete，将会导致指向的动态内存被二次销毁。

#### 练习12.12

- **p 和 q 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：**

- ```c++
    auto p = new int();
    auto sp = make_shared<int>();
    (a) process(sp);
    (b) process(new int());
    (c) process(p);
    (d) process(shared_ptr<int>(p));
    (a) 合法，将sp作为参数传递给了process.
    (b) 不合法，内置指针不能隐式转换成智能指针
    (c) 同上
    (d) 合法，但将会导致p指针指向的动态内存在离开函数局部空间后就被销毁
    ```

#### 练习12.13

- **如果执行下面的代码，会发生什么？**

- ```c++
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;
    ```

sp成为一个空置指针，其指向的动态内存已被销毁。

### 12.1.4 节练习

#### 练习12.14

- **编写你自己版本的用 shared_ptr 管理 connection 的函数。**

```c++
void end_connection(connection *p) { disconnection(*p); }
void f(destination &d /* 其他参数 */){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
}
```

#### 练习12.15

- **重写第一题的程序，用 lambda （参见10.3.2节，第346页）代替end_connection 函数。**  

```c++
void f(destination &d /* 其他参数 */){
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [] (connection *p){ disconnection(*p); } ) ;
}
```

### 12.1.5 节练习

#### 练习12.16

- **如果你试图拷贝或赋值 unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。**

```c++
error C2280: “std::unique_ptr<int,std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)”: 尝试引用已删除的函数
```

#### 练习12.17

- **下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。**

- ```c++
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    (a) IntP p0(ix);
    (b) IntP p1(pi);
    (c) IntP p2(pi2);
    (d) IntP p3(&ix);
    (e) IntP p4(new int(2048));
    (f) IntP p5(p2.get());
    
    (a) 不合法，必须绑定到一个new返回的指针上
    (b) 能通过编译，但可能出错。因为pi不是new出来的，因此在离开作用域后指针调用delete时会报错。
    (c) 能通过编译，但可能出错。因为当p2离开作用域后会delete掉动态内存，此时pi2就是空置指针了。
    (d) 能通过编译，但可能出错。因为&ix不是new出来的，因此在离开作用域后指针调用delete时会报错。
    (e) 合法。
    (f) 能通过编译，但可能出错。当P2或P5delete动态内存后，另一个指针就是空置指针了。还会引发二次delete的问题。
    ```

#### 练习12.18

- **shared_ptr 为什么没有 release 成员？**

release操作将释放指向的对象并返回指针，而share_ptr可能拥有多个指向同一个对象的指针，此时就会导致其他指针成为空置指针。将会出现不必要的问题。

### 12.1.6 节练习

#### 练习12.19

- **定义你自己版本的 StrBlobPtr，更新 StrBlob 类，加入恰当的 friend 声明以及 begin 和 end 成员。**

```c++
#include <string>
#include <vector>
#include <memory>
#include <exception>
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加删减元素
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back() 
	{check(0, "pop_back on empty StrBlob");
		data->pop_back();}	
	// 元素访问
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr < std::vector<std::string>> data;
	// 如果data[i]不合法，抛出一个异常
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr(); //前缀递增
	bool operator!=(const StrBlobPtr &a) { return a.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();    // vector还存在吗
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;    // 一切正常，返回指向vector的shared_ptr
}

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {    // 前缀递增，返回递增后对象的引用
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size()); 
}
```

#### 练习12.20

- **编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。**

```c++
#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.h"
using namespace std;

int main() {
	ifstream file("Text.txt");
	StrBlob s;
	string str;
	while (getline(file, str))
		s.push_back(str);
	for (auto begin = s.begin(); begin != s.end(); begin.incr())
		cout << begin.deref() << endl;
	return 0;
}
```

#### 练习12.21

- **也可以这样编写 StrBlobPtr 的 deref 成员：**

- ```c++
    std::string& deref() const {
    return (*check(curr, "dereference past end"))[curr];
    }
    ```

原版，可读性更强。

#### 练习12.22

- **为了能让 StrBlobPtr 使用 const StrBlob，你觉得应该如何修改？定义一个名为ConstStrBlobPtr 的类，使其能够指向 const StrBlob。**

修改构造函数使其接受const StrBlob&。修改begin和end函数为const 成员函数。

```c++
#include <string>
#include <vector>
#include <memory>
#include <exception>
class ConstStrBlobPtr;

class StrBlob {
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加删减元素
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back() 
	{check(0, "pop_back on empty StrBlob");
		data->pop_back();}	
	// 元素访问
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	ConstStrBlobPtr begin() const;     //两个函数改为const成员函数
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr < std::vector<std::string>> data;
	// 如果data[i]不合法，抛出一个异常
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}    // 接受参数改为const StrBlob&
	const std::string& deref() const;    //根据逻辑，此处的返回值应为const
	ConstStrBlobPtr& incr(); //前缀递增
	bool operator!=(const ConstStrBlobPtr &a) { return a.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();    // vector还存在吗
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;    // 一切正常，返回指向vector的shared_ptr
}

const std::string& ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {    // 前缀递增，返回递增后对象的引用
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr StrBlob::begin(){
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() {
	return ConstStrBlobPtr(*this, data->size());
}
```

### 12.2.1 节练习

#### 练习12.23

- **编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象。**

```c++
#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4996)   //关闭 strcpy不安全错误。

int main() {
	char* char1 = new char[strlen("Hello" "world") + 1](); // +1为 '\0'
	strcpy(char1, "Hello ");
	strcat(char1, "world");
    delect[] char1;
	cout << char1 << endl;
	string str1{ "Hello " }, str2{ "world" };
	cout << str1 + str2 << endl;
}
```

#### 练习12.24

- **编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。**

```c++
#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4996)   //关闭 strcpy不安全错误。

int main() {
	string str;
	char* chars = new char[2]();    // 动态数组自动增长
	cin >> str;
	strcpy(chars, str.c_str());
	cout << chars << endl;
	delete[] chars;
}
```

#### 练习12.25

- 给定下面的new表达式，你应该如何释放pa？

- ```c++
    int *pa = new int[10];
    ```

```c++
delete[] pa;
```

### 12.2.2 节练习

#### 练习12.26

- **用allocator重写第427页中的程序。**

```c++
#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main() {
	int n = 5;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	alloc.deallocate(p, n);
}
```

------

要找工作了，后面这具体的项目实践就不做了，过基础要紧。

有机会再回头完成。