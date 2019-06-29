int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.reserve(50);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;
    while (v.size() != v.capacity())
        v.push_back(0);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;
    v.push_back(42);
    cout << "v: size: " << v.size()
         << " capacity: "  << v.capacity() << endl;    //增加1/2原有长度
    return 0;
}