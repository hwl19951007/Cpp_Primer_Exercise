## chapter13 拷贝、赋值与销毁

[TOC]

## 练习

### 13.1.1 节练习

#### 练习13.1

- **拷贝构造函数是什么？什么时候使用它？**

如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数。

1）拷贝初始化（使用 = 初始化）

2）类作为实参传递给非引用类型的形参

3）返回值类型为非引用类型的函数返回一个对象时

4）用花括号列表初始化一个数组中的元素或一个聚合类中的成员

5）初始化标准库容器或调用其insert或push成员，容器会对其元素进行拷贝初始化

#### 练习13.2

- **解释为什么下面的声明是非法的。**

```c++
Sales_data::Sales_data( Sales_data rhs );
```

类的拷贝构造函数的第一个参数必须是引用类型。因为其参数为非引用类型时，为了能够调用拷贝构造函数，就必须拷贝它的实参，但拷贝其实参时，我们又需要调用拷贝构造函数，将导致无限循环。

#### 练习13.3

- **当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？**

对类类型的成员，将会调用其拷贝构造函数进行拷贝，内置类型成员则将会直接拷贝。

StrBlob：其数据成员仅有一个shared_ptr，因此将会拷贝这个shared_ptr，且其计数器自增1。

StrBlobPtr：其数据成员有一个weak_ptr以及一个size_t类型，curr将直接拷贝，weak_ptr将调用其类的拷贝构造函数进行拷贝，不增加其计数器。

#### 练习13.4

- **假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数。**

- ```c++
    Point global;
    Point foo_bar( Point arg )  //用了一次拷贝构造函数（参数为自身类类型的引用）
    {
    	Point local = arg, *heap = new Point( global );  //用了两次拷贝构造函数 （=）
    	*heap = local;    //用了一次拷贝构造函数 （=）
    	Point pa[ 4 ] = { local, *heap };    //用了两次拷贝构造函数，两次用花括号列表初始化一个数组中的元素
    	return *heap;    //用了一次拷贝构造函数，从一个返回类型为非引用类型的函数返回一个对象
    }
    ```

#### 练习13.5

- **给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps指向的位置，而不是ps本身的位置。**

- ```c++
    class HasPtr{
    public:
    	HasPtr( const std::string &s = std::string() ) : 
    		ps( new std::string( s ) ), i(0) { }
    	HasPtr( const HasPtr &hp );
    private:
    	std::string *ps;
    	int i;
    };
    ```

```c++
HasPtr::HasPtr( const HasPtr & orig):
	ps( new std::string(*orig.ps) ), i(orig.i)  {  }
```

### 13.1.2 节练习

#### 练习13.6

- **拷贝赋值运算符是什么？什么时候使用它？合成拷贝赋值运算符完成什么工作？什么时候会生成合成拷贝赋值运算符？**

拷贝赋值运算符是一个重载的赋值运算符，它是类的成员函数，其左侧运算对象绑定到隐式的this参数。拷贝赋值运算符控制类对象如何赋值。拷贝赋值运算符接受一个与其所在类相同类型的参数，通常返回一个指向其左侧运算对象的引用。

当用类对象对类对象进行赋值时，会使用拷贝运算符。

对某些类，合成拷贝赋值运算符用于禁止该类型对象的赋值，若非出于此目的，它会将左侧运算对象的每个非static成员赋予左侧运算对象的对应成员。

如果一个类未定义自己的拷贝赋值运算符，编译器就会生成合成拷贝赋值运算符。

#### 练习13.7

- **当我们将一个StrBlob赋值给另一个StrBlob时，会发生什么？赋值StrBlobPtr呢？**

StrBlob：会通过shared_ptr类的拷贝赋值运算符将shared_ptr拷贝赋值，且其计数器自增。

StrBlobPtr：会通过weak_ptr类的拷贝赋值运算符将weak_ptr拷贝赋值。curr调用内置类型的赋值运算符。

#### 练习13.8

- **为13.1.1节练习13.5中的HasPtr类编写赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。**

