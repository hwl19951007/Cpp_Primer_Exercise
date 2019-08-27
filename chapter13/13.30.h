class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {  }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		if (this != &rhs_hp) {    //�ж��Ƿ�������ֵ������
			auto temp_ps = new std::string(*rhs_hp.ps);
			delete ps;    //ɾ��ԭps
			ps = temp_ps;    //��psָ����string
			i = rhs_hp.i;
		}
		return *this;
	}
	~HasPtr() {    //��������
		delete ps;    //��Ҫ����ָ��ָ�������
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