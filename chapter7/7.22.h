#include <iostream>
#include <string>
using namespace std;
class Peason{
public:
	Peason() = default;
	Peason(const string s1, const string s2) :name(s1), address(s2) { }
	Peason(istream &is);
	string get_name() const { return name; }
	string get_address() const { return address; }
private:
	string name;
	string address;
	friend istream &read(istream &is, Peason &item);
	friend ostream &print(ostream &os, const Peason &item);
};
istream &read(istream &is, Peason &item) {
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, const Peason &item) {
	os << item.name << " " << item.address;
	return os;
}

Peason::Peason(istream &is) {
	read(is, *this);
}
