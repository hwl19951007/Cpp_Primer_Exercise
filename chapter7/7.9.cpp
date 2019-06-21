#include <iostream>
#include <string>
using namespace std;
struct Peason{
	string name;
	string address;
	string get_name() const { return name; }
	string get_address() const { return address; }
};
istream &read(istream &is, Peason &item) {
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, const Peason &item) {
	os << item.name << " " << item.address;
	return os;
}