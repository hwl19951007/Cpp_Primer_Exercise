#include <iostream>
#include <string>
class Tree
{
	friend std::ostream& operator<<(std::ostream& os, const Tree& item);
	friend std::istream& operator>>(std::istream& is, Tree& item);
	friend bool operator==(const Tree &lhs, const Tree &rhs);
	friend bool operator!=(const Tree &lhs, const Tree &rhs);

private:
	std::string Name;
	unsigned Age = 0;
	double Height = 0;
public:
	Tree() = default;
	Tree(const std::string &n, unsigned a, double h)
		: Name(n), Age(a), Height(h) {}
	explicit operator bool() const {
		return !Name.empty() && Age != 0 && Height != 0;
	}
};
std::ostream& operator<<(std::ostream& os, const Tree& item) {
	os << item.Name << " " << item.Age << " " << item.Height;
	return os;
}
std::istream& operator>>(std::istream& is, Tree& item) {
	is >> item.Name >> item.Age >> item.Height;
	if (!is)
		item = Tree();
	return is;
}
bool operator==(const Tree &lhs, const Tree &rhs) {
	return (lhs.Name == rhs.Name && lhs.Age == rhs.Age && lhs.Height && rhs.Height);
}
bool operator!=(const Tree &lhs, const Tree &rhs) {
	return !(lhs == rhs);
}
