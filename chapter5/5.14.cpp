#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vstr;
	string str;
	int count = 0;
	while (cin >> str)
		vstr.push_back(str);
	auto beg = vstr.begin();
	while (beg + 1 != vstr.end()) {
		if (*beg == *(beg + 1)) count++;
		beg++;
	}
	cout << count;
}