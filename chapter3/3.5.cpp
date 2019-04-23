#include <iostream>
#include <string>
int main()
{
	std::string str1, str2;
	std::cout << "please enter some strings." << std::endl;
	while (std::cin >> str2) str1 += str2;
	std::cout << str1 << std::endl;
	str1 = "";
	std::cout << "please enter some strings." << std::endl;
	while (std::cin >> str2) str1 += str2 + " ";
	std::cout << str1 << std::endl;
}