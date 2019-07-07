void eliminate_duplicates(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

int biggies(vector<string> &words, vector<string>::size_type sz) {
	eliminate_duplicates(words);
	auto count = count_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });
	return count;
}

int main() {
	std::vector<std::string> v = { "13", "12", "123", "1234", "12345", "123456" };
	cout << biggies(v, 4);
}