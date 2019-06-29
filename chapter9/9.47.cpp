int main() {
	string str("ab2c3d7R4E6");
	string letter("abcdRE");
	string number("23467");
	string::size_type pos = 0;
	while ((pos = str.find_first_of(number, pos)) != string::npos) {
		cout << "found number at index: " << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_of(letter, pos)) != string::npos) {
		cout << "found letter at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(letter, pos)) != string::npos) {
		cout << "found number at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(number, pos)) != string::npos) {
		cout << "found letter at index:" << pos << ", element is " << str[pos] << endl;
		++pos;
	}
}