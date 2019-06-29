bool compare(const vector<int>& v1, const vector<int>& v2){
    bool result = true;
    if (v1.size() == v2.size()){
        vector<int>::const_iterator begin1 = v1.begin(), begin2 = v2.begin();
        while(begin1 != v1.end()){
            if (*begin1 != *begin2){
                result = false;
                break;
            }
            ++begin1, ++begin2;
        }
    }
    return result;
}