```c++
class HasPtr{
public:
	HasPtr( const std::string &s = std::string() ) : 
		ps( new std::string( s ) ), i(0) { }
	HasPtr( const HasPtr &hp ) : ps( new std::string(*orig.ps) ), i(orig.i)  {  }
    HasPtr& operator=(const HasPtr &rhs_hp){
            if (this != &hp){    //判断是否将自身赋值给自身
    	auto temp_ps = new std::string( *hp.ps );
    	delete ps;    //删除原ps
    	ps = temp_ps;    //令ps指向新string
    	i = hp.i;
    }
    	return *this;
}
private:
	std::string *ps;
	int i;
};
```

### 13.1.3 节练习

#### 练习13.9

- **析构函数是什么？合成析构函数完成什么工作？什么时候会生成合成析构函数？**

析构函数释放对象使用的资源，并销毁对象的非static数据成员。析构函数是类的一个成员函数，名字由波浪号接类名构成，没有参数，没有返回值。

对于某些类，合成析构函数被用来阻止该类型的对象被销毁，如果不是这种情况，合成析构函数的函数体就为空。析构操作是在析构函数函数体执行完成后隐含执行的。

当一个类未定义自己的析构函数时，编译器会为它定义一个合成析构函数。

#### 练习13.10

- **当一个StrBlob对象被销毁时会发生什么？一个StrBlobPtr对象销毁时呢？**

StrBlob：合成析构函数的空函数体执行完成后，进入到隐含的析构阶段，调用shared_ptr的析构函数来销毁其指针，计数器减一，如果计数器为0，销毁其指向的对象。

StrBlobPtr：合成析构函数的空函数体执行完成后，进入到隐含的析构阶段，调用weak_ptr的析构函数销毁其指针。curr是内置类型，没有析构函数，销毁时什么也不会发生。

#### 练习13.11

- **为前面练习中的HasPtr类添加一个析构函数。**

```c++
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {  }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		if (this != &rhs_hp) {    //判断是否将自身赋值给自身
			auto temp_ps = new std::string(*rhs_hp.ps);
			delete ps;    //删除原ps
			ps = temp_ps;    //令ps指向新string
			i = rhs_hp.i;
		}
		return *this;
	}
    ~HasPtr(){    //析构函数
    delete ps;    //需要销毁指针指向的内容
    }
private:
	std::string *ps;
	int i;
};
```

#### 练习13.12

- **在下面的代码片段中会发生几次析构函数的调用？**

- ```c++
    bool fcn( const Sales_data *trans, Sales_data accum )
    {
    Sales_data item1( *trans ), item2( accum );
    return item1.isbn() != item2.isbn();
    }
    ```

一共三次。

局部变量item1, item2在函数fcn结束后销毁。accum作为复制的临时变量，在函数fcn结束后也被销毁。

trans作为指针，没有析构函数，同时也不会导致其指向的对象被销毁。

#### 练习13.13

- **理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，为该类定义这些成员，每个成员都打印自己的名字：**

- ```c++
    struct X {
    	X() { std::cout << "X()" << std::endl; }
    	X(const X&) { std::cout << "X(const X&)" << std::endl; }
    };
    ```

- **给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象：**

    **将它们作为非引用和引用参数传递；**

    **动态分配它们；**

    **将它们存放于容器中；**

    **诸如此类。观察程序的输出，直到你确认理解了什么时候用使用拷贝控制成员，以及为什么会使用它们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。**

```c++
#include <iostream>
#include <vector>

struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; }
	~X() { std::cout << "~X" << std::endl; }
};

void f(const X& xr, X x) {
	std::vector<X> vx;
	vx.push_back(xr);
	vx.push_back(x);    //不知道为什么此处会多拷贝赋值一个X并析构掉。
}
int main() {
	X *x = new X();
	f(*x, *x);
	delete x;
	return 0;
}
```

### 13.1.4 节练习

#### 练习13.14

- **假定numbered是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为mysn的数据成员中。假定numbered使用合成的拷贝控制成员，并给定如下函数：**

- ```c++
    void f( numbered s ) { cout << s.mysn << endl; }
    ```

- **则下面代码输出什么内容？**

