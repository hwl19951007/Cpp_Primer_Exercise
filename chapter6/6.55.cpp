#include <vector>
using namespace std;
int fun1(int i, int j) { return i + j; }
int fun2(int i, int j) { return i - j; }
int fun3(int i, int j) { return i * j; }
int fun4(int i, int j) { return i / j; }
int main()
{
	vector<int(*)(int, int)> v = {fun1, fun2, fun3, fun4};
}