#include <iostream>
int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	if (v1 > v2){
		int t;
		t = v2;
		v2 = v1;
		v1 = t;
	}
	while (v2 - v1 >= 0) {
		std::cout << " " << v1;
		++v1;
	}
	return 0;
}