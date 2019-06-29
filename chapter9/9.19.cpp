int main(){
    string str;
    list<string> deq;
    while(cin >> str)
        deq.push_back(str);
    list<string>::const_iterator iter = deq.begin();
    while (iter != deq.end()){
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}