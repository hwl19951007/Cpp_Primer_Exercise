#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8 };
	for (auto riter = v.crbegin(); riter != v.crend(); ++riter)
		cout << *riter << endl;
}