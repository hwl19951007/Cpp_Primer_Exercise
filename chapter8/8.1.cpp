#include <iostream>
#include <string>
using namespace std;
istream& func(istream &is) {
	string str;
	while (!is.eof() && is >> str ) {    //优先判断是否输入结束标识符
		cout << str;
	}
	is.clear();
	return is;
}
int main() {
	func(cin);
}