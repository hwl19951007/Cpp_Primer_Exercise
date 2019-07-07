#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	istream_iterator<int> in(cin), eof;
	vector<int> v(in, eof);
	sort(v.begin(), v.end());
	ostream_iterator<int> out(cout, "\n");
	copy(v.begin(), v.end(), out);
	cout << endl;
}