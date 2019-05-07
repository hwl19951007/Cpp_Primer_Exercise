#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	char c;
	while (cin >> c) {
		if (c == 'a') count += 1;
		if (c == 'e') count += 1;
		if (c == 'i') count += 1;
		if (c == 'o') count += 1;
		if (c == 'u') count += 1;
	}
	cout << count << endl;
}