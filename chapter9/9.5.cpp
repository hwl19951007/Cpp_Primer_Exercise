int func(vector<int>::iterator first, vector<int>::iterator secornd, int val){
    if (first < second){
        vector<int>::iterator begin = first, end = second;
    }else{
        vector<int>::iterator begin = second, end = first;
    }
    while(begin <= end){    //begin和end可能指向同一个目标
        if (*begin == val)
            return *begin;
        ++begin;
    }
    return -1;    //如果循环结束依然没有返回值，说明迭代器范围内没有给定的值。用-1代表失败。
}