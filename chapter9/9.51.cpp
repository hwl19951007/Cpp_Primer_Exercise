#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Date
{
	friend void print(Date& item);
private:
	unsigned year;
	unsigned month;
	unsigned date;
public:
	Date(const string& s);
	unsigned change_to_digit(const string& s);
};
unsigned Date::change_to_digit(const string& s)
{
	string numbers{ "0123456789" };
	if (s.find_first_of(numbers) != string::npos)
		return stoi(s);
	vector<string> v{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	decltype(v.size()) loc = 0;
	for (decltype(v.size()) i = 0; i != v.size(); ++i)
		if (s.find(v[i]) != string::npos)
		{
			loc = i + 1;	break;
		}
	return loc;
}
Date::Date(const string& s)
{
	string punct{ " /," };
	auto pos = s.find_first_of(punct);
	month = change_to_digit(s.substr(0, pos));
	++pos;
	auto pos2 = s.find_first_of(punct, pos);
	date = stoi(s.substr(pos, pos2 - pos));
	++pos2;
	auto pos3 = s.find_first_of(punct, pos2);
	year = stoi(s.substr(pos2, pos3 - pos2));
}

void print(Date& item)
{
	cout << item.year << " " << item.month << " " << item.date << endl;
}
int main()
{
	Date date1("January 1,1990");
	print(date1);
	Date date2("1/1/1990");
	print(date2);
	Date date3("Jan 1 1990");
	print(date3);
	system("pause");
}