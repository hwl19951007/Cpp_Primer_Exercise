string func(const string & str,const string & prefix,const string & suffix){
    string result(str);
    auto beg = result.begin();
    result.insert(beg, prefix.begin(), prefix.end());
    result.append(suffix);
    return result;
}