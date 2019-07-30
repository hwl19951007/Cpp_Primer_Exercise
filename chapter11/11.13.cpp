#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	int i;
	vector <pair <string, int> > v;
	while (true) {
		cout << "Please input a word:" << endl;
		cin >> str;
		cout << "Please input a number:" << endl;
		cin >> i;
		v.push_back({ str, i });    //直接隐式调用默认构造函数转化为pair
        //v.push_back(make_pair(str, i));    调用make_pair函数进行构造
        //v.push_back(pair<string, int>(str, i));       使用成员进行初始化
        //pair<string, int> {str, i};    使用成员进行初始化
        //v.push_back(p);
		cout << "if you want stop, input 'stop', if not, input anyword else." << endl;
		cin >> str;
		if (str == "stop")
			break;
	}
	for (auto &p : v)
		cout << p.first << "   " << p.second << endl;
}