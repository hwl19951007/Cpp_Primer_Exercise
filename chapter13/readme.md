- ```c++
## chapter11 关联容器
    
[TOC]
    
## 练习
    
### 11.1 节练习
    
#### 练习11.1
    
- **描述map 和 vector 的不同。**
    
    map是关联容器，其中的元素是一些键值对（key-value）关键字起到索引的作用，关键词可以是任何东西。
    
    vector是顺序容器， 其中的元素就是元素，下标起到索引的作用，只能是数字。
    
    #### 练习11.2
    
    - **分别给出最适合使用 list、vector、deque、map以及set的例子。**
    
    list 需要频繁在非首尾位置插入时。

    vector 作为元素容器，需要随机访问，不太需要插入元素时。

    deque 作为元素容器，需要随机访问，不太需要插入元素，但比vector 在插入到头部时使用。

    map 存储具有映射信息时。
    
    set 存储需要规避或判断的数据。
    
    #### 练习11.3
    
    - **编写你自己的单词计数程序。**
    
    ​```c++
    void words_count()
{
        map<string, size_t> m;
    string word;
        while (cin >> word)
    {
            ++m[word];
    }
    }
    ​```
    
    #### 练习11.4
    
    - **扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。**
    
​```c++
    void words_count()
{
    	map<string, size_t> m;
	string word;
    		while (cin >> word)
		{
                //利用标准库进行大写转小写
			transform(word.begin(), word.end(), word.begin(), ::tolower);
    			auto iter = word.begin();
			while (iter != word.end()) {    //删除标点符号
    				if (ispunct(*iter))
					iter = word.erase(iter);
    				else
					++iter;
    			}
			++m[word];
    		}
		for (auto c : m)
    			cout << c.first << c.nrd;
    }
    ​```
    
    ### 11.2.1 节练习
    
    #### 练习11.5
    
- **解释map和set的区别。你如何选择使用哪个？**
    
map其中的元素是一些键值对（key-value）
    
set 的元素仅仅是关键字。
    
    依据具体使用场景决定使用哪个。如记录不同人的电话号码可以使用set，记录电话本上有哪些人可以用set。
    
    #### 练习11.6
    
    - **解释set和list的区别。你如何选择使用哪个？**
    
    set 是单纯的关键字合集，list是链表类型的容器。list的功能相对要更多一些。
    
    依据具体使用场景决定，如需保留一定顺序，则list将更合适。
    
#### 练习11.7
    
- **定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。**
    
​```c++
    int main() {
	map<string, vector<string>> fam;
    	string fam_name, name;
	while (true) {
    		cout << "First, input your family name: " << endl;
		cin >> fam_name;
    		cout << "Second, input your childen's name, or input over to 'end' input." << endl;
		while (cin >> name) {
    			if (name == "end")
				break;
    			fam[fam_name].push_back(name);
		}
    		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
    		cin >> name;
    		if (name == "stop")
    			break;
    	}
    	for (auto f : fam) {
    		cout << "famile name: " << f.first  << "children's names: " << '\n' <<  endl;
    		for (auto name : f.second)
    			cout << name << endl;
    	}
    }
    ​```
    
    #### 练习11.8
    
    - **编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？**
    
    ​```c++
    int main() {
    	vector<string> v;
    	string str;
    	while (cin >> str) {
    		if (find(v.begin(), v.end(), str) == v.end())
    			v.push_back(str);
    	}
	for (auto &str : v)
    		cout << str << endl;
}
    ​```

    使用set的优点是无需判断单词是否已经保存在了容器中，直接插入即可。

    ### 11.2.2 节练习

    #### 练习11.9

    - **定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。**

    ​```c++
    map<string, list<int>> m;
    ​```
    
    #### 练习11.10
    
    - **可以定义一个vector<int>::iterator 到 int 的map吗？list<int>::iterator 到 int 的map呢？对于两种情况，如果不能，解释为什么。**
    
    前者可以，后者不行。因为vector的迭代器支持“严格弱序”操作，即“ < ”，而list的迭代器不支持。
    
    #### 练习11.11
    
    - **不使用decltype 重新定义 bookstore。**
    
    ​```c++
    multiset<Sales_data,bool (*pf) (const Sales_data &, const Sales_data &)>
    bookstore(compareIsbn);
    ​```
    
    ### 11.2.3 节练习
    
    #### 练习11.12

    - **编写程序，读入string和int的序列，将每个string和int存入一个pair中，pair保存在一个vector中。**  

    ​```c++