- ```c++
    numbered a, b = a, c = b;
    f(a);f(b);f(c);
    ```

输出三个相同的数字。使用合成拷贝控制成员，只会拷贝其序号，而不会生成新的唯一的序号。

#### 练习13.15

- **假定numbered定义了一个拷贝构造函数，能生成一个新的序号。这会改变上一题中调用的输出结果吗？如果会改变，为什么？新的输出结果是什么？**

会改变。因为b和c的初始化方式是拷贝初始化，通常使用的就是拷贝构造函数，因此上一题的输出结果会改变。新的输出结果将变为三个不同的序号。对应的是abc三个实参拷贝生成的三个副本的mysn成员。

#### 练习13.16

- **如果f中的参数是const numered&， 将会怎样？ 这会改变输出结果吗？如果改变，为什么？**

会改变。因为将参数改为引用后，不会再将实参拷贝而是直接传入，因此输出的是abc三个类的mysn成员。

#### 练习13.17

- **分别编写前三题所描述的numbered和f，验证你是否正确预测了输出结果。**

```c++
#include <iostream>
using namespace std;

class numbered1 {
public:
	numbered1() { mysn = unique++; }
	int mysn;
	static int unique;
};
class numbered2 {
public:
	numbered2() { mysn = unique++; }
	numbered2(const numbered2&) { mysn = unique++; }
	int mysn;
	static int unique;
};
int numbered1::unique = 10;
int numbered2::unique = 20;

void f(numbered1 s) { cout << s.mysn << endl; }
void f(numbered2 s) { cout << s.mysn << endl; }
void fc(const numbered2& s) { cout << s.mysn << endl; }
int main() {
	numbered1 a , b = a, c = b;
	f(a); f(b); f(c);
	numbered2 d, e = d, g = e;
	f(d); f(e); f(g);
	fc(d); fc(e); fc(g);
}
```

### 13.1.6 节练习

#### 练习13.18

- **定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。**

```c++
class Employee {
public:
	Employee() { id = unique++; };
	Employee(const std::string& str) : name(str) { id = unique++; };
private:
	std::string name;
	int id;
	static int unique;
};
int static unique = 0;
```

#### 练习13.19

- **你的Employee类需要定义它自己的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。**

不需要。因为在现实世界中，雇员不可能真正被拷贝，因此其唯一的雇员证号也就没有必要因为拷贝而自增。在使用时，使用其引用即可。 将控制拷贝成员删除，避免没有意义的拷贝。

```c++
class Employee {
public:
	Employee() { id = unique++; };
	Employee(const std::string& str) : name(str) { id = unique++; };
	Employee(const Employee&) = delete;
	Employee& operator = (const Employee&) = delete;
private:
	std::string name;
	int id;
	static int unique;
};
```

#### 练习13.20

- **解释当我们拷贝、赋值或销毁TextQuery和QueryResult类对象时会发生什么？**

#### 练习13.21

- **你认为TextQuery和QueryResult类需要定义它们自己版本的拷贝控制成员吗？如果需要，为什么？如果不需要，为什么？实现你认为这两个类需要的拷贝控制操作。**

### 13.2 节练习

#### 练习13.22

- **假定我们希望HasPtr的行为像一个值。即，对于对象所指向的string成员，每个对象都有一份自己的拷贝。我们将在下一节介绍拷贝控制成员的定义。但是，你已经学习了定义这些成员所需的所有知识。在继续学习下一节之前为HasPtr编写拷贝构造函数和赋值运算符。**

```c++
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {  }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		if (this != &rhs_hp) {    //判断是否将自身赋值给自身
			auto temp_ps = new std::string(*rhs_hp.ps);
			delete ps;    //删除原ps
			ps = temp_ps;    //令ps指向新string
			i = rhs_hp.i;
		}
		return *this;
	}
    ~HasPtr(){    //析构函数
    delete ps;    //需要销毁指针指向的内容
    }
private:
	std::string *ps;
	int i;
}; 
```

### 13.2.1 节练习

#### 练习13.23

