#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

void eliminate_duplicates(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}
bool check_size(const string &str, string::size_type sz) {
	return str.size() < sz;
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
	eliminate_duplicates(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wz = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = words.end() - wz;
	for_each(wz, words.end(), [](const string &s) { cout << s << " "; });
}

int main() {
	std::vector<std::string> v = { "a", "b", "bc", "abc", "1234", "12345", "123456" };
	biggies(v, 4);
}