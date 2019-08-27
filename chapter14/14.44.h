#include <functional>..
map<string, function<int(int, int)>> binOps = {
	{"+", plus<int>()},
	{"-", minus<int>()},
	{"*", multiplies<int>()},
	{"/", divides<int>()},
	{"%", modulus<int>()}
}