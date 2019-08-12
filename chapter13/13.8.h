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
private:
	std::string *ps;
	int i;
};