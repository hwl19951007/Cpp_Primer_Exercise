#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int i;
	while (cin >> i) v.push_back(i);
	int len = v.size();
	for (i = 0; i < len - 1; i++)   //相邻整数
		cout << v[i] + v[i + 1] << ' ';
	cout << '\n';
	for (i = 0; i < len >>1; i++)  //头尾整数
		cout << v[i] + v[len - i - 1] << ' ';
}