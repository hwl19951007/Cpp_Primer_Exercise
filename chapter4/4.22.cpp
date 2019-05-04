#include <string>
using namespace std;
int main()
{
	string finalgrade;
	int grade;
	finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "low pass";
	if (grade > 90) finalgrade = "high pass";
	else if (grade > 75) finalgrade = "pass";
	else if (grade < 60) finalgrade = "fail";
	else finalgrade = "low pass";
}