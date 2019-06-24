struct PersonInfo {
	string name;
	vector<string> phones;
};
int main(int argc, char const *argv[]) {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	return 0;
}