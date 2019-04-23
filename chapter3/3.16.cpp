#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> v1;                    //没有包含元素
    for (auto i : v1)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v2(10);              //包含10个元素,所有的元素值为0
    for (auto i : v2)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v3(10, 42);          //包含10个元素,所有的元素值为42
    for (auto i : v3)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v4{10};              //包含1个元素，值为10
    for (auto i : v4)
        cout << i << '\t';
    cout << "\n============\n";
    vector<int> v5{10, 42};          //包含2个元素，值为10和42
    for (auto i : v5)
        cout << i << '\t';
    cout << "\n============\n";
    vector<string> v6{10};          //包含10个元素,所有的元素值为空字符串
    for (auto i : v6)
        cout << i << '\t';
    cout << "\n============\n";
    vector<string> v7{10, "hi"};  　//包含10个元素,所有的元素值为字符串“hi”
    for (auto i : v7)
        cout << i << '\t';
    cout << "\n============\n";
    return 0;
}