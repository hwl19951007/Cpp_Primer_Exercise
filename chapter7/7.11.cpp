#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data first;
	Sales_data second("123");
	Sales_data third("1234", 3, 2.22);
	Sales_data forth(cin);
	print(print(print(print(cout, first), second), third), forth);
}