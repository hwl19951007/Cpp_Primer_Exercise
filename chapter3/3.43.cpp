#include <iostream>
using namespace std;
int main()
{
	cout << "Version1:" << endl;
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int(&p)[4] : ia)
		for (int q : p) cout << q << ' ';
	cout << '\n' << "Version2:" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cout << ia[i][j] << ' ';
	cout << '\n' << "Version3:" << endl;
	for (int *p = ia[0]; p < ia[3]; p++)
		cout << *p << ' ';
}