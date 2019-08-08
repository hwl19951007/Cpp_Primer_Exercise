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
	// 销毁内存分两步，1。需要对每一个对象调用destroy销毁。2.释放内存返回给系统。
	while (q != p)
		alloc.destroy(q--);
	alloc.deallocate(p, n);
}