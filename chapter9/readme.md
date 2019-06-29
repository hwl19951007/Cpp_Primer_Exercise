## chapter9 顺序容器

[TOC]

## 练习

### 9.1 节练习

#### 练习9.1

- **对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。**

(a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
(b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
(c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

（a）list。由于要求按字典顺序插入到容器中，因此需要进行中间插入，使用list较为合适。

（b）deque。由于需要在头部和末尾进行插入和删除操作，而deque是最适合的。

（c）vector。需要对读入容器中的数量进行排序，而vector支持随机访问，更适合用于此任务。

### 9.2 节练习

#### 练习9.2

- **定义一个list对象，其元素类型是int的deque。**

`list<deque<int>> lst;`

### 9.2.1 节练习

#### 练习9.3	

- **构成迭代器范围的迭代器有何限制？**

begin和end必须均指向同一个容器中的元素或尾元素之后的位置。且end不在begin之前。

#### 练习9.4

- **编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。**

```c++
bool func(vector<int>::iterator first, vector<int>::iterator secornd, int val){
    if (first < second){
        vector<int>::iterator begin = first, end = second;
    }else{
        vector<int>::iterator begin = second, end = first;
    }
    while(begin <= end){    //begin和end可能指向同一个目标
        if (*begin == val)
            return true;
        ++begin;
    }
    return false;    //如果循环结束依然没有返回值，说明迭代器范围内没有给定的值
}
```

#### 练习9.5

- **重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。**

```c++
int func(vector<int>::iterator first, vector<int>::iterator secornd, int val){
    if (first < second){
        vector<int>::iterator begin = first, end = second;
    }else{
        vector<int>::iterator begin = second, end = first;
    }
    while(begin <= end){    //begin和end可能指向同一个目标
        if (*begin == val)
            return *begin;
        ++begin;
    }
    return -1;    //如果循环结束依然没有返回值，说明迭代器范围内没有给定的值。用-1代表失败。
}
```

#### 练习9.6

- **下面程序有何错误？你应该如何修改它？**

```c++
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

list不是随机访问容器，因此迭代器没有重载小于运算符，故不能使用`iter1 < iter2`的形式。

改为`iter1 != iter2`。

### 9.2.2 节练习

#### 练习9.7

- **为了索引int的vector中的元素，应该使用什么类型？**

`vector<int>::size_type`



#### 练习9.8

- **为了读取string的list中的元素，应该使用什么类型？如果写入list，又应该使用什么类型？**

`list<string>::const_reference`

`list<string>::reference`

### 9.2.3 节练习

#### 练习9.9

- **begin和cbegin两个函数有什么不同？**

当使用auto类型时，cbegin必定返回常量类型，而begin则依据容器类型决定返回常量类型或非常量类型。

#### 练习9.10

- **下面4个对象分别是什么类型？**

```c++
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
it1 是vector<int>::iterator。
it2 是vector<int>::const_iterator。
//但由于auto仅能作为一种类型使用，而it1和it2不是同一种类型，因此将发生编译错误。！！！
it3 是vector<int>::const_iterator。
it4 是vector<int>::const_iterator。
```

### 9.2.4 节练习

#### 练习9.11

- **对6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值。**

```c++
vector<int> v1;             //默认初始化，不包含任何内容
vector<int> v2 = {1,2,3};   //初始化为列表中的拷贝。包含1,2,3这3个int值。
vector<int> v3 = v2;        //初始化为另一个vector对象的拷贝。包含1,2,3这3个int值。
vector<int> v4(v3.begin(), v3.end());    //初始化为两个迭代器指定范围内的元素的拷贝。同上。
vector<int> v5(3);          //包含3个元素，进行了值初始化。3个值为0的int值。
vector<int> v6(3, 3);       //包含3个值为3的元素。
```

#### 练习9.12

- **对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。**

接受容器创建其拷贝的构造函数，其元素类型和容器类型均必须相同。

接受两个迭代器创建拷贝的构造函数，其容器不一定相同，同时其元素类型也可以不相同，只要能够转换成所需的元素类型即可。

#### 练习9.13

- **如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。**

```c++
list<int> lst(2,2);
vector<int> vi(2,2);
vector<double> v1(lst.begin(), lst.end());
vector<double> v2(vi.begin(), vi.end());
```

### 9.2.5 节练习

#### 练习9.14

-  **编写程序，将一个list中的char *指针（指向C风格字符串）元素赋值给一个vector中的string。**

```c++
int main() {
	char ca1[] = "Hello, World.";
	list<char *> lst(1, ca1);
	vector<string> v;
	v.assign(lst.begin(), lst.end());
	cout << *v.begin() << endl;
	return 0;
}
```

### 9.2.7 节练习

#### 练习9.15

-  **编写程序，判定两个vector<int>是否相等。**

```c++
bool compare(const vector<int>& v1, const vector<int>& v2){
    bool result = true;
    if (v1.size() == v2.size()){
        vector<int>::const_iterator begin1 = v1.begin(), begin2 = v2.begin();
        while(begin1 != v1.end()){
            if (*begin1 != *begin2){
                result = false;
                break;
            }
            ++begin1, ++begin2;
        }
    }
    return result;
}
```

#### 练习9.16

-  **重写上一题的程序，比较一个list中的元素和一个vector中的元素。**

```c++
bool compare(const list<int>& lst1, const vector<int>& v2) {
	bool result = true;
	if (lst1.size() == v2.size()) {
		list<int>::const_iterator begin1 = lst1.begin();
		vector<int>::const_iterator begin2 = v2.begin();
		while (begin1 != lst1.end()) {
			if (*begin1 != *begin2) {
				result = false;
				break;
			}
			++begin1, ++begin2;
		}
	}
	return result;
}
```

#### 练习9.17

-  **假定c1和c2是两个容器，下面的比较操作有何限制（如果有的话）？**

```c++
if (c1 < c2)
```

首先，c1,c2不可以是无序关联容器。其次，c1,c2必须是保存相同类型的元素的相同类型的容器。

### 9.3.1 节练习

#### 练习9.18

- **编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。**

```c++
int main(){
    string str;
    deque<string> deq;
    while(cin >> str)
        deq.push_back(str);
    deque<string>::const_iterator iter = deq.begin();
    while (iter != deq.end()){
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}
```

#### 练习9.19

- **重写上题的程序，用list替代deque。列出程序要做出哪些改变。**

```c++
int main(){
    string str;
    list<string> deq;
    while(cin >> str)
        deq.push_back(str);
    list<string>::const_iterator iter = deq.begin();
    while (iter != deq.end()){
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}
```

不做任何改变，用list替代deque即可。

#### 练习9.20

- **编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。**

```c++
int main(){
    list<int> lst = {1,2,3,4,5,6,7,8,9,10};
    deque<int> odd, even;
    list<int>::iterator iter = lst.begin();
    while (iter != lst.end()){
        if (*iter % 2 == 1)
            odd.push_back(*iter);
        else
            even.push_back(*iter);
		++iter;
    }
    return 0;
}
```

#### 练习9.21

- **如果我们将第308页中使用insert返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。**

循环依然等价于调用push_front，将标准输入的字符依次插入vector的头部，但将非常耗时。

#### 练习9.22

- **假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？**

```c++
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

1.迭代器在循环中没有自增，将始终原地踏步。

2.当iv成功插入新元素后，iter，mid都将失效。

修改如下。

```c++
	vector<int>::iterator iter = iv.begin();
	auto half = iv.size() >> 1;
	while ((iv.end() - iter) >  half ) {    //利用距离替代mid来判断
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;    //如果插入了新元素，多向后迭代一步
		}
		++iter;
	}
```

### 9.3.2 节练习

#### 练习9.23

- **在本节第一个程序（第309页）中，若c.size()为1，则val、val2、val3和val4的值会是什么？**

均为c中的第一个元素。

#### 练习9.24

- **编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。在一个空vector上测试你的程序。**

```c++
int main(){
    vector<int> v;
    int val1 = v.at(0); // terminating with uncaught exception of type std::out_of_range
    int val2 = v[0];          // Segmentation fault: 11
    int val3 = v.front();     // Segmentation fault: 11
    int val4 = *v.begin();    // Segmentation fault: 11
    return 0;
}
```

### 9.3.3 节练习

#### 练习9.25

- **对于第312中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？**

如果elem1与elem2相等，则删除区间为0，故将不删除元素。

如果elem2是尾后迭代器，则删除elem1及之后的全部元素。

若均为尾后迭代器，则不删除元素。

#### 练习9.26

- **使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。**

- ```c++
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    ```

```c++
int main() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> v;
	list<int> lst;
	for (int i : ia) {
		v.push_back(i);
		lst.push_back(i);
	}
	vector<int>::iterator iterV = v.begin();
	while (iterV != v.end()) {
		if (*iterV % 2 != 1)
			iterV = v.erase(iterV);
		else
			++iterV;
	}
	list<int>::iterator iterL = lst.begin();
	while (iterL != lst.end()) {
		if (*iterL % 2)
			iterL = lst.erase(iterL);
		else
			++iterL;
	}
}
```

### 9.3.4 节练习

#### 练习9.27

- **编写程序，查找并删除forward_list<int>中的奇数元素。**

```c++
int main(){
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()){
        if (*curr % 2)
            curr = flst.erase_after(prev);    //通过前驱删除当前元素
        else{
            prev = curr;
            ++curr;
        }
    }
    for (auto i : flst)
        cout << i;
}
```

#### 练习9.28

- **编写函数，接受一个forward_list<string>和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。**

```c++
void func(forward_list<string> &flst, string str1, string str2) {
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr == str1) {
			curr = flst.insert_after(curr, str2);
			return;
		}
		else {
			prev = curr;
			++curr;
		}
	}
	flst.insert_after(prev, str2);
}
```

### 9.3.5 节练习

#### 练习9.29

- **假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？**

会默认初始化75个元素添加到vec的末尾。

会将vec中的后90个元素删除。

#### 练习9.30

- **接受单个参数的resize版本对元素类型有什么限制（如果有的话）？**

元素类型必须提供一个默认构造函数。

### 9.3.6 节练习

#### 练习9.31

- **第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。**

list和forward_list不支持随机访问，因此其迭代器也不支持+=2的加减运算。其原因在于链表类型容器的元素存储是不连续的，无法通过增加固定的数字来移动迭代器。

```c++
//forward_list
int main() {
	forward_list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = lst.begin();
	auto prev = lst.before_begin();
	while (curr != lst.end()) {
		if (*curr % 2) {
			lst.insert_after(prev, *curr);
			prev = curr;
			++curr;
		}
		else
			curr = lst.erase_after(prev);
	}
	for (auto i : lst)
		cout << i << endl;
}
//list
int main() {
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = lst.begin();
	while (curr != lst.end()) {
		if (*curr % 2) {
			curr = lst.insert(curr, *curr);
			++curr;
			++curr;
		}
		else
			curr = lst.erase(curr);
	}
	for (auto i : lst)
		cout << i << endl;
}
```

#### 练习9.32

- **在第316页的程序中，像下面语句这样调用insert是否合法？如果不合法，为什么？**

- ```c++
    iter = vi.insert(iter, *iter++);
    ```

不合法。虽然上面语句可以正常运行，但是由于在C++中并没有指定函数形参的入栈顺序，因此可能是先输入iter这个形参，或是先输入`*iter++`这个形参。对于这两种情况而言，得到的结果将会不同。

因此是不合法的。

#### 练习9.33

- **在本节最后一例中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。**

如果容器是vector或string以及deque，迭代器将会失效，程序崩溃。如果是list将正常运行。

#### 练习9.34

- **假定vi是一个保存int的容器，其中有偶数值也要奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。**

```c++
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```

遇到奇数时复制该奇数再次插入，并移动至下个元素。

然而iter将被重新赋值为iter之前的元素，因此移动至原先的下个元素需要自增iter两次。故将死循环。

### 9.4 节练习

#### 练习9.35

- **解释一个vector的capacity和size有何区别。**

size是指vector已经保存的元素的数目，capacity是vector在不分配新的内存空间的前提下它最多可以保存多少元素。



#### 练习9.36

- **一个容器的capacity可能小于它的size吗？**

不可能

#### 练习9.37

- **为什么list或array没有capacity成员函数？**

list的元素不是以连续的地址存储的，因此不需要担心当前内存地址不够用的问题，只需找到新的可用空间即可。

array是固定长度的数组，其capacity在初始化之初就固定了，因此其成员函数无意义。

#### 练习9.38

- **编写程序，探究在你的标准实现中，vector是如何增长的。**

```c++
int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.reserve(50);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;
    while (v.size() != v.capacity())
        v.push_back(0);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;
    v.push_back(42);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;    //增加1/2原有长度
    return 0;
}
```

#### 练习9.39

- **解释下面程序片段做了什么：**

- ```c++
    vector<string> svec;
    svec.reserve(1024);	//为该vevtor申请1024个元素空间
    string word;
    while (cin >> word)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);	//根据vector内元素数目将其扩大0.5倍
    ```

#### 练习9.40

- **如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个、或1048个呢？**

256：1024，512：1024    resize后数量不超过预留空间，因此capacity不改变。

1000：因为resize会添加元素进入容器，因此vector将根据具体实现提升capacity，且不低于1500。

1048：因为resize会添加元素进入容器，因此vector将根据具体实现提升capacity，且不低于1524。

### 9.5.1 节练习

#### 练习9.41

- **编写程序，从一个vector<char>初始化一个string。**

```c++
vector<char> vc = {'H', 'E', 'L', 'L', 'O'};
string str(vc.begin(), vc.end());
```

#### 练习9.42

- **假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？**

预先将该string执行成员函数reserve(100)。这样就能极大减少初期的扩容操作。

### 9.5.2 节练习

#### 练习9.43

- **编写一个函数，接受三个string参数是s、oldVal 和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。**

```c++
void func(string &s, const string &oldVal, const string &newVal) {
	string::iterator iter = s.begin();
	auto len = oldVal.size();
    //因为(iter, iter + len)是个左闭右开区间，因此判断条件为iter + len - 1 != s.end()
	while (s.end() - len + 1 != iter) {
		if (oldVal == string(iter, iter + len)) {
			iter = s.erase(iter, iter + len);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += len;
		}
		else
			++iter;
	}
}
```

#### 练习9.44

- **重写上一题的函数，这次使用一个下标和replace。**

```c++
void func(string &s, const string &oldVal, const string &newVal) {
	string::size_type pos = 0;
	auto len = oldVal.size();
	while (pos + len - 1 != s.size()) {    //如果插入值后，s.size()会变，因此不能把它保存在对象里
		if (oldVal == s.substr(pos, len)) {
			s.replace(pos, len, newVal);
			pos += len;
		}
		else
			++pos;
	}
}
```

#### 练习9.45

- **编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。**

```c++
string func(const string & str,const string & prefix,const string & suffix){
    string result(str);
    auto beg = result.begin();
    result.insert(beg, prefix.begin(), prefix.end());
    result.append(suffix);
    return result;
}
```

#### 练习9.46

- **重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。**

```c++
string func(const string & str, const string & prefix, const string & suffix) {
	string result(str);
	result.insert(0, prefix);
	result.insert(result.size(), suffix);
	return result;
}
```

### 9.5.3 节练习

#### 练习9.47

- **编写程序，首先查找string"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。**

```c++
int main() {
	string str("ab2c3d7R4E6");
	string letter("abcdRE");
	string number("23467");
	string::size_type pos = 0;
	while ((pos = str.find_first_of(number, pos)) != string::npos) {
		cout << "found number at index: " << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_of(letter, pos)) != string::npos) {
		cout << "found letter at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(letter, pos)) != string::npos) {
		cout << "found number at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(number, pos)) != string::npos) {
		cout << "found letter at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
}
```

#### 练习9.48

- **假定name和numbers的定义如325页所示，numbers.find(name)返回什么？**

string::npos

#### 练习9.49

- **如果一个字母延伸到中线之上，如d 或 f，则称其有上出头部分（ascender）。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（descender）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。**

```c++
int main(int argc, char const * argv[]){
    string noneed("bdfhkltgjpqy");
    string word, result;
    fstream& in(argv[1]);
    while(in >> word){
        if (word.find_first_in(noneed) == string::npos && word.size() > result.size())
            result = word;
    }
    cout << result;
}
```

### 9.5.5 节练习

#### 练习9.50

- **编写程序处理一个vector<string>，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。**

```c++
int main() {
	vector<string> v = { "1", "2", "3", "4", "5" };
	int resultI = 0;
	for (const string& str : v)
		resultI += stoi(str);
	cout << resultI << endl;
	float resultF = 0.0;
	for (const string& str : v)
		resultF += stof(str);
	cout << resultF << endl;
}
```

#### 练习9.51

- **设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同的数据格式，如January 1,1900、1/1/1990、Jan 1 1900 等。**

```c++
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Date
{
	friend void print(Date& item);
private:
	unsigned year;
	unsigned month;
	unsigned date;
public:
	Date(const string& s);
	unsigned change_to_digit(const string& s);
};
unsigned Date::change_to_digit(const string& s)
{
	string numbers{ "0123456789" };
	if (s.find_first_of(numbers) != string::npos)
		return stoi(s);
	vector<string> v{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	decltype(v.size()) loc = 0;
	for (decltype(v.size()) i = 0; i != v.size(); ++i)
		if (s.find(v[i]) != string::npos)
		{
			loc = i + 1;	break;
		}
	return loc;
}
Date::Date(const string& s)
{
	string punct{ " /," };
	auto pos = s.find_first_of(punct);
	month = change_to_digit(s.substr(0, pos));
	++pos;
	auto pos2 = s.find_first_of(punct, pos);
	date = stoi(s.substr(pos, pos2 - pos));
	++pos2;
	auto pos3 = s.find_first_of(punct, pos2);
	year = stoi(s.substr(pos2, pos3 - pos2));
}

void print(Date& item)
{
	cout << item.year << " " << item.month << " " << item.date << endl;
}
int main()
{
	Date date1("January 1,1990");
	print(date1);
	Date date2("1/1/1990");
	print(date2);
	Date date3("Jan 1 1990");
	print(date3);
	system("pause");
}
```

### 9.6 节练习

#### 练习9.52

- **使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。**