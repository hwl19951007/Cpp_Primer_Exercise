#include <string>
using namespace std;
class Screen;    //Windows_mgr����Screen������˵�������
class Window_mgr {  //�ȶ���Window_mgr��
public:
	using ScreenIndex = vector<Screen>::size_type;    //Screen����
	void clear(ScreenIndex i);  //������������������
private:
	vector<Screen> screens;//{Screen(24, 80, ' ')};ֱ�ӵ���Screen�Ĺ��캯�����ᱨ��
};
class Screen {  //������������Screen��
public:
	friend void Window_mgr::clear(ScreenIndex i);   //��������Ԫ����
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
inline void Window_mgr::clear(ScreenIndex i) {  //�����clear����
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}