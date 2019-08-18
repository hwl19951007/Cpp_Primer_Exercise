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