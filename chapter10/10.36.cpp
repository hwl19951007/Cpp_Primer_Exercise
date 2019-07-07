#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	list<int> lst = { 1,0,1,0,1,0,1 };
	auto index = find(lst.crbegin(), lst.crend(), 0);
	cout << "last zero: " << *index << endl;
}