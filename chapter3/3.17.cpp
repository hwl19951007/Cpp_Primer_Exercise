#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> v;
	string str;
	while (cin >> str) {
		for (auto &c : str) c = toupper(c);
		v.push_back(str);
	}
	for (auto s : v) cout << s << '\n';
}