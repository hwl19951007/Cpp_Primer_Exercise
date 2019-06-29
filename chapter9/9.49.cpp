int main(int argc, char const * argv[]){
    string noneed("bdfhkltgjpqy");
    string word, result;
    fstream& in(argv[1]);
    while(in >> word){
        if (word.find_first_in(noneed) == string::npos && word.size() > result.size())
            result = word;
    }
    cout << result;
}