#include <iostream>
#include <string>
using namespace std;
istream& func(istream &is) {
	string str;
	while (!is.eof() && is >> str ) {    //�����ж��Ƿ����������ʶ��
		cout << str;
	}
	is.clear();
	return is;
}
int main() {
	func(cin);
}