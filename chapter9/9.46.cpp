string func(const string & str, const string & prefix, const string & suffix) {
	string result(str);
	result.insert(0, prefix);
	result.insert(result.size(), suffix);
	return result;
}