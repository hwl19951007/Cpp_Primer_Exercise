#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	while(cin >> num1 >> num2)
	    try {
		    if (num2 == 0) throw runtime_error("ERROR!Division by zero!");
		    cout << num1 / num2;
	    }catch (runtime_error err) {
			cout << err.what() << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') break;
	    }
}