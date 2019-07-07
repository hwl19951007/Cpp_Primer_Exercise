int main() {
	int i = 5;
	auto f = [i](int j) {return i + j; };
	cout << f(5);
}