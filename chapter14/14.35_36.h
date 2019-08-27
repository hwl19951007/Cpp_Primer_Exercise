#include <iostream>
#include <string>
#include <vector>
class InputString {
public:
	InputString(std::istream &i = std::cin) : is(i) {}
	std::string operator()() {
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream &is;
};
int main() {
	InputString i;
	std::vector<std::string> v;
	for (std::string temp; !(temp = i()).empty(); v.push_back(temp))
		for (auto str : v) std::cout << str << std::endl;
}