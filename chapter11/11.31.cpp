#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	multimap<string, string> m;
	auto iter = m.find("test");
	if (iter == m.end())
		cout << "item isn't in this map." << endl;
	else
		m.erase(iter);
	return 0;
}