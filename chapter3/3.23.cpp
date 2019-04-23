#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v(10,2);
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << '\t';
	cout << endl;
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it *= 2;
		cout << *it << '\t';
	}
}