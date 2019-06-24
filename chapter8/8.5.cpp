#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main(int argc,char *argv[]){
    ifstream in(argv[1]);
    vector<string> v;
    if (in){
        string s;
        while(in >> s){
            v.push_back(s);
        }else{
            cerr << "got wrong filename." << endl;
        }
    }
    return 0;
}