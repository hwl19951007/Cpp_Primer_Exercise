HasPtr& HasPtr::operator=( const HasPtr &hp){
    if (this != &hp){    //�ж��Ƿ�����ֵ������
    	auto temp_ps = new std::string( *hp.ps );
    	delete ps;    //ɾ��ԭps
    	ps = temp_ps;    //��psָ����string
    	i = hp.i;
    }
    	return *this;
}