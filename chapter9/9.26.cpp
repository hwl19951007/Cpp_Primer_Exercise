int main() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> v;
	list<int> lst;
	for (int i : ia) {
		v.push_back(i);
		lst.push_back(i);
	}
	vector<int>::iterator iterV = v.begin();
	while (iterV != v.end()) {
		if (*iterV % 2 != 1)
			iterV = v.erase(iterV);
		else
			++iterV;
	}
	list<int>::iterator iterL = lst.begin();
	while (iterL != lst.end()) {
		if (*iterL % 2)
			iterL = lst.erase(iterL);
		else
			++iterL;
	}
}