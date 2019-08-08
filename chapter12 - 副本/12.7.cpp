#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> build() {
	auto p = make_shared<vector<int>>();
	return p;
}
shared_ptr<vector<int>>  write(shared_ptr<vector<int>> p) {
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void read(shared_ptr<vector<int>> p) {
	for (int i : *p)
		cout << i << endl;
}
// 使用智能指针则无需注重释放内存，在read函数内，p作为函数内的局部变量，将被自动销毁
int main() {
	read(write(build()));
	return 0;
}