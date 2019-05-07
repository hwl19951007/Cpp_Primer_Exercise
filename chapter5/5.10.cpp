#include <iostream>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char c;
	while (cin >> c) {
		c = tolower(c);
		if (c == 'a') aCnt += 1;
		if (c == 'e') eCnt += 1;
		if (c == 'i') iCnt += 1;
		if (c == 'o') oCnt += 1;
		if (c == 'u') uCnt += 1;
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << endl;
}