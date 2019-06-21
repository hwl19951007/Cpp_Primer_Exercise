#include <iostream>
#include <string>
using namespace std;
struct Peason{
	string name;
	string address;
	string get_name() const { return name; }
	string get_address() const { return address; }
};