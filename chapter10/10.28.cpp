#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
	list<int> lst1;
	list<int> lst2;
	list<int> lst3;
	copy(v1.begin(), v1.end(), inserter(lst1, lst1.begin()));
	for (int i : lst1)    //{1,2,3,4,5,6,7,8,9}
		cout << i;
	cout << endl;
	copy(v1.begin(), v1.end(), back_inserter(lst2));
	for (int i : lst2)    //{1,2,3,4,5,6,7,8,9}
		cout << i;
	cout << endl;
	copy(v1.begin(), v1.end(), front_inserter(lst3));
	for (int i : lst3)    //{9,8,7,6,5,4,3,2,1}
		cout << i;
}