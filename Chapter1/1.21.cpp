#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cout << "Please enter two items that have same ISBN: " << std::endl;
	std::cin >> item1 >> item2;
	std::cout << "The sum is :" << item1 + item2 << std::endl;
	return 0;
}