#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	list<int> lst;
	copy(vi.crbegin() + 2, vi.crend() - 3, back_inserter(lst));
	for (int i : lst)
		cout << i << endl;
}