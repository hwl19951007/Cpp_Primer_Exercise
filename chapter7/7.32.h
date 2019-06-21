#include <string>
using namespace std;
class Screen;    //Windows_mgr含有Screen对象，因此得先声明
class Window_mgr {  //先定义Window_mgr类
public:
	using ScreenIndex = vector<Screen>::size_type;    //Screen坐标
	void clear(ScreenIndex i);  //声明函数，但不定义
private:
	vector<Screen> screens;//{Screen(24, 80, ' ')};直接调用Screen的构造函数将会报错
};
class Screen {  //后声明并定义Screen类
public:
	friend void Window_mgr::clear(ScreenIndex i);   //并声明友元函数
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { };
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { };
    //...
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};
//...
inline void Window_mgr::clear(ScreenIndex i) {  //最后定义clear函数
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}