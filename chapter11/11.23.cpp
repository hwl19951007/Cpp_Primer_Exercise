#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	multimap<string, string> fam;
	string fam_name, name;
	while (true) {
		cout << "First, input your family name: " << endl;
		cin >> fam_name;
		cout << "Second, input your childen's name: " << endl;
		cin >> name;
        fam[fam_name] = name;
		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
		cin >> name;
		if (name == "stop")
			break;
	}
	for (auto f : fam) {
		cout << "famile name: " << f.first  << "children's names: "<<  endl;
		for (auto name : f.second)
			cout << name << endl;
	}
}