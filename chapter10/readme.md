- ## chapter10 泛型算法

    [TOC]

    ## 练习

    ### 10.1 节练习

    #### 练习10.1

    - **头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。count返回给定值在序列中出现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。**

    ```c++
    #include <algorithm>
    int main() {
    	int i;
    	vector<int> vi;
    	while (cin >> i)
    		vi.push_back(i);
    	cout << count(vi.cbegin(), vi.cend(), 6);
    }
    ```

    #### 练习10.2

    - **重做上一题，但读取string序列存入 list 中。**

    ```c++
    #include <algorithm>
    int main() {
    	string str;
    	list<string> lst;
    	while (cin >> str)
    		lst.push_back(str);
    	cout << count(lst.cbegin(), lst.cend(), "a");
    }
    ```

    ### 10.2.1 节练习

    #### 练习10.3

    - **用accumulate求一个vector<int>中的元素之和。**

    ```c++
    #include <numeric>
    int main(){
        vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
        cout << accumulate(vi.cbegin(), vi.cend(), 0) << endl;
    }
    ```

    #### 练习10.4

    - **假定v是一个vector<double>，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？**

    最终得到的结果将会由于每次将值添加到结果时，因double到int的隐式转换丢失精度。

    #### 练习10.5

    - **在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？**

    正常运行并返回正确结果。

    ### 10.2.2 节练习

    #### 练习10.6

    - **编写程序，使用fill_n将一个序列中的 int 值都设置为 0。**

    ```c++
    int main(){
        vector<int> vi(10, 10);
        fill_n(vi.begin(), vi.size(), 0);
        for (int i : vi)
            cout << i << endl;
    }
    ```

    #### 练习10.7

    - **下面程序是否有错误？如果有，请改正：**

    ```c++
    (a) 
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());
    (b)
    vector<int> vec;
    vec.reserve(10);
    fill_n(vec.begin(), 10, 0);
    ```

    （a）有错。vec是空容器，无法向一个空容器去复制数据。

    （b）有错。虽然为vec提供了内存空间，但此时vec仍是一个空容器，无法向空容器去写入元素，该语句的结果是未定义的。

    #### 练习10.8

    - **本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？**

    对于标准库算法而言，它只会使用赋值算法将容器内的值改变。而当标准库算法使用back_inserter时，赋值运算符将变作调用push_back函数，而非原本的赋值函数。可见这一行为是因为使用了back_inserter才导致改变了容器的大小，对于标准库算法而言仅仅是调用了赋值算法而已，因此不会使这一断言失效。

    ### 10.2.3 节练习

    #### 练习10.9

    - **实现你自己的elimDups。测试你的程序，分别在读取输入后、调用 unique后以及调用erase后打印vector的内容。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
        sort(v.begin(), v.end());
        for (auto i : v)
            cout << i << "  ";
        cout << endl;
    
        auto end_unique = unique(v.begin(), v.end());
        for (auto i : v)
            cout << i << "  ";
        cout << endl;
    
        v.erase(end_unique, v.end());
        for (auto i : v)
            cout << i << "  ";
        cout << endl;
    }
    int main()
    {
        vector<string> v = {"abc", "abc", "efg", "hij", "klmn", "opq", "xyz", "klmn"};
        eliminate_duplicates(v);
        return 0;
    }
    ```

    #### 练习10.10

    - **你认为算法不改变容器大小的原因是什么？**

    因为泛型函数使用的是迭代器，因此其本身就没有容器的概念。这也是为了通用性服务，不考虑容器本身，而通过迭代器来直接访问其中的元素。另外，由于迭代器容易因为元素的删除插入等原因失效，因此为了避免这种情况发生，会限制泛型函数进行增删的操作，避免出现迭代器失效的情况。

    ### 10.3.1 节练习

    #### 练习10.11

    - **编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。打印vector的内容，验证你的程序的正确性。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    
    bool isShorter(const string &s1, const string &s2) {
    	return s1.size() < s2.size();
    }
    
    int main()
    {
    	vector<string> v = { "abc", "abc", "efg", "hij", "klmn", "opq", "xyz", "klmn" };
    	eliminate_duplicates(v);
    	stable_sort(v.begin(), v.end(), isShorter);
    	for (auto i : v)
    		cout << i << " ";
    	return 0;
    }
    ```

    #### 练习10.12

    - **编写名为compareIsbn的函数，比较两个 Sales_data 对象的isbn( ) 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。**

    ```c++
    void compareIsbn(const Sales_data &S1, const Sales_data &S2){
        return S1.isbn() < S2.isbn();
    }
    ```

    #### 练习10.13

    - **标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。**

    ```c++
    bool morethan5(const string &str) {
    	return str.size() > 4;
    }
    int main() {
    	vector<string> v{ "1", "12", "123", "1234", "12345", "123456" };
    	for (const string &str : v) {
    		if (morethan5(str))
    			cout << str << endl;
    	}
    }
    ```

    ### 10.3.2 节练习

    #### 练习10.14

    - **编写一个 lambda ，接受两个int，返回它们的和。**

    ```c++
    int main() {
    	auto f = [](int i, int j) {return i + j; };
    	cout << f(1, 2) << endl;
    }
    ```

    #### 练习10.15

    - **编写一个 lambda ，捕获它所在函数的 int，并接受一个 int参数。lambda 应该返回捕获的 int 和 int 参数的和。**

    ```c++
    int main() {
    	int i = 5;
    	auto f = [i](int j) {return i + j; };
    	cout << f(5);
    }
    ```

    #### 练习10.16

    - **使用 lambda 编写你自己版本的 biggies。**

    略。

    #### 练习10.17

    - **重写10.3.1节练习10.12（第345页）的程序，在对sort的调用中使用 lambda 来代替函数 compareIsbn。**

    ```c++
    sort(v.begin(), v.end(), [](const Sales_data &s1, const Sales_data &s2) 
         {return s1.isbn() < s2.isbn(); });
    ```

    #### 练习10.18

    - **重写 biggies，用 partition 代替 find_if。我们在10.3.1节练习10.13（第345页）中介绍了 partition 算法。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    
    void biggies(vector<string> &words, vector<string>::size_type sz) {
    	eliminate_duplicates(words);
    	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
    	auto wz = partition(words.begin(), words.end(), [sz](const string &a) {return a.size() < sz; });
    	auto count = words.end() - wz;
    	for_each(wz, words.end(), [](const string &s) { cout << s << " "; });
    }
    
    int main() {
    	std::vector<std::string> v = { "a", "b", "bc", "abc", "1234", "12345", "123456" };
    	biggies(v, 4);
    }
    ```

    #### 练习10.19

    - **用 stable_partition 重写前一题的程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    
    void biggies(vector<string> &words, vector<string>::size_type sz) {
    	eliminate_duplicates(words);
    	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
    	auto wz = stable_partition(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });
    	auto count = words.end() - wz;
    	for_each(wz, words.end(), [](const string &s) { cout << s << " "; });
    }
    
    int main() {
    	std::vector<std::string> v = { "13", "12", "123", "1234", "12345", "123456" };
    	biggies(v, 4);
    }
    ```

    ### 10.3.3 节练习

    #### 练习10.20

    - **标准库定义了一个名为 count_if 的算法。类似 find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    
    int biggies(vector<string> &words, vector<string>::size_type sz) {
    	eliminate_duplicates(words);
    	auto count = count_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });
    	return count;
    }
    
    int main() {
    	std::vector<std::string> v = { "13", "12", "123", "1234", "12345", "123456" };
    	cout << biggies(v, 4);
    }
    ```

    #### 练习10.21

    - **编写一个lambda，捕获一个局部Int变量，并递减变量值，直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获 的变量是否为0。**

    ```c++
    int main() {
    	int i = 10;
    	auto f = [&i]() {if (i == 0) return true; else { while (i != 0) --i; return false; }};
    	cout << f() << "   " << i << endl;
    	cout << f() << "   " << i << endl;
    }
    ```

    ### 10.3.4 节练习

    #### 练习10.22

    - **重写统计长度小于等于6的单词数量的程序，使用函数代替 lambda。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    bool check_size(const string &str, string::size_type sz) {
    	return str.size() >= sz;
    }
    int biggies(vector<string> &words, vector<string>::size_type sz) {
    	eliminate_duplicates(words);
    	auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    	return count;
    }
    
    int main() {
    	std::vector<std::string> v = { "13", "12", "123", "1234", "12345", "123456" };
    	cout << biggies(v, 4);
    }
    ```

    #### 练习10.23

    - **bind 接受几个参数？**

    bind函数接收一个函数，并接收一个参数列表，其中参数列表的数量没有限制。

    #### 练习10.24

    - **给定一个string，使用 bind 和 check_size 在一个 int 的vector 中查找第一个大于string长度的值。**

    ```c++
    bool check_size(const string &str, string::size_type sz) {
    	return str.size() < sz;
    }
    int main(){
        string str = "hello";
        vector<int> vi = {1,2,3,4,5,6,7,8,9};
        find_if(vi.begin(), vi.end(), bind(check_size, str, _1));
    }
    ```

    #### 练习10.25

    - **在10.3.2节（第349页）的练习中，编写了一个使用partition 的biggies版本。使用 check_size 和 bind 重写此函数。**

    ```c++
    void eliminate_duplicates(vector<string> &v)
    {
    	sort(v.begin(), v.end());
    	auto end_unique = unique(v.begin(), v.end());
    	v.erase(end_unique, v.end());
    }
    bool check_size(const string &str, string::size_type sz) {
    	return str.size() < sz;
    }
    void biggies(vector<string> &words, vector<string>::size_type sz) {
    	eliminate_duplicates(words);
    	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
    	auto wz = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    	auto count = words.end() - wz;
    	for_each(wz, words.end(), [](const string &s) { cout << s << " "; });
    }
    
    int main() {
    	std::vector<std::string> v = { "a", "b", "bc", "abc", "1234", "12345", "123456" };
    	biggies(v, 4);
    }
    ```

    ### 10.4.1 节练习

    #### 练习10.26

    - **解释三种插入迭代器的不同之处。**

    back_inserter 创建一个使用push_back的迭代器，将元素插入的容器末尾。接收被插入元素一个参数。

    front_inserter 创建一个使用push_front的迭代器，将元素插入到容器头部。接收被插入元素一个参数。

    inserter 创建一个使用insert的迭代器，将元素插入到指定位置。接收被插入元素和目标位置两个参数。

    #### 练习10.27

    - **除了 unique（参见10.2.3节，第343页） 之外，标准库还定义了名为 unique_copy 的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 unique_copy将一个vector中不重复的元素拷贝到一个初始化为空的list中。**

    ```c++
    int main() {
    	vector<int> v1 = { 1,1,2,2,3,3,4,4,5,5 };
    	vector<int> v2;
    	unique_copy(v1.begin(), v1.end(), back_inserter(v2));
    	for (int i : v2)
    		cout << i << endl;
    }
    ```

    #### 练习10.28

    - **一个vector 中保存 1 到 9，将其拷贝到三个其他容器中。分别使用inserter、back_inserter 和 front_inserter 将元素添加到三个容器中。对每种 inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。**

    ```c++
    int main() {
    	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
    	list<int> lst1;
    	list<int> lst2;
    	list<int> lst3;
    	copy(v1.begin(), v1.end(), inserter(lst1, lst1.begin()));
    	for (int i : lst1)    //{1,2,3,4,5,6,7,8,9}
    		cout << i;
    	cout << endl;
    	copy(v1.begin(), v1.end(), back_inserter(lst2));
    	for (int i : lst2)    //{1,2,3,4,5,6,7,8,9}
    		cout << i;
    	cout << endl;
    	copy(v1.begin(), v1.end(), front_inserter(lst3));
    	for (int i : lst3)    //{9,8,7,6,5,4,3,2,1}
    		cout << i;
    }
    ```

    ### 10.4.2 节练习

    #### 练习10.29

    - **编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。**

    ```c++
    int main(){
        string str = "file_name";
        ifstream input(stf);
        istream_iterator<string> iter(input), eof;
        vector<string> v(iter(input), eof);
        ostream_iterator<string> iter_out(cout, "\n");
        copy(v.begin(), v.end(), iter_out);
        cout << endl;
    }
    ```

    #### 练习10.30

    - **使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。**

    ```c++
    int main() {
    	istream_iterator<int> in(cin), eof;
    	vector<int> v(in, eof);
    	sort(v.begin(), v.end());
    	ostream_iterator<int> out(cout, "\n");
    	copy(v.begin(), v.end(), out);
    	cout << endl;
    }
    ```

    #### 练习10.31

    - **修改前一题的程序，使其只打印不重复的元素。你的程序应该使用 unique_copy（参见10.4.1节，第359页）。**

    ```c++
    int main() {
    	istream_iterator<int> in(cin), eof;
    	vector<int> v(in, eof);
    	sort(v.begin(), v.end());
    	ostream_iterator<int> out(cout, "\n");
    	unique_copy(v.begin(), v.end(), out);
    	cout << endl;
    }
    ```

    #### 练习10.32

    - **重写1.6节（第21页）中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。使用 sort 和10.3.1节（第345页）中的 compareIsbn 函数来排序交易记录，然后使用 find 和 accumulate 求和。**

    #### 练习10.33

    - **编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用 istream_iterator 读取输入文件。使用 ostream_iterator 将奇数写入第一个输入文件，每个值后面都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。**

    ```c++
    void func(const string& input_filename, const string& output_filename1, const string& output_filename2){
        ifstream in(input_filename);
        istream_iterator<int> iter_in(in), eof;
        ostream_iterator<int> iter_out1(ofstream(output_filename1), " "), ite_out2(ofsteam(out_filename2), "\n");
        while(iter_in != eof){
            if (i&1 == 1)
                *iter_out1++ = i;
            else
                *iter_out2++ = i;
            ++iter_in;
        }
    }
    ```

    ### 10.4.3 节练习

    #### 练习10.34

    - **使用 reverse_iterator 逆序打印一个vector。**

    ```c++
    int main() {
    	vector<int> v = { 1,2,3,4,5,6,7,8 };
    	for (auto riter = v.crbegin(); riter != v.crend(); ++riter)
    		cout << *riter << endl;
    }
    ```

    #### 练习10.35

    - **使用普通迭代器逆序打印一个vector。**

    ```c++
    int main() {
    	vector<int> v = { 1,2,3,4,5,6,7,8 };
    	for (auto iter = v.cend() - 1; iter >= v.cbegin(); --iter) {
    		cout << *iter << endl;
    		if (iter == v.cbegin())
    			break;
    	}
    }
    ```

    #### 练习10.36

    - **使用 find 在一个 int 的list 中查找最后一个值为0的元素。**

    ```c++
    int main() {
    	list<int> lst = { 1,0,1,0,1,0,1 };
    	auto index = find(lst.crbegin(), lst.crend(), 0);
    	cout << "last zero: " << *index << endl;
    }
    ```

    #### 练习10.37

    - **给定一个包含10 个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。**

    ```c++
    int main() {
    	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
    	list<int> lst;
    	copy(vi.crbegin() + 2, vi.crend() - 3, back_inserter(lst));
    	for (int i : lst)
    		cout << i << endl;
    }
    ```

    ### 10.5.1 节练习

    #### 练习10.38

    - **列出5个迭代器类别，以及每类迭代器所支持的操作。**

    输入迭代器（input iterator）： `iter1==iter2 、iter1!=iter2 、 iter++、 *iter  、 iter->xx`

    输出迭代器（output iterator）： ` ++iter、 *iter`

    前向迭代器（forward iterator）： `iter1==iter2 、iter1!=iter2 、 iter++、 *iter  、 iter->xx`

    双向迭代器（bidirectional iterator）： `iter1==iter2 、iter1!=iter2 、 iter++、 iter--  、*iter  、 iter->xx`

    随机访问迭代器（random-access iterator）：`iter1==iter2 、iter1!=iter2、iter++、iter--  、*iter  、 iter->xx  、 iter1(< 、 <= 、 > 、 >=)iter2、 iter(+、+=、-、-=)i 、iter1-iter2、iter[n]`

    #### 练习10.39

    - **list 上的迭代器属于哪类？vector呢？**

    list：前向迭代器。vector：随机访问迭代器。

    #### 练习10.40

    - **你认为 copy 要求哪类迭代器？reverse 和 unique 呢？**

    copy：前两个为输入，后一个为输出。

    reverse：双向迭代器。

    unique：前向迭代器。

    ### 10.5.3 节练习

    #### 练习10.41

    - **仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：**

    `replace(beg, end, old_val, new_val);`

    将`beg`至`end`范围内所有值为`old_val`的元素替换为`new_val`。

    `replace_if(beg, end, pred, new_val);`

    将`beg`至`end`范围内所有通过谓词`pred`判定为真的元素替换为`new_val`。

    `replace_copy(beg, end, dest, old_val, new_val);`

    将`beg`至`end`范围内所有值为`old_val`的元素替换为`new_val`的结果复制到dest迭代器及其后续部分。不改变原容器内的值。

    `replace_copy_if(beg, end, dest, pred, new_val);`

    将`beg`至`end`范围内所有通过谓词`pred`判定为真的元素替换为`new_val`的结果复制到dest迭代器及其后续部分。不改变原容器内的值。

    ### 10.6 节练习

    #### 练习10.42

    - **使用 list 代替 vector 重新实现10.2.3节中的去除重复单词的程序。**

    ```c++
    void elimDups(list<string> &words){
        sort(words.begin(), words.end());
        list.unique();
    }
    ```