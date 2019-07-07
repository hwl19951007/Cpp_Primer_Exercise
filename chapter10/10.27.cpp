#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1 = { 1,1,2,2,3,3,4,4,5,5 };
	vector<int> v2;
	unique_copy(v1.begin(), v1.end(), back_inserter(v2));
	for (int i : v2)
		cout << i << endl;
}