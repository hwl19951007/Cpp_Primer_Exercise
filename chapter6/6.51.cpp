#include <iostream>
using namespace std;
void f()
{cout << "����" << __func__ << "()" << endl;}
void f(int)
{cout << "����" << __func__ << "(int)" << endl;}
void f(int, int)
{cout << "����" << __func__ << "(int, int)" << endl;}
void f(double, double = 3.14)
{cout << "����" << __func__ << "(double, double = 3.14)" << endl;}
int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}