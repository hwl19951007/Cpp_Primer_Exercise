#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	map < string, vector < pair <string, string> >> fam;
	string fam_name, name, birthday;
	while (true) {
		cout << "First, input your family name: " << endl;
		cin >> fam_name;
		cout << "Second, input your childen's name: " << endl;
		cin >> name;
		cout << "Third, input your childen's birthday: " << endl;
		cin >> birthday;
		fam[fam_name].push_back({ name, birthday });
		cout << "If you want stop input, input 'stop'. If you want continue, input anyword else." << endl;
		cin >> name;
		if (name == "stop")
			break;
	}
	for (auto f : fam) {
		cout << "famile name: " << f.first << endl;
		for (auto p : f.second) {
			cout << "Children's name :" << p.first << "Children's birthday : " << p.second << endl;
		}
	}
}