- **比较上一节练习中你编写的拷贝控制成员和这一节中的代码。确定你理解了你的代码和我们的代码之间的差异（如果有的话）。**

我的代码中增加了一个是否是在将自身赋值给自己的判断。这个判断可以省略。

#### 练习13.24

- **如果本节中的HasPtr版本未定义析构函数，将会发生什么？如果未定义拷贝构造函数，将会发生什么？**

如果没有定义析构函数，会导致ps指向的动态内存无法释放。

如果没有定义拷贝控制函数，会导致拷贝时拷贝的是指针本身，而非连同动态内存一起拷贝。其结果就是当其中一个类成员被销毁时，另一个类成员的ps将会变为空悬指针。

#### 练习13.25

- **假定希望定义StrBlob的类值版本，而且希望继续使用shared_ptr，这样我们的StrBlobPtr类就仍能使用指向vector的weak_ptr了。你修改后的类将需要一个拷贝构造函数和一个拷贝赋值运算符，但不需要析构函数。解释拷贝构造函数和拷贝赋值运算符必须要做什么。解释为什么不需要析构函数。**

因为需要的是类值版本，因此拷贝构造函数和拷贝赋值运算符需要令左侧运算对象获得一个新的底层vector，而不是令两者指向一个相同的底层vector。

因为StrBlob类内仅有一个shared_ptr成员，在类调用其合成析构函数就会再调用shared_ptr类的析构函数时，如果其计数器减至0了，就会将其指向的动态内存一同释放。已经能够保证资源分配、释放的正确性。

#### 练习13.26

- **对上一题描述的StrBlob类，编写你自己的版本。**

```c++
#ifndef StrBlob_h
#define StrBlob_h

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
	//拷贝构造函数
	StrBlob(const StrBlob& rhs) : data(std::make_shared<std::vector<std::string>>(*rhs.data)) { };
	//拷贝赋值运算符
	StrBlob& operator=(const StrBlob& rhs) { data = std::make_shared<std::vector<std::string>>(*rhs.data); return *this; };
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

ConstStrBlobPtr StrBlob::begin() const { 
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
	return ConstStrBlobPtr(*this, data->size());
}

#endif // StrBlob_h
```

### 13.2.2 节练习

#### 练习13.27

- **定义你自己的使用引用计数版本的HasPtr。**

```c++
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	//    拷贝构造函数拷贝所有三个数据成员，并递增计数器
	HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		++*rhs_hp.use;    //先自增右侧对象的计数器，再自减左侧对象计数器。来处理自赋值的情况。
		if (--*use == 0) {
			delete ps;    //需要销毁指针指向的内容
			delete use;
		}
		ps = rhs_hp.ps;
		i = rhs_hp.i;
		use = rhs_hp.use;
		return *this;
	}
	~HasPtr() {    //析构函数
		if (--*use == 0) {
			delete ps;    //需要销毁指针指向的内容
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use;    //用来记录有多少个对象共享*ps的成员
};
```

#### 练习13.28

- **给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员。**

```c++
(a)
class TreeNode {
private:
	std::string value;
	int *count;    // 此处应是指针
	TreeNode *left;
	TreeNode *right;
};
(b)
class BinStrTree {
private:
	TreeNode *root;
};
```

```c++
#include <string>

class TreeNode {
public:
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
	TreeNode& operator=(const TreeNode &rhs) {
		++*rhs.count;
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
		value = rhs.value;
		count = rhs.count;
		left = rhs.left;
		right = rhs.right;
		return *this;
	}
	~TreeNode() {
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
	}
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) { }
	BinStrTree(const BinStrTree& rhs) : root(new TreeNode(*rhs.root)) { }
	BinStrTree& operator=(const BinStrTree& rhs) {
		TreeNode *new_root = new TreeNode(*rhs.root);
		delete root;
		root = new_root;
		return *this;
	}
	~BinStrTree() {
		delete root;
	}
private:
	TreeNode *root;
};
```

### 13.3 节练习

#### 练习13.29

- **解释swap( HasPtr&, HasPtr& )中对swap的调用不会导致递归循环。**

