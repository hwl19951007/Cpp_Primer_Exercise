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
	Sales_data(const string &s, unsigned n, double d) :bookNo(s), units_sold(n), revenue(n*d) { cout << "3 parameter" << endl; }
	Sales_data() : Sales_data("", 0, 0.0) { cout << "0 parameter" << endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0.0) { cout << "1 parameter" << endl; }
	Sales_data(istream &is):Sales_data() { read(is, *this); cout << "istream parameter" << endl; }
	Sales_data& operator+=(const Sales_data&);
	void CalcRevenue(double price);
	double avg_prive() const;
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
	friend istream& operator>>(istream &is, Sales_data &item);
	friend ostream& operator<<(ostream &os, Sales_data &item);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
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

inline double Sales_data::avg_prive() const
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

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
istream& operator>>(istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

ostream& operator<<(ostream &os, Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_prive();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data temp(lhs);
	temp += rhs;
	return temp;
}