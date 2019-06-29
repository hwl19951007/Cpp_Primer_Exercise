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