```c++
inline void swap( Hasptr &lhs, HasPtr &rhs)
{   using std::swap;
    swap( lhs.ps, rhs.ps );
    swap( lhs.i, rhs.i );}
```

从代码可以知道，下面两个swap函数的参数分别是字符串指针和常数，并不是HasPtr&类型，自然不会导致递归循环。

#### 练习13.30

- **为你的类值版本的HasPtr编写swap函数，并测试它。为你的swap函数添加一个打印语句，指出函数什么时候执行。**

```c++
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {  }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		if (this != &rhs_hp) {    //判断是否将自身赋值给自身
			auto temp_ps = new std::string(*rhs_hp.ps);
			delete ps;    //删除原ps
			ps = temp_ps;    //令ps指向新string
			i = rhs_hp.i;
		}
		return *this;
	}
    ~HasPtr(){    //析构函数
    delete ps;    //需要销毁指针指向的内容
    }
    
private:
	std::string *ps;
	int i;
}; 
inline void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap" << std::endl;
}
```

#### 练习13.31

- **为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。为这个vector添加一些元素，并对它执行sort。注意何时调用swap。**

```c++
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {  }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		if (this != &rhs_hp) {    //判断是否将自身赋值给自身
			auto temp_ps = new std::string(*rhs_hp.ps);
			delete ps;    //删除原ps
			ps = temp_ps;    //令ps指向新string
			i = rhs_hp.i;
		}
		return *this;
	}    // <运算符
    bool operator<(const HasPtr &lhs, const HasPtr &rhs){
        return *lhs.ps < *rhs.ps;
    }
    ~HasPtr(){    //析构函数
    delete ps;    //需要销毁指针指向的内容
    }
    
private:
	std::string *ps;
	int i;
}; 
inline void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap" << std::endl;
}
```

#### 练习13.32

- **类指针的HasPtr版本会从swap函数受益吗？如果会，得到了什么益处？如果不是，为什么？**

自定义的swap的目的是为了减少swap过程中不必要的临时副本的创建，而类指针的HasPtr版本，仅有一个int类型可能需要创建临时副本，其余均是直接交换指针地址。因此基本不会得到益处。

### 13.4 节练习

#### 练习13.33

- **为什么Message的成员save和remove的参数是一个Folder&？为什么我们不将参数定义为Folder或者是const Folder&？**

将参数定义为Folder，那么save和remove将对副本进行操作，等于做无用功。

将参数定义为const Folder&，那么引用将无法被改变，将无法完成函数的功能。

#### 练习13.34

- **编写本节所描述的Message。**

```c++
#ifndef Message_h
#define Message_h

#include <set>
class Folder;

class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	// folder 被隐式初始化为空集合
	explicit Message(const std::string &str = "") : contents(str) {}  
	// 拷贝控制成员，用来管理指向本Message的指针
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	// 从给定Folder集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;    // 包含本Message的Folder
	// 拷贝控制成员所使用的的工具函数
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

class Folder { 
	friend class Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	// 拷贝控制成员
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder&);
	void remove_from_Message();
	void addMsg(Message *m) { msgs.insert(m); };
	void remMsg(Message *m) { msgs.erase(m); };
};

void Message::save(Folder &f) {
	folders.insert(&f);    // 将给定Folder添加到我们的Folder列表中
	f.addMsg(this);    // 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f) {
	folders.erase(&f);    // 将给定Folder从我们的Folder列表中删除
	f.remMsg(this);    // 将本Message从f的Message集合中删除
}
// 将本Message添加到指向m的Floder中
void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders)    // 对每个包含m的Folder
		f->addMsg(this);    // 向改Folder添加一个指向本Message的指针
}

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);    // 将本消息添加到指向M的Folder中
}

void Message::remove_from_Folders() {
	for (auto f : folders)    // 对folders中每个指针
		f->remMsg(this);    // 从该Folder中删除本Message
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
	// 通过先删除自身指针再插入它们来处理自赋值情况
	remove_from_Folders();    // 更新已有Folder
	contents = rhs.contents;    // 从rhs拷贝消息和Folder指针
	folders = rhs.folders;
	add_to_Folders(rhs);    // 将本Message添加到那些Folder中
	return *this;
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	// 将每个消息的指针从它（原来）所在的Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// 交换contents和Folder指针set
	swap(lhs.folders, rhs.folders);    // 使用swap(set&, set&)
	swap(lhs.contents, rhs.contents);    // 使用swap(string&, string&)
	// 将每个Message的指针添加到它的（新）Folder中
	lhs.add_to_Folders(lhs);    // 使用工具函数避免代码重复
	rhs.add_to_Folders(rhs);
}
// 将自身添加到参数Folder中的Message的Folder集合
void Folder::add_to_Message(const Folder &f) {
	for (auto m : f.msgs)
		m->addFldr(this);
}
// 将自身从自身的Message集合中删除
void Folder::remove_from_Message() {
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
	add_to_Message(f);
}

Folder::~Folder() {
	remove_from_Message();
}

Folder& Folder::operator=(const Folder&f) {
	remove_from_Message();    // 避免自赋值
	msgs = f.msgs;
	add_to_Message(f);
	return *this;
}

void swap(Folder &lhs, Folder &rhs) {
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

#endif // !Message_h

```

