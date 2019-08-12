HasPtr& HasPtr::operator=( const HasPtr &hp){
    if (this != &hp){    //判断是否将自身赋值给自身
    	auto temp_ps = new std::string( *hp.ps );
    	delete ps;    //删除原ps
    	ps = temp_ps;    //令ps指向新string
    	i = hp.i;
    }
    	return *this;
}