#include <iostream>
int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	while (v2 - v1 >= 0) {  //默认v2 > v1
		std::cout << " " << v1;
		++v1;
	}
	return 0;
}