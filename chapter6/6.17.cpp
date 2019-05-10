bool upper_in_string(const string & str) {
	bool tag = false;
	for (char c : str) {
		tag = isupper(c);
		if (tag == true) break;
	}
	return tag;
}
void string_to_lower(string & str) {
	for (char &c : str) c = tolower(c);
}