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
// ʹ������ָ��������ע���ͷ��ڴ棬��read�����ڣ�p��Ϊ�����ڵľֲ������������Զ�����
int main() {
	read(write(build()));
	return 0;
}