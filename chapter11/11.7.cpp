#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	map<string, vector<string>> fam;
	string fam_name, name;
	while (true) {
		cout << "First, input your family name: " << endl;
		cin >> fam_name;
		cout << "Second, input your childen's name, or input over to 'end' input." << endl;
		while (cin >> name) {
			if (name == "end")
				break;
			fam[fam_name].push_back(name);
		}
		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
		cin >> name;
		if (name == "stop")
			break;
	}
	for (auto f : fam) {
		cout << "famile name: " << f.first  << "children's names: " << '\n' <<  endl;
		for (auto name : f.second)
			cout << name << endl;
	}
}