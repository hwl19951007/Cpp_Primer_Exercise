#include "Chapter6.h"
#include <iostream>
using namespace std;
int fact1() {
	cout << "Please enter an integer:" << endl;
	int val;
	cin >> val;
	cout << "The factor of " << val;
	int ret = 1;
	while (val > 1)
		ret *= val--;
	cout << " is " << ret << endl;
	return 0;
}