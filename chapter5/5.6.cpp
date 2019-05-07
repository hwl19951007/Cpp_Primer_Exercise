#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	string lettergrade;
	int grade;
	while (cin >> grade)
	{
		grade < 60 ? lettergrade = scores[0] : lettergrade = scores[(grade - 50) / 10];
		cout << lettergrade << '\n';
	}
}