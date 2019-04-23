#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> text;
	string str;
	while (cin >> str)
		text.push_back(str);
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (auto &c : *it) c = toupper(c);
		cout << *it << endl;
	}
}