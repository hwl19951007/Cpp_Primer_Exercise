#ifndef StrBlob_h
#define StrBlob_h

#include <string>
#include <vector>
#include <memory>
#include <exception>
class ConstStrBlobPtr;

class StrBlob {
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	//拷贝构造函数
	StrBlob(const StrBlob& rhs) : data(std::make_shared<std::vector<std::string>>(*rhs.data)) { };
	//拷贝赋值运算符
	StrBlob& operator=(const StrBlob& rhs) { data = std::make_shared<std::vector<std::string>>(*rhs.data); return *this; };
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加删减元素
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	// 元素访问
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	ConstStrBlobPtr begin() const;     //两个函数改为const成员函数
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr < std::vector<std::string>> data;
	// 如果data[i]不合法，抛出一个异常
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front() {
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const {
	// 如果vector为空， check会抛出一个异常
	check(0, "front on empty StrBolb");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}


class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}    // 接受参数改为const StrBlob&
	const std::string& deref() const;    //根据逻辑，此处的返回值应为const
	ConstStrBlobPtr& incr(); //前缀递增
	bool operator!=(const ConstStrBlobPtr &a) { return a.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();    // vector还存在吗
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;    // 一切正常，返回指向vector的shared_ptr
}

const std::string& ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {    // 前缀递增，返回递增后对象的引用
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr StrBlob::begin() const {
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
	return ConstStrBlobPtr(*this, data->size());
}

#endif // StrBlob_h