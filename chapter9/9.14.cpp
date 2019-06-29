int main() {
	char ca1[] = "Hello, World.";
	list<char *> lst(1, ca1);
	vector<string> v;
	v.assign(lst.begin(), lst.end());
	cout << *v.begin() << endl;
	return 0;
}