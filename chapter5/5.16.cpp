#include <iostream>
using namespace std;
int main()
{
	int i = 0, sum = 0;
	while (i <= 100){
		sum += i;
		++i;
	}
	for (int i = 0; i != 100; ++i)
		sum += i;
}