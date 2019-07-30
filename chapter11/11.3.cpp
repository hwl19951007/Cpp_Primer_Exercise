#include <iostream>
#include <map>
#include <string>
using namespace std;

void words_count()
{
    map<string, size_t> m;
    string word;
    while (cin >> word)
    {
        ++m[word];
    }
}