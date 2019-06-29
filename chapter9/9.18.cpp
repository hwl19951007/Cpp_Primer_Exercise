int main(){
    string str;
    deque<string> deq;
    while(cin >> str)
        deq.push_back(str);
    deque<string>::const_iterator iter = deq.begin();
    while (iter != deq.end()){
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}