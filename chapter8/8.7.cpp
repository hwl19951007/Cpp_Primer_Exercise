#include <iostream>
#include <string>
#include <fstream>
#include "Sales_data.h"
using namespace std;
int main(int argc,char *argv[]){
    Sales_data total;
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if (in){
		if (read(in, total)) {
			Sales_data trans;
			while(read(in ,trans)) {
				if(total.isbn() == trans.isbn())
					total.combine(trans);
				else {
					print(out, total) << endl;
					total =trans;
				}
			}
			print(out, total)<<endl;
		}
		else {
			cerr<<" No data?!"<<endl;
		}
    }
    return 0;
}