void func(string &s, const string &oldVal, const string &newVal) {
	string::iterator iter = s.begin();
	auto len = oldVal.size();
    //��Ϊ(iter, iter + len)�Ǹ�����ҿ����䣬����ж�����Ϊiter + len - 1 != s.end()
	while (s.end() - len + 1 != iter) {
		if (oldVal == string(iter, iter + len)) {
			iter = s.erase(iter, iter + len);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += len;
		}
		else
			++iter;
	}
}