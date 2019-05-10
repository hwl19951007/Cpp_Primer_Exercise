#include <iostream>
using namespace std;
int abso(int val) {
	if (val > 0)
		return val;
	else return -val;
}
int main()
{
	cout << "Please enter an integer:" << endl;
	int val;
	cin >> val;
	cout << "The absolute value of " << val << " is " << abso(val) << endl;
}