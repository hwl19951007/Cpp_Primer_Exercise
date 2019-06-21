#include <iostream>
#include <string>
using namespace std;
class Sales_data;
istream &read(istream &is, Sales_data &item);

// own Sales_data
class Sales_data {
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) { }
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { }
	Sales_data(istream &is) { read(is, *this); }
	void CalcRevenue(double price);
	double CalcAveragePrice();
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	friend istream &read(istream &is, Sales_data &item);
	friend ostream &print(ostream &os, const Sales_data &item);
};

void Sales_data::CalcRevenue(double price)
{
	revenue = units_sold * price;
}

void Sales_data::SetData(Sales_data data)
{
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data)
{
	if (bookNo != data.bookNo) return;
	units_sold += data.units_sold;
	revenue += data.revenue;
}

double Sales_data::CalcAveragePrice()
{
	if (units_sold != 0)
		return revenue / units_sold;
	else
		return 0.0;
}
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.bookNo << " " << item.units_sold << " "<< item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}