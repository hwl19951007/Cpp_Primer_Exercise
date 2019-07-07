void eliminate_duplicates(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	eliminate_duplicates(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wz = partition(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });
	auto count = words.end() - wz;
	for_each(wz, words.end(), [](const string &s) { cout << s << " "; });
}

int main() {
	std::vector<std::string> v = { "1", "1", "12", "123", "1234", "12345", "123456" };
	biggies(v, 4);
}