#### 练习13.35

- **如果Message使用合成的拷贝控制成员，将会发生什么？**

如果Message使用合成的拷贝控制成员，那么Folder将不会知道Message被拷贝或销毁了，会导致Folder中记录的Message数量与Folder中记录的不符合。

#### 练习13.36

- **设计并实现对应的Folder类。此类应该保存一个指向Folder中包含的Message的set。**

#### 练习13.37

- **为Message类添加成员，实现向 folders添加或删除一个给定的Folder*。这两个成员类似Folder类中的addMsg和remMsg操作。**

以上两题见13.34的代码。

#### 练习13.38

- **我们并未使用拷贝和交换的方式来设计Message的赋值运算符。你认为其原因是什么？**

没有动态内存的使用，因此使用拷贝和交换的方式并不能得到多少优化。另外我们Message的swap函数还会修改保存该Message的Folder中的成员，无法直接使用，需要修改。不值得为其再修改一个交换的函数，效率过低。

### 13.5 节练习

#### 练习13.39

- **编写你自己版本的StrVec，包括你自己版本的reserve、capacity 和 resize。**

```c++
#ifndef StrVec_h
#define StrVec_h

#include <allocators>
#include <string>
#include <initializer_list>

// 类vector类内存分配策略的简化实现
class StrVec {
public:
	// allocator成员进行默认初始化
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);               // 拷贝构造函数
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);    // 拷贝赋值运算符
	~StrVec();                           // 析构函数
	StrVec(StrVec &&rhs) noexcept;    // 移动构造函数
	StrVec& operator=(StrVec&&rhs) noexcept;    // 移动赋值运算符
	void push_back(const std::string&);  // 拷贝元素

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const std::string&);

private:
	static std::allocator<std::string> alloc;    // 分配元素
	std::string *elements;      // 指向数组首元素的指针
	std::string *first_free;    // 指向数组第一个空闲元素的指针
	std::string *cap;           // 指向数组尾后位置的指针

	// 被添加元素的函数所使用
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();                // 销毁元素并释放内存
	void reallocate();          // 获得更多内存并拷贝已有元素
	void alloc_n_move(size_t);    // 将元素移至扩增容量后的新内存地址的工具函数
	void range_initialize(const std::string*, const std::string*);
};

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();     // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	// 分配空间保存给定范围内的元素
	auto data = alloc.allocate(b - e);
	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	// 不能传递给deallcate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁元素
		for (auto p = first_free; p != elements;/* 空 */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::range_initialize(const std::string *first, const std::string *last) {
	auto newdata = alloc_n_copy(first, last);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s) {
	// 调用alloc_n_copy分配空间以容纳与 s 中一样多的元素
	range_initialize(s.begin(), s.end());
}

StrVec::StrVec(std::initializer_list<std::string> il) {
	range_initialize(il.begin(), il.end());
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec &rhs) {
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用的空间一样大
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
	rhs.elements = rhs.first_free = rhs.cap = nullptr;    // 使右值引用可以安全的被析构
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs)    // 直接检测自赋值
	{
        free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::alloc_n_move(size_t newcapacity) {
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 将数据从旧内存移动到新内存
	auto dest = newdata;          // 指向新数组中的下一个空闲 
	auto elem = elements;         // 指向旧数组中的下一个元素
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();     // 一旦我们移动完元素就释放旧内存空间
	// 更新我们的数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate() {
	// 我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t newcapacity) {
	if (newcapacity > capacity())     // 如果要求分配的空间小于等于已分配空间，不做改变
		alloc_n_move(newcapacity);
}

void StrVec::resize(size_t count) {
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &str) {
	if (count < size()) {
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
	else if (count > size()) {
		alloc_n_move(count * 2);
		while (first_free != elements + count)
			alloc.construct(first_free++, str);
	}
}

#endif // !StrVec_h
```

