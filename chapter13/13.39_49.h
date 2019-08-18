#ifndef StrVec_h
#define StrVec_h

#include <allocators>
#include <string>
#include <initializer_list>

// 类vector类内存分配策略的简化实现
class StrVec {
public:
	// allocator成员进行默认初始化
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);               // 拷贝构造函数
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);    // 拷贝赋值运算符
	~StrVec();                           // 析构函数
	StrVec(StrVec &&rhs) noexcept;    // 移动构造函数
	StrVec& operator=(StrVec&&rhs) noexcept;    // 移动赋值运算符
	void push_back(const std::string&);  // 拷贝元素

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const std::string&);

private:
	static std::allocator<std::string> alloc;    // 分配元素
	std::string *elements;      // 指向数组首元素的指针
	std::string *first_free;    // 指向数组第一个空闲元素的指针
	std::string *cap;           // 指向数组尾后位置的指针

	// 被添加元素的函数所使用
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();                // 销毁元素并释放内存
	void reallocate();          // 获得更多内存并拷贝已有元素
	void alloc_n_move(size_t);    // 将元素移至扩增容量后的新内存地址的工具函数
	void range_initialize(const std::string*, const std::string*);
};

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();     // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	// 分配空间保存给定范围内的元素
	auto data = alloc.allocate(b - e);
	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	// 不能传递给deallcate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁元素
		for (auto p = first_free; p != elements;/* 空 */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::range_initialize(const std::string *first, const std::string *last) {
	auto newdata = alloc_n_copy(first, last);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s) {
	// 调用alloc_n_copy分配空间以容纳与 s 中一样多的元素
	range_initialize(s.begin(), s.end());
}

StrVec::StrVec(std::initializer_list<std::string> il) {
	range_initialize(il.begin(), il.end());
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec &rhs) {
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用的空间一样大
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
	rhs.elements = rhs.first_free = rhs.cap = nullptr;    // 使右值引用可以安全的被析构
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs)    // 直接检测自赋值
	{
        free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::alloc_n_move(size_t newcapacity) {
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 将数据从旧内存移动到新内存
	auto dest = newdata;          // 指向新数组中的下一个空闲 
	auto elem = elements;         // 指向旧数组中的下一个元素
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();     // 一旦我们移动完元素就释放旧内存空间
	// 更新我们的数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate() {
	// 我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t newcapacity) {
	if (newcapacity > capacity())     // 如果要求分配的空间小于等于已分配空间，不做改变
		alloc_n_move(newcapacity);
}

void StrVec::resize(size_t count) {
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &str) {
	if (count < size()) {
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
	else if (count > size()) {
		alloc_n_move(count * 2);
		while (first_free != elements + count)
			alloc.construct(first_free++, str);
	}
}

#endif // !StrVec_h