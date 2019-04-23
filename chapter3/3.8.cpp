#include <iostream>
#include <string>
int main()
{
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	decltype(str.size()) i = 0;
	for (i = 0; i < str.size(); i++) str[i] = 'X';
	std::cout << str << std::endl;
	i = 0;
	while (i < str.size()) str[i++] = 'C';
	std::cout << str << std::endl;
}