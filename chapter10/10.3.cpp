#include <numeric>
int main(){
    vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    cout << accumulate(vi.cbegin(), vi.cend(), 0) << endl;
}