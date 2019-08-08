#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main() {
	int n = 5;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	// �����ڴ��������1����Ҫ��ÿһ���������destroy���١�2.�ͷ��ڴ淵�ظ�ϵͳ��
	while (q != p)
		alloc.destroy(q--);
	alloc.deallocate(p, n);
}