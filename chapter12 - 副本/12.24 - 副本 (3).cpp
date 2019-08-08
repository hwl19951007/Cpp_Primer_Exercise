#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4996)   //关闭 strcpy不安全错误。

int main() {
	string str;
	char* chars = new char[2]();    // 动态数组自动增长
	cin >> str;
	strcpy(chars, str.c_str());
	cout << chars << endl;
	delete[] chars;
}