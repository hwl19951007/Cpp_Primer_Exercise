#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	multimap<string, string> m;
	for (auto &c : m) {
		cout << "author: " << c.first << endl;
		cout << "writings: " << c.second << endl;
	}
	return 0;
}