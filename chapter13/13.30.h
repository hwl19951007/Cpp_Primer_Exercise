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
	~HasPtr() {    //析构函数
		delete ps;    //需要销毁指针指向的内容
	}

private:
	std::string *ps;
	int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap" << std::endl;
}