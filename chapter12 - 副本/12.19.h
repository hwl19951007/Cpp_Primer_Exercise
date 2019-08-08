#include <string>
#include <vector>
#include <memory>
#include <exception>
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// ���ɾ��Ԫ��
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back() 
	{check(0, "pop_back on empty StrBlob");
		data->pop_back();}	
	// Ԫ�ط���
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr < std::vector<std::string>> data;
	// ���data[i]���Ϸ����׳�һ���쳣
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
	// ���vectorΪ�գ� check���׳�һ���쳣
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	// ���vectorΪ�գ� check���׳�һ���쳣
	check(0, "front on empty StrBolb");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr(); //ǰ׺����
	bool operator!=(const StrBlobPtr &a) { return a.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();    // vector��������
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;    // һ������������ָ��vector��shared_ptr
}

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {    // ǰ׺���������ص�������������
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size()); 
}