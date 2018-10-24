1.9
#include <iostream>
int main()
{
	int sum = 0;
	for (int i = 50; i <= 100; ++i)
		sum += i;
	std::cout << sum;
	return 0;
}
1.10
#include <iostream>
int main()
{
	for (int i = 10; i >= 0; --i)
		std::cout << " " << i;
	return 0;
}
1.11
#include <iostream>
int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	for (;v2 - v1 >= 0; ++v1)	//默认v2>v1
		std::cout << " " << v1;
	return 0;
}