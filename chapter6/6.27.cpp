int sum(initializer_list<int> il) {
	int sum = 0;
	for (const int i : il) sum += i;
	return sum;
}