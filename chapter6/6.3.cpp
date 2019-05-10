#include <iostream>
using namespace std;
int fact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
int main()
{
	cout << fact(5);
}