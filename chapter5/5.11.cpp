#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, nCnt = 0;    //最后三个为空格，制表符，换行符
	string str;
	char c;
	while (getline(cin, str)) {
		c = tolower(str[0]);
		if (c == 'a') aCnt += 1;
		if (c == 'e') eCnt += 1;
		if (c == 'i') iCnt += 1;
		if (c == 'o') oCnt += 1;
		if (c == 'u') uCnt += 1;
		if (c == ' ') sCnt += 1;    //cin 无法获取空格和制表符，改用getline
		if (c == '\t') tCnt += 1;
		if (c == '\n') nCnt += 1;    //getline 也无法获取到换行符，只能改用从文本文件的输入流中获取
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of vowel space: \t" << sCnt << '\n'
		<< "Number of vowel tab: \t" << tCnt << '\n'
		<< "Number of vowel newline: \t" << nCnt << endl;
}