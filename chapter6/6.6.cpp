#include <iostream>
using namespace std;
int fact(int val) {    //形参
	static int ret = 1;    //局部静态变量
	int fac = 1;           //局部变量
	while (val > 1)
		fac *= val;
	ret += fac;
	return ret;
}