#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.h"
using namespace std;

int main() {
	ifstream file("Text.txt");
	StrBlob s;
	string str;
	while (getline(file, str))
		s.push_back(str);
	for (auto begin = s.begin(); begin != s.end(); begin.incr())
		cout << begin.deref() << endl;
	return 0;
}