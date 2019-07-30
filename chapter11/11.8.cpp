#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<string> v;
	string str;
	while (cin >> str) {
		if (find(v.begin(), v.end(), str) == v.end())
			v.push_back(str);
	}
	for (auto &str : v)
		cout << str << endl;
}