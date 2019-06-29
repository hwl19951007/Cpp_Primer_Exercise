bool compare(const list<int>& lst1, const vector<int>& v2) {
	bool result = true;
	if (lst1.size() == v2.size()) {
		list<int>::const_iterator begin1 = lst1.begin();
		vector<int>::const_iterator begin2 = v2.begin();
		while (begin1 != lst1.end()) {
			if (*begin1 != *begin2) {
				result = false;
				break;
			}
			++begin1, ++begin2;
		}
	}
	return result;
}