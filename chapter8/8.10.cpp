#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
	vector<string> v;
	fstream in(argv[1]);
	if (in) {
		string line;
		while (getline(in, line)) {
			cout << line << endl;
			v.push_back(line);
		}
	}
	string oneWord;
	for (const string& s : v) {
		istringstream word(s);
		while (word >> oneWord) {
			cout << oneWord << endl;
		}
	}
}
