#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string lettergrade;
	int grade;
	while (cin >> grade)
	{
		if (grade < 60)
			lettergrade = scores[0];
		else
			lettergrade = scores[(grade - 50) / 10];
		cout << lettergrade << '\n';
	}
}#include <iostream>
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
		if (!isupper(str[0])) {   //不管首字母是否大写，迭代器必须继续指向下一个元素。
			str = *beg;
			++beg;
			continue;
		}
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