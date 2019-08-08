#include <iostream>
#include <vector>
using namespace std;

vector<int>* build() {
	vector<int> *p(new vector<int>());
	return p;
}
vector<int>* write(vector<int> *p) {
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void read(vector<int> *p) {
	for (int i : *p)
		cout << i << endl;
	delete p;
}
int main() {
	read(write(build()));
	return 0;
}