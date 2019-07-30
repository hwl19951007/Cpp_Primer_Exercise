#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;


map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			trans_map[key] = value;
	}
	return trans_map;
}

const string& transform(const string &s, const map<string, string> &m) {
	auto map_iter = m.find(s);
	if (map_iter != m.cend())
		return map_iter->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);    //读取每个单词
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc,  char* argv[]) {
	ifstream map_file(argv[1]), input(argv[2]);
	word_transform(map_file, input);
	return 0;
}