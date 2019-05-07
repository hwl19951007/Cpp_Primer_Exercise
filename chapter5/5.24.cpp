#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	if (num2 == 0) 
		throw runtime_error("ERROR! Division by zero!");
	cout << num1 / num2;
}