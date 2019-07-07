#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8 };
	for (auto iter = v.cend() - 1; iter >= v.cbegin(); --iter) {
		cout << *iter << endl;
		if (iter == v.cbegin())
			break;
	}
}