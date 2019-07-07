void eliminate_duplicates(vector<string> &v)
{
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << "  ";
    cout << endl;

    auto end_unique = unique(v.begin(), v.end());
    for (auto i : v)
        cout << i << "  ";
    cout << endl;

    v.erase(end_unique, v.end());
    for (auto i : v)
        cout << i << "  ";
    cout << endl;
}
int main()
{
    vector<string> v = {"abc", "abc", "efg", "hij", "klmn", "opq", "xyz", "klmn"};
    eliminate_duplicates(v);
    return 0;
}