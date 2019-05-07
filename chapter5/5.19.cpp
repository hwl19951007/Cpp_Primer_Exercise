#include <iostream>
#include <string>
using namespace std;
int main()
{
	string rsp;
	do {
		string str1 = "", str2 = "";
		cout << "Please enter two string:" << endl;
		cin >> str1 >> str2;
		if (str1.size() > str2.size()) cout << str2 << " is shorter." << "\n\n";
		else cout << str1 << " is shorter." << "\n\n";
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
}