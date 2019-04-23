#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> v1;                    //没有包含元素
	for (auto it = v1.cbegin(); it != v1.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v2(10);              //包含10个元素,所有的元素值为0
	for (auto it = v2.cbegin(); it != v2.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v3(10, 42);          //包含10个元素,所有的元素值为42
	for (auto it = v3.cbegin(); it != v3.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v4{ 10 };              //包含1个元素，值为10
	for (auto it = v4.cbegin(); it != v4.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<int> v5{ 10, 42 };          //包含2个元素，值为10和42
	for (auto it = v5.cbegin(); it != v5.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<string> v6{ 10 };          //包含10个元素,所有的元素值为空字符串
	for (auto it = v6.cbegin(); it != v6.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	vector<string> v7{ 10, "hi" };    //包含10个元素,所有的元素值为字符串“hi”
	for (auto it = v7.cbegin(); it != v7.cend(); ++it)
		cout << *it << '\t';
	cout << "\n============\n";
	return 0;
}