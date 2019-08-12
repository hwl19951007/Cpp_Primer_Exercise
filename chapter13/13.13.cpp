#include <iostream>
#include <vector>

struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; }
	~X() { std::cout << "~X" << std::endl; }
};

void f(const X& xr, X x) {
	std::vector<X> vx;
	vx.push_back(xr);
	vx.push_back(x);    //��֪��Ϊʲô�˴���࿽����ֵһ��X����������
}
int main() {
	X *x = new X();
	f(*x, *x);
	delete x;
	return 0;
}