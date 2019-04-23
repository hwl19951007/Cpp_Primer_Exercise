#include <iostream>
#include <string>
int main()
{
	std::string str = "Hello world!";
	std::cout << str << std::endl;
	for (auto &c : str) c = 'X'; //用引用来修改其值
	std::cout << str << std::endl;
}