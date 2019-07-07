#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str = "file_name";
    ifstream input(stf);
    istream_iterator<string> iter(input), eof;
    vector<string> v(iter(input), eof);
    ostream_iterator<string> iter_out(cout, "\n");
    copy(v.begin(), v.end(), iter_out);
    cout << endl;
}