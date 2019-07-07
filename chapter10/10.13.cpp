bool morethan5(const string &str) {
	return str.size() > 4;
}
int main() {
	vector<string> v{ "1", "12", "123", "1234", "12345", "123456" };
	for (const string &str : v) {
		if (morethan5(str))
			cout << str << endl;
	}
}