int main() {
    	string str;
    	int i;
    	vector <pair <string, int> > v;
    	while (true) {
    		cout << "Please input a word:" << endl;
		cin >> str;
    		cout << "Please input a number:" << endl;
		cin >> i;
    		v.push_back({ str, i });
		cout << "if you want stop, input 'stop', if not, input anyword else." << endl;
    		cin >> str;
    		if (str == "stop")
    			break;
    	}
    	for (auto &p : v)
    		cout << p.first << "   " << p.second << endl;
    }
    ​```
    
    #### 练习11.13
    
    - **在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？**

    ​```c++
int main() {
    	string str;
	int i;
    	vector <pair <string, int> > v;
	while (true) {
    		cout << "Please input a word:" << endl;
    		cin >> str;
    		cout << "Please input a number:" << endl;
    		cin >> i;
    		v.push_back({ str, i });    //直接隐式调用默认构造函数转化为pair
            //v.push_back(make_pair(str, i));    调用make_pair函数进行构造
        //v.push_back(pair<string, int>(str, i));       使用成员进行初始化
            //pair<string, int> {str, i};    使用成员进行初始化
        //v.push_back(p);
    		cout << "if you want stop, input 'stop', if not, input anyword else." << endl;
		cin >> str;
    		if (str == "stop")
    			break;
    	}
    	for (auto &p : v)
    		cout << p.first << "   " << p.second << endl;
    }
    ​```

    直接隐式构造最利于编写，指定成员类型并进行初始化最易于理解。

    #### 练习11.14

    - **扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的map，添加一个pair的vector，保存孩子的名和生日。**

    ​```c++
int main() {
    	map < string, vector < pair <string, string> >> fam;
	string fam_name, name, birthday;
    	while (true) {
    		cout << "First, input your family name: " << endl;
    		cin >> fam_name;
    		cout << "Second, input your childen's name: " << endl;
		cin >> name;
    		cout << "Third, input your childen's birthday: " << endl;
		cin >> birthday;
    		fam[fam_name].push_back({ name, birthday });
		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
    		cin >> name;
    		if (name == "stop")
    			break;
    	}
    	for (auto f : fam) {
    		cout << "famile name: " << f.first << endl;
    		for (auto p : f.second) {
    			cout << "Children's name :" << p.first << "Children's birthday : " << p.second << endl;
    		}
    	}
    }
    ​```
    
    ### 11.3.1 节练习
    
    #### 练习11.15
    
    - **对一个int到vector<int>的map，其mapped_type、key_type和value_type分别是什么？**
    
    mapped_type 是 vector<int>
    
key_type 是 int
    
value_type 是 pair<const int , vector<int>>
    
#### 练习11.16
    
    - **使用一个map迭代器编写一个表达式，将一个值赋予一个元素。**
    
    ​```c++
    map<int, int> m={1,2};
    map<int, int>::iterator iter = m.begin();
    *iter.second = 3;
    ​```
    
    #### 练习11.17
    
    - **假定 c 是一个string的multiset，v是一个string的vector，解释下面的调用。指出每个调用是否合法：**
    
    ​```c++
    copy(v.begin(), v.end(), inserter(c, c.end()));//将v中元素依次插入到c的尾部
    copy(v.begin(), v.end(), back_inserter(c));//将v中元素依次插入到c的尾部
    copy(c.begin(), c.end(), inserter(v, v.end()));//将c中元素依次插入到v的尾部
    copy(c.begin(), c.end(), back_inserter(v));//将c中元素依次插入到v的尾部
    ​```
    
    其中第二条语句不合法，因为关联容器不支持位置相关的操作，而back_inserter调用了操作push_back。

    #### 练习11.18

    - **写出第382页循环中map_it的类型，不要使用auto或decltype。**

    ​```c++
