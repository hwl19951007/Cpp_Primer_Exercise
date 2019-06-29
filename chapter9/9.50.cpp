int main() {
	vector<string> v = { "1", "2", "3", "4", "5" };
	int resultI = 0;
	for (const string& str : v)
		resultI += stoi(str);
	cout << resultI << endl;
	float resultF = 0.0;
	for (const string& str : v)
		resultF += stof(str);
	cout << resultF << endl;
}