int main() {
	int i = 10;
	auto f = [&i]() {if (i == 0) return true; else { while (i != 0) --i; return false; }};
	cout << f() << "   " << i << endl;
	cout << f() << "   " << i << endl;
}