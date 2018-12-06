#include <iostream>
int main()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;    // 输出32
	std::cout << u - u2 << std::endl;    //输出-32对int占位数得值的模

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;    //输出32
	std::cout << i - i2 << std::endl;    //输出-32
	std::cout << i - u << std::endl;    //输出0
	std::cout << u - i << std::endl;    //输出0
	return 0;
}
