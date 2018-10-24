#include <iostream>
int main()
{
	int value = 0, sum = 0;
	std::cout << "Enter some numbers:" << std::endl;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "The sum of numbers is:" << sum << std::endl;
	return 0;
}