#include <iostream>
 
#include "2.42-Sales_data.h"
 
int main()
{
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.CalcRevenue(price);
    book.Print();
 
    return 0;
}
