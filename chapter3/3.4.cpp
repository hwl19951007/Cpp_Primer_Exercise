#include <iostream>
#include <string>
int main()
{
	std::string str1, str2;
	std::cout << "please enter two strings." << std::endl;
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);

	if (str1 == str2) std::cout << "Two strings are equal." << std::endl;
	else if (str1 > str2)std::cout << str1 << std::endl;
	else std::cout << str2 << std::endl;

	if(str1.size() == str2.size()) std::cout << "Two strings have same length." << std::endl;
	else if (str1.size() > str2.size())std::cout << str1 << std::endl;
	else std::cout << str2 << std::endl;
}