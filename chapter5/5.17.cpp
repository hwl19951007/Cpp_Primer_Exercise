#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v1 = { 0,1,1,2 }, v2 = { 0,1,1,2,3,5,8 };
	auto beg1 = v1.begin(), beg2 = v2.begin();
	string tag = "True";
	while (beg1 != v1.end() && beg2 != v2.end()) {
		if (*beg1 != *beg2) {
			tag = "False";
			break;
		}
		++beg1; ++beg2;
	}
	cout << tag;
}