int func(vector<int>::iterator first, vector<int>::iterator secornd, int val){
    if (first < second){
        vector<int>::iterator begin = first, end = second;
    }else{
        vector<int>::iterator begin = second, end = first;
    }
    while(begin <= end){    //begin��end����ָ��ͬһ��Ŀ��
        if (*begin == val)
            return *begin;
        ++begin;
    }
    return -1;    //���ѭ��������Ȼû�з���ֵ��˵����������Χ��û�и�����ֵ����-1����ʧ�ܡ�
}