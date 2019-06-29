void func(forward_list<string> &flst, string str1, string str2) {
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr == str1) {
			curr = flst.insert_after(curr, str2);
			return;
		}
		else {
			prev = curr;
			++curr;
		}
	}
	flst.insert_after(prev, str2);
}