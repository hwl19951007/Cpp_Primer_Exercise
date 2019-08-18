class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) { }
	//    �������캯�����������������ݳ�Ա��������������
	HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
	HasPtr& operator=(const HasPtr &rhs_hp) {
		++*rhs_hp.use;    //�������Ҳ����ļ����������Լ���������������������Ը�ֵ�������
		if (--*use == 0) {
			delete ps;    //��Ҫ����ָ��ָ�������
			delete use;
		}
		ps = rhs_hp.ps;
		i = rhs_hp.i;
		use = rhs_hp.use;
		return *this;
	}
	~HasPtr() {    //��������
		if (--*use == 0) {
			delete ps;    //��Ҫ����ָ��ָ�������
			delete use;
		}
	}
private:
	std::string *ps;
	int i;
	std::size_t *use;    //������¼�ж��ٸ�������*ps�ĳ�Ա
};