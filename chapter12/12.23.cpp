#include <iostream>
#include <string>
using namespace std;
#pragma warning( disable : 4996)   //�ر� strcpy����ȫ����

int main() {
	char* char1 = new char[strlen("Hello" "world") + 1](); // +1Ϊ '\0'
	strcpy(char1, "Hello ");
	strcat(char1, "world");
    delect[] char1;
	cout << char1 << endl;
	string str1{ "Hello " }, str2{ "world" };
	cout << str1 + str2 << endl;
}