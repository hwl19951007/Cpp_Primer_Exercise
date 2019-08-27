class MyClass
{
public:
	std::string* operator->() const{
        return ptr;}
private:
	StrBlobPtr *ptr;
}