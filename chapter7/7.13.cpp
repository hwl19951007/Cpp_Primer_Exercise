#include <iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data total(cin);
	if (cin) {
		Sales_data trans(cin);
		do {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		} while (read(cin, trans));    //利用do while循环来完成构造函数后的第一次比较
		print(cout, total) << endl;
	}
	else {
		cout << "No data?!" << endl;
		return -1;
	}return 0;
}