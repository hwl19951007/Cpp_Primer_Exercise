void eliminate_duplicates(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

int main()
{
	vector<string> v = { "abc", "abc", "efg", "hij", "klmn", "opq", "xyz", "klmn" };
	eliminate_duplicates(v);
	stable_sort(v.begin(), v.end(), isShorter);
	for (auto i : v)
		cout << i << " ";
	return 0;
}