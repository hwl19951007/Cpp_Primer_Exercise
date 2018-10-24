#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    int count = 1;
    std::cin >> item1;
    while (std::cin >> item2) {
        if (item1.isbn() == item2.isbn()) {
            count += 1;
        }
        else {
            std::cout << item1.isbn() << " have " << count << " sale records." << std::endl;
            item1 = item2;
            count = 1;
           }
       }
    return 0;
}