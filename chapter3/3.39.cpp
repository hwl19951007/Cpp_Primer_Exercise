#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1 = "A string example";
	string str2 = "A dofferent example";
	if (str1 == str2) cout << "str1 equal to str2" << endl;
	else if (str1 < str2) cout << "str1 litter than str2" << endl;
	else cout << "str1 greater than str2" << endl;

	const char ca1[] = "A string example";
	const char ca2[] = "A different example";
	if (strcmp(ca1, ca2) == 0) cout << "str1 equal to str2" << endl;
	else if (strcmp(ca1, ca2) < 0) cout << "str1 litter than str2" << endl;
	else cout << "str1 greater than str2" << endl;
}