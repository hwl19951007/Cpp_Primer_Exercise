#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto begin = scores.begin();
	while (cin >> grade) {
		if (grade <= 100)
			++*(begin + grade / 10);
	}
}