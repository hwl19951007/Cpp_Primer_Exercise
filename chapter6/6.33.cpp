void print(vector<int>::iterator vi, vector<int>::iterator end) {
	if (vi != end) { 
		cout << *vi << endl;
		print(++vi, end);
	}
}