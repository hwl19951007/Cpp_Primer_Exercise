int main(){
    vector<int> vi(10, 10);
    fill_n(vi.begin(), vi.size(), 0);
    for (int i : vi)
        cout << i << endl;
}