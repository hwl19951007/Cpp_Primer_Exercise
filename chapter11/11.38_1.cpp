void words_count()
{
    unordered_map<string, size_t> m;
    string word;
    while (cin >> word)
    {
        ++m[word];
    }
}