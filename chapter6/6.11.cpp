#include <iostream>
using namespace std;
void reset(int &i) {
	i = 1;
}
int main() {
	int i = 5;
	reset(i);
	cout << i;
}