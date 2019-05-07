#include <iostream>
using namespace std;
int main()
{
	unsigned  ffCnt = 0, flCnt = 0, fiCnt = 0;
	char c;
	char temp = ' ';
	while (cin >> c) {
		if (temp == 'f')
			if (c == 'f') ffCnt += 1;
			else if (c == 'l') flCnt += 1;
			else if (c == 'i') fiCnt += 1;
		temp = c;
	}
	cout << "Number of vowel ff: \t" << ffCnt << '\n'
		<< "Number of vowel fl: \t" << flCnt << '\n'
		<< "Number of vowel fi: \t" << fiCnt << endl;
}