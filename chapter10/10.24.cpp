bool check_size(const string &str, string::size_type sz) {
	return str.size() < sz;
}
int main(){
    string str = "hello";
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    find_if(vi.begin(), vi.end(), bind(check_size, str, _1));
}