#include <iostream>
#include <string>
int main()
{
	std::string str;
	//getline可以接收两个参数，输入流和字符串，并将输入流写入字符串
	std::cout << "Now i can get the whole sentence." << std::endl;
	std::getline(std::cin, str);
	std::cout << str << std::endl;
	//cin是获取输入流，遇到空格等空白就会停止
	std::cout << "Now i can get one word." << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;
}