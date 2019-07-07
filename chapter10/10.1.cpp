#include <algorithm>
int main() {
	int i;
	vector<int> vi;
	while (cin >> i)
		vi.push_back(i);
	cout << count(vi.cbegin(), vi.cend(), 6);
}