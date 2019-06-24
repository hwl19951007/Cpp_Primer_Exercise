#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const string& str) {
	return (str.size() > 0) ? true : false;
}
string format(const string& str) {
	return str;
}
int main(int argc, char const *argv[]) {
	string line, word;
	vector<PersonInfo> people;
	ifstream in(argv[1]);
	while (getline(in, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	ostringstream os;
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			os << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}
	cout << os.str() << endl;
	return 0;
}
