#include <iostream>
#include <vector>
#define NDEBUG
using namespace std;
void print(vector<int>::iterator vi, vector<int>::iterator end) {
	if (vi != end) {
		cout << *vi << endl;
		print(++vi, end);
	}
}
int main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7 };
#ifndef NDEBUG    //if not define
	cout << "vector have " << v1.size() << "elements." << endl;
#endif
	print(v1.begin(), v1.end());
}