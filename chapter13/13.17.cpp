#include <iostream>
using namespace std;

class numbered1 {
public:
	numbered1() { mysn = unique++; }
	int mysn;
	static int unique;
};
class numbered2 {
public:
	numbered2() { mysn = unique++; }
	numbered2(const numbered2&) { mysn = unique++; }
	int mysn;
	static int unique;
};
int numbered1::unique = 10;
int numbered2::unique = 20;

void f(numbered1 s) { cout << s.mysn << endl; }
void f(numbered2 s) { cout << s.mysn << endl; }
void fc(const numbered2& s) { cout << s.mysn << endl; }
int main() {
	numbered1 a , b = a, c = b;
	f(a); f(b); f(c);
	numbered2 d, e = d, g = e;
	f(d); f(e); f(g);
	fc(d); fc(e); fc(g);
}