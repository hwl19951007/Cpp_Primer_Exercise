#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vstr;
	string str;
	string exist_str;
	while (cin >> str) {
		vstr.push_back(str);
		if (exist_str == str)
			break;
		exist_str = str;
	}
	str = vstr[0];
	auto beg = vstr.begin() + 1;
	bool tag = false;
	while (beg != vstr.end()){
		if (str == *beg) {
			tag = true;
			break;
		}
		str = *beg;
		++beg;
	}
	if (tag) cout << str;
	else cout << "no repeat word.";
}