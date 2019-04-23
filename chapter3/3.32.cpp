#include <vector>
using namespace std;
int main()
{
	int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	int ib[10];
	for (int i = 0; i < 10; i++) ib[i] = ia[i];
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(ia[i]);
}