#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4996)   //�ر� strcpy����ȫ����

int main() {
	string str;
	char* chars = new char[2]();    // ��̬�����Զ�����
	cin >> str;
	strcpy(chars, str.c_str());
	cout << chars << endl;
	delete[] chars;
}