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
	Screen &move(pos, pos);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os) { do_display(os); return *this; }
	const Screen &display(ostream &os) const { do_display(os); return *this; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream &os) const { os << contents; }
};
inline Screen &Screen::move(pos row, pos col) {
	pos rows = row * width;
	cursor = rows + col;
	return *this;
}
inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos row, pos col, char c) {
	contents[row * width + col] = c;
	return *this;
}