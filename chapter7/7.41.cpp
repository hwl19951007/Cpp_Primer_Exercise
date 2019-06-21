#include <iostream>
#include <string>
using namespace std;
class Sales_data;
istream &read(istream &is, Sales_data &item);
class Sales_data {
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { cout << "3 parameter" << endl; }
	Sales_data() : Sales_data("", 0, 0.0) { cout << "0 parameter" << endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0.0) { cout << "1 parameter" << endl; }
	Sales_data(istream &is):Sales_data() { read(is, *this); cout << "istream parameter" << endl; }
    friend istream &read(istream &is, Sales_data &item);
};
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
int main(int argc, char const * argv[])
{
	Sales_data s1;
	Sales_data s2("cin");
    Sales_data s3("cin", 5, 8);
    return 0;
}