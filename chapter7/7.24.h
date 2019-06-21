#include <string>
using namespace std;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { };
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
	char get() const { return contents[cursor]; }
	char get(pos row, pos col) { return contents[row * width + col]; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};