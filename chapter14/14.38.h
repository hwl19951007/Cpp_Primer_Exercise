class checklength {
	size_t sz;
public:
	checklength(size_t n) : sz(n) {}
	bool operator()(const string &str) {
		return str.size() == sz;
	}
}
//主函数略