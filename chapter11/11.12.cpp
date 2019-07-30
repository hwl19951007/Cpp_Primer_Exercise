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
		v.push_back({ str, i });
		cout << "if you want stop, input 'stop', if not, input anyword else." << endl;
		cin >> str;
		if (str == "stop")
			break;
	}
	for (auto &p : v)
		cout << p.first << "   " << p.second << endl;
}