map<string, size_t>::iterator
    ​```
    
    #### 练习11.19
    
    - **定义一个变量，通过对11.2.2节（第378页）中的名为 bookstore 的multiset调用begin()来初始化这个变量。写出变量的类型，不要使用auto或decltype。**
    
    ​```c++
    multiset<Sales_data>::iterator iter = bookstore.begin();
    ​```
    
    ### 11.3.2 节练习
    
    #### 练习11.20
    
    - **重写11.1节练习（第376页）的单词计数程序，使用insert代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。**
    
    ​```c++
    void words_count()
    {
    map<string, size_t> m;
        string word;
    while (cin >> word)
        {
        auto ret = m.insert({word, 1});
            if (!ret.second)
                ++ret.first->second;
        }
    }
    ​```
    
    下标版本。更直观，且无需考虑单词已经存在于map中，可以省去一个 if 判断语句。
    
#### 练习11.21
    
- **假定word_count是一个string到size_t的map，word是一个string，解释下面循环的作用：**
    
- ```c++
        while (cin >> word)
        ++word_count.insert({word, 0}).first->second;
        ```
    
    将新的单词的pair插入到map中，其数量为0。然后通过接引返回的迭代器，将其数量自增。不管插入是否成功，都将返回该单词的迭代器，因此必然能够成功将其值增加1。
    
    作用是将新单词插入map并将计数值记为1，或将旧单词计数值增加1。
    
    #### 练习11.22
    
    - **给定一个map<string,vector<int>>，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型。**
    
    参数类型为`pair <string, vector<int>>`
    
    返回类型为`pair<pair<string, vector<int>>, bool>`
    
    #### 练习11.23
    
    - **11.2.1节练习（第378页）中的map以孩子的姓为关键字，保存他们的名的vector，用multimap重写此map。**
    
    ​```c++
    int main() {
    	multimap<string, string> fam;
	string fam_name, name;
    	while (true) {
		cout << "First, input your family name: " << endl;
    		cin >> fam_name;
		cout << "Second, input your childen's name: " << endl;
    		cin >> name;
        fam[fam_name] = name;
    		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
		cin >> name;
    		if (name == "stop")
			break;
    	}
    	for (auto f : fam) {
    		cout << "famile name: " << f.first  << "children's names: "<<  endl;
    		for (auto name : f.second)
    			cout << name << endl;
    	}
    }
    ​```
    
    ### 11.3.4 节练习

    #### 练习11.24

    - **下面的程序完成什么功能？**

    - ```c++
        map<int, int> m;
        m[0] = 1;
        ```
    
    如果m中已有以0为关键字的键值对，则将其值赋值为1。如果没有，则为m添加一个关键字0，并将其值赋值为1。
    
    #### 练习11.25
    
    - **对比下面的程序与上一题程序**
    
    - ```c++
        vector<int> v;
        v[0] = 1;
        ```
    
    错误。vector的下标操作返回的是一个右值，无法作为左值接收赋值操作。
    
    #### 练习11.26
    
    - **可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子———即，定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返会的类型。**
    
    ​```c++
map<int, string > m;
    int    //下标操作类型
string //返回类型
    ​```

    ### 11.3.5 节练习

    #### 练习11.27

    - **对于什么问题你会使用count来解决？什么时候你又会选择find呢？**

    对于可能存在重复关键字的问题使用count来解决，对于不存在重复关键字的问题使用find来解决。

    #### 练习11.28

    - **对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。**

    ​```c++
    map<string, int> m;
    map<string, int>::iterator iter;    //初始化一个该map类型的迭代器来保存其结果
    ​```
    
    #### 练习11.29
    
    - **如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？**
    
upper_bound 返回一个迭代器，指向第一个关键字大于给定关键字的元素，可能是尾后迭代器。
    
lower_bound 返回一个迭代器，指向第一个关键字不小于给定关键字的元素，可能是尾后迭代器。
    
equal_bound 返回一个迭代器pair，表示关键字的范围，可能是尾后迭代器。
    
    如果给定关键字不在容器中，则迭代器均指向关键字可以插入的位置。
    
    #### 练习11.30
    
    - **对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。**
    
    pos是指向map元素的迭代器pair，首先，.first操作将获取指向关键字的mapped对象的迭代器，->second操作附带了解引用的操作，并取出了mapped对象中的valued对象，即该关键字映射的对象值。
    
    #### 练习11.31
    
    - **编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map中时也能正常运行。**
    
    ​```c++
    int main() {
    	multimap<string, string> m;
    	auto iter = m.find("test");
    	if (iter == m.end())
    		cout << "item isn't in this map." << endl;
	else
    		m.erase(iter);
}
    ​```

    #### 练习11.32

    - **使用上一题定义的multimap编写一个程序，按字典序打印作者列表和他们的作品。**
    
    ​```c++
    int main() {
    	multimap<string, string> m;
    	for (auto &c : m) {
    		cout << "author: " << c.first << endl;
    		cout << "writings: " << c.second << endl;
    	}
    	return 0;
    }
