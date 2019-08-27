//主函数部分修改，以count统计长度在1-9之间的单词有多少个等。或修改类为边界统计形式
class IsInRange(){
    size_t max,min;
    public:
    IsInRange(size_t i, size_t j) : min(i), max(j) {}
    bool operator()(const string& str){
        return str.size() >= min && str.size() <= max;
    }
}
//主函数略