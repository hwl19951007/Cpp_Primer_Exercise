#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void words_count()
{
	map<string, size_t> m;
	string word;
		while (cin >> word)
		{
            //利用标准库进行大写转小写
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			auto iter = word.begin();
			while (iter != word.end()) {    //删除标点符号
				if (ispunct(*iter))
					iter = word.erase(iter);
				else
					++iter;
			}
			++m[word];
		}
		for (auto c : m)
			cout << c.first << c.second;
}