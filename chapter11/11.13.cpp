#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	int i;
	vector <pair <string, int> > v;
	while (true) {
		cout << "Please input a word:" << endl;
		cin >> str;
		cout << "Please input a number:" << endl;
		cin >> i;
		v.push_back({ str, i });    //ֱ����ʽ����Ĭ�Ϲ��캯��ת��Ϊpair
        //v.push_back(make_pair(str, i));    ����make_pair�������й���
        //v.push_back(pair<string, int>(str, i));       ʹ�ó�Ա���г�ʼ��
        //pair<string, int> {str, i};    ʹ�ó�Ա���г�ʼ��
        //v.push_back(p);
		cout << "if you want stop, input 'stop', if not, input anyword else." << endl;
		cin >> str;
		if (str == "stop")
			break;
	}
	for (auto &p : v)
		cout << p.first << "   " << p.second << endl;
}