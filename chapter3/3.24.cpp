#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int i;
	while (cin >> i) v.push_back(i);
	auto begin = v.begin(), end = v.end() - 1;
	for (auto it = begin; it < end; it++)   //相邻整数
		cout << *it + *(it + 1) << ' ';
	cout << '\n';
	for (;begin < end; begin++, end--)  //头尾整数
		cout << *begin + *end << ' ';
}