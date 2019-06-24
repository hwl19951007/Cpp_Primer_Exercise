#include <iostream>
#include <string>
using namespace std;
istream& func(istream &is) {
	string str;
	while (is >> str && !is.eof()) {
		cout << str;
	}
	is.clear();
	return is;
}
int main() {
	func(cin);
}