#### 练习13.40

- **为你的StrVec类添加一个构造函数，它接受一个initializer_list<string>的参数。**

见练习13.39

#### 练习13.41

- **在push_back中，我们为什么在construct调用使用前置递增运算？如果使用后置递增运算的话，会发生什么？**

我觉得用的是后置版本啊。。。为了在first_free位置创建新元素，因为first_free的位置就是一般意义上的尾后位置，因此先再first_free位置创建新元素再向后移动才是合理的。用前置版本，将会先移动first_free，再在移动后的位置上创建新元素，就不合理了。

#### 练习13.42

- **在你的TextRequery和QueryResult类中用你的StrVec类代替vector<string>，以此来测试你的StrVec类。**

没做，略。

#### 练习13.43

- **重写free成员，用for_each和lambda来代替for循环destroy元素。你更倾向于哪种实现？为什么?**

```c++
for_each(elements, first_free, [](std::string &s){ alloc.destroy(&s); });
```

for_each的实现，更简洁，可读性更强，也不需要人为控制指针，减少了出错的可能性。

#### 练习13.44

- **编写标准库string类的简化版本，命名为String。你的类至少有一个默认构造函数和一个接受C风格字符指针参数的构造函数。使用allocator为你的String类分配所需内存。**

```c++
#ifndef String_h
#define String_h

#include <memory>
#include <algorithm>
#include <iostream>

class String{
public:
	String(): String("") {}    // 委托构造函数
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&)noexcept;    // 移动构造函数
	String& operator=(String&&)noexcept;    // 移动赋值运算符
	~String();
private:
	char *elements;
	char *end;
	static std::allocator<char> alloc;

	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void print();
};

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b,e,data) };
}

String::String(const char* c) {
	auto e = c;
	while (*e != '\0') e++;    // 找到字符串的长度
	e++;
	auto data = alloc_n_copy(c, e);
	elements = data.first;
	end = data.second;
	print();
}

String::String(const String &rhs) {
	auto data = alloc_n_copy(rhs.elements, rhs.end);
	elements = data.first;
	end = data.second;
	print();
}

void String::free() {
	if (elements) {
		std::for_each(elements, end, [](char &c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}

String& String::operator=(const String &rhs) {
	auto data = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = data.first;
	end = data.second;
	return *this;
}

String::~String() { free(); }

String::String(String &&rhs) noexcept : elements(rhs.elements), end(rhs.end) {
	rhs.elements = rhs.end = nullptr;    // 将右侧对象置为可析构的状态
}

String& String::operator=(String &&rhs) noexcept {
	if (this != &rhs) {    // 检测自赋值
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}
void String::print() {
	std::cout << "This is a String." << std::endl;
}
#endif // !StrVec_h
```

### 13.6.1 节练习

#### 练习13.45

- **解释右值引用和左值引用的区别。**

右值引用用&&来获取，它是必须绑定到右值的引用，只能绑定到一个将要销毁的对象。

左值引用（即常规引用）不能绑定到要求转换的表达式、字面常量或返回右值的表达式，而右值引用则相反。

左值引用用以保存持久的状况。而右值引用要么是保存字面常量，要么是表达式求值过程中创建的临时变量。

