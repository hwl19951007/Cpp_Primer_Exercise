#include <iostream>
#include <vector>
#include <algorithm>
class IsEqual {
	int value;
public:
	IsEqual(int i) : value(i) {}
	bool operator()(int i) {
		return i == value;
	}
};
int main() {
	std::vector<int> v = { 1,2,3,3,3,4,5 };
	std::replace_if(v.begin(), v.end(), IsEqual(3), 5);
	for (int i : v) std::cout << i << " ";
}