void func(string &s, const string &oldVal, const string &newVal) {
	string::size_type pos = 0;
	auto len = oldVal.size();
	while (pos + len - 1 != s.size()) {    //�������ֵ��s.size()��䣬��˲��ܰ��������ڶ�����
		if (oldVal == s.substr(pos, len)) {
			s.replace(pos, len, newVal);
			pos += len;
		}
		else
			++pos;
	}
}