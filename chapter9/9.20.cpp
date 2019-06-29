int main(){
    list<int> lst = {1,2,3,4,5,6,7,8,9,10};
    deque<int> odd, even;
    list<int>::iterator iter = lst.begin();
    while (iter != lst.end()){
        if (*iter % 2 == 1)
            odd.push_back(*iter);
        else
            even.push_back(*iter);
		++iter;
    }
    return 0;
}