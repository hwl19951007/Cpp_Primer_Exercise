#include <iostream>
using namespace std;
void print(const int *beg, const int *end) {
	while (beg != end) cout << *beg++ << endl;
}

void print(const int *arr, size_t size) {
	for (size_t i = 0; i != size; i++)
		cout << *(arr + i) << endl;
}
int main() {
	int i = 0, j[2] = { 0, 1 };
	print(&i, &i + 1);
	print(begin(j), end(j));
	print(&i, 1);
	print(j, 2);
}