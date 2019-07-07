#include <fstream>
#include <iterator>
using namespace std;

void func(const string& input_filename, const string& output_filename1, const string& output_filename2) {
	ifstream  in(input_filename);
	istream_iterator<int> iter_in(in), eof;
	ofstream of1(output_filename1), of2(output_filename2);
	ostream_iterator<int> iter_out1(of1, " "), iter_out2(of2, "\n");
	while (iter_in != eof) {
		if (*iter_in & 1 == 1)
			*iter_out1++ = *iter_in;
		else
			*iter_out2++ = *iter_in;
		++iter_in;
	}
}