​```
    
### 11.3.6 节练习
    
#### 练习11.33 
    
    - **实现你自己版本的单词转换程序。**
    
    ​```C++
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <map>
    using namespace std;

    
map<string, string> buildMap(ifstream &map_file) {
    	map<string, string> trans_map;
	string key;
    	string value;
    	while (map_file >> key && getline(map_file, value)) {
    		if (value.size() > 1)
    			trans_map[key] = value.substr(1);
    		else
    			trans_map[key] = value;
    	}
    	return trans_map;
    }
    
const string& transform(const string &s, const map<string, string> &m) {
    	auto map_iter = m.find(s);
	if (map_iter != m.cend())
    		return map_iter->second;
	else
    		return s;
}
    
void word_transform(ifstream &map_file, ifstream &input) {
    	auto trans_map = buildMap(map_file);
    	string text;
    	while (getline(input, text)) {
    		istringstream stream(text);    //读取每个单词
    		string word;
    		bool firstword = true;
    		while (stream >> word) {
    			if (firstword)
    				firstword = false;
    			else
    				cout << " ";
    			cout << transform(word, trans_map);
    		}
    		cout << endl;
	}
    }

    int main(int argc,  char* argv[]) {
	ifstream map_file(argv[1]), input(argv[2]);
    	word_transform(map_file, input);
	return 0;
    }
    ​```
    
    #### 练习11.34
    
    - **如果你将transform函数中的find替换为下标运算符，会发生什么情况？**
    
如果用下标运算符寻找一个不存在的键值，将会在字典中创建一个新的键值对，则将返回错误的转换法则。
    
#### 练习11.35
    
- **在buildMap中，如果进行如下改写，会有什么效果？**
    
        ```c++
        trans_map[key] = value.substr(1);
        改为trans_map.insert({key, value.substr(1)});
        ```
    
    insert操作与下标操作的区别是，在map内已有该键值时，insert将不会进行任何操作，而下标将会将新的键值对覆盖旧的键值对。
    
    具体来说，改写过后，如果有重复的转换规则，则将保留更早的转换规则。
    
#### 练习11.36
    
- **我们的程序并没检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。**
    
将会抛出异常`runtime_error("no rule for ")`
    
    ### 11.4 节练习
    
    #### 练习11.37
    
    - **一个无序容器与其有序版本相比有何优势？有序版本有何优势？**
    
无序容器性能更强，维护方便。有序版本能够保持元素序列，便于操作。
    
#### 练习11.38
    
- **用 unordered_map 重写单词计数程序（参见11.1节，第375页）和单词转换程序（参见11.3.6节，第391页）。**
    
    ​```c++
    void words_count()
    {
        unordered_map<string, size_t> m;
        string word;
        while (cin >> word)
        {
            ++m[word];
    }
    }
​```
    
​```c++
    #include <iostream>
#include <fstream>
    #include <sstream>
#include <string>
    #include <map>
using namespace std;
    

    map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> trans_map;
    	string key;
	string value;
    	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
    			trans_map[key] = value.substr(1);
		else
    			trans_map[key] = value;
	}
    	return trans_map;
}
    
const string& transform(const string &s, const unordered_map<string, string> &m) {
    	auto map_iter = m.find(s);
	if (map_iter != m.cend())
    		return map_iter->second;
	else
    		return s;
}
    
void word_transform(ifstream &map_file, ifstream &input) {
    	auto trans_map = buildMap(map_file);
	string text;
    	while (getline(input, text)) {
		istringstream stream(text);    //读取每个单词
    		string word;
		bool firstword = true;
    		while (stream >> word) {
			if (firstword)
    				firstword = false;
			else
    				cout << " ";
			cout << transform(word, trans_map);
    		}
		cout << endl;
    	}
}
    
int main(int argc,  char* argv[]) {
    	ifstream map_file(argv[1]), input(argv[2]);
	word_transform(map_file, input);
    	return 0;
}
    ​```xxxxxxxxxx void elimDups(list<string> &words){    sort(words.begin(), words.end());    list.unique();}c++
```