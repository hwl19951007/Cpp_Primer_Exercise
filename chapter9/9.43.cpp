void func(string &s, const string &oldVal, const string &newVal) {
	string::iterator iter = s.begin();
	auto len = oldVal.size();
    //因为(iter, iter + len)是个左闭右开区间，因此判断条件为iter + len - 1 != s.end()
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