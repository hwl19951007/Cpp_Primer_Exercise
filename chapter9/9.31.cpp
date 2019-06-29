//forward_list
int main() {
	forward_list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = lst.begin();
	auto prev = lst.before_begin();
	while (curr != lst.end()) {
		if (*curr % 2) {
			lst.insert_after(prev, *curr);
			prev = curr;
			++curr;
		}
		else
			curr = lst.erase_after(prev);
	}
	for (auto i : lst)
		cout << i << endl;
}
//list
int main() {
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = lst.begin();
	while (curr != lst.end()) {
		if (*curr % 2) {
			curr = lst.insert(curr, *curr);
			++curr;
			++curr;
		}
		else
			curr = lst.erase(curr);
	}
	for (auto i : lst)
		cout << i << endl;
}