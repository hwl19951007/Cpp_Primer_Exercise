#include <iostream>
using namespace std;
int change(int &i, int &j) {
	int temp = i;
	i = j;
	j = temp;
	return 0;
}
int main() {
	int i = 5, j = 10;
	cout << i << ", " << j;
	change(i, j);
	cout << " been changed as " << i << ", " << j;
}