#### 练习13.46

- **什么类型的引用可以绑定到下面的初始化器上？**

- ```c++
    int f();
    vector<int> vi(100);
    int? r1 = f();
    int? r2 = vi[0];
    int? r3 = r1;
    int? r4 = vi[0] * f();
    ```

```c++
int&& r1 = f();           // f()返回右值，因此需以右值引用来绑定
int& r2 = vi[0];          // 变量表达式，以左值引用绑定
int& r3 = r1;             // 绑定了右值引用的变量，以左值引用绑定
int&& r4 = vi[0] * f();    // 返回右值的表达式，以右值引用绑定
```

#### 练习13.47

- **对你在练习13.44中定义的String类，为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行时打印一条信息。**

已添加在练习13.44中。

#### 练习13.48

- **定义一个vector<String>并在其上多次调用push_back。运行你的程序，并观察String被拷贝了多少次。**

略。

### 13.6.2 节练习

#### 练习13.49

- **为你的StrVec、String和Message类添加一个移动构造函数和一个移动赋值运算符。**

StrVec见练习13.39。String见练习13.44。Message略。

#### 练习13.50

- **在你的String类的移动的操作中添加打印语句，并重新运行13.6.1节的练习13.48中的程序，它使用了一个vector<String>，观察什么时候会避免拷贝。**

返回右值的时候。

#### 练习13.51

- **虽然unique_ptr不能拷贝，但我们在12.1.5节中编写了一个clone函数，它以值方式返回一个unique_ptr。解释为什么函数是合法的，以及为什么它能工作。**

因为以值方式返回的unique_ptr是右值，因此在返回它时，它会调用unique_ptr内的移动构造函数或移动赋值运算符来接管此函数中unique_ptr变量的所属权，因此是合法的。

#### 练习13.52

- **详细解释第478页中HasPtr对象的赋值发生了什么？特别是，一步一步描述hp、hp2以及HasPtr的赋值运算符中的参数rhs的值发生了什么变化？**

对于hp = hp2:

hp2是一个左值，因此在参数传递时，构造形参rhs调用的是拷贝构造函数，rhs将获得hp2的一个副本，rhs和hp2是独立的，而且string的内容相同。赋值结束后，rhs被销毁。

对于hp = std::move(  hp2 );

构造rhs的时候调用的是移动构造函数，rhs接管hp2的所有权，然后swap交换this和rhs的指针，rhs指向this中数据成员原来指向的string，而this数据成员指向hp2指向的string。

#### 练习13.53

- **从底层效率的角度看，HasPtr的赋值运算符并不理想，解释为什么。为HasPtr实现一个拷贝赋值运算符和一个移动赋值运算符，并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中执行的操作。**

因为当赋值运算符获得一个右值引用时，它依然会先拷贝一个对象，再进行交换操作，而不是直接与右值引用进行交换。

#### 练习13.54

- **如果我们为HasPtr定义了移动赋值运算，但未改变拷贝并交换运算符，会发生什么？编写代码验证你的答案。**

编译不通过。

```c++
error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type { aka HasPtr }')
hp1 = std::move(*pH);
```

### 13.6.3 节练习

#### 练习13.55

- **为你的StrBlob添加一个右值引用版本的push_back。**

```c++
void push_back(string &&t) { data->push_back(std::move(t)); }
```

#### 练习13.56

- **如果sorted定义如下，会发生什么：**

- ```c++
    Foo Foo::sorted() const & {
        Foo ret(*this);
        return ret.sorted();
    }
    ```

    因为通过拷贝构造函数生成的ret是一个左值，因此会继续调用当前版本的sorted函数，直至内存泄露。

#### 练习13.57

- **如果sorted定义如下，会发生什么：**

- ```c++
    Foo Foo::sorted() const & { return Foo(*this).sorted(); }
    ```

Foo(*this)返回的是临时变量，是一个右值，因此会正确调用右值引用版本的sorted。

#### 练习13.58

- **编写新版本的Foo类，其sorted函数中有打印语句，来验证你对前面两题的答案是否正确。**

略