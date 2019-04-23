#include <vector>
using namespace std;
int main()
{
	vector<int> v{1,2,3,4,5};
	int arr[5];
	for (int i = 0; i < v.size(); i++) arr[i] = v[i];
}