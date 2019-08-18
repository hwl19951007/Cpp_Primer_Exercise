#ifndef StrVec_h
#define StrVec_h

#include <allocators>
#include <string>
#include <initializer_list>

// ��vector���ڴ������Եļ�ʵ��
class StrVec {
public:
	// allocator��Ա����Ĭ�ϳ�ʼ��
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);               // �������캯��
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);    // ������ֵ�����
	~StrVec();                           // ��������
	StrVec(StrVec &&rhs) noexcept;    // �ƶ����캯��
	StrVec& operator=(StrVec&&rhs) noexcept;    // �ƶ���ֵ�����
	void push_back(const std::string&);  // ����Ԫ��

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const std::string&);

private:
	static std::allocator<std::string> alloc;    // ����Ԫ��
	std::string *elements;      // ָ��������Ԫ�ص�ָ��
	std::string *first_free;    // ָ�������һ������Ԫ�ص�ָ��
	std::string *cap;           // ָ������β��λ�õ�ָ��

	// �����Ԫ�صĺ�����ʹ��
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// ���ߺ��������������캯����������ֵ�����������������ʹ��
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();                // ����Ԫ�ز��ͷ��ڴ�
	void reallocate();          // ��ø����ڴ沢��������Ԫ��
	void alloc_n_move(size_t);    // ��Ԫ��������������������ڴ��ַ�Ĺ��ߺ���
	void range_initialize(const std::string*, const std::string*);
};

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();     // ȷ���пռ�������Ԫ��
	// ��first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	// ����ռ䱣�������Χ�ڵ�Ԫ��
	auto data = alloc.allocate(b - e);
	// ��ʼ��������һ��pair����pair��data��uninitialized_copy�ķ���ֵ����
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	// ���ܴ��ݸ�deallcateһ����ָ�룬���elementsΪ0������ʲôҲ����
	if (elements) {
		// ��������Ԫ��
		for (auto p = first_free; p != elements;/* �� */)
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
	// ����alloc_n_copy����ռ��������� s ��һ�����Ԫ��
	range_initialize(s.begin(), s.end());
}

StrVec::StrVec(std::initializer_list<std::string> il) {
	range_initialize(il.begin(), il.end());
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec &rhs) {
	// ����alloc_n_copy�����ڴ棬��С��rhs��Ԫ��ռ�õĿռ�һ����
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
	rhs.elements = rhs.first_free = rhs.cap = nullptr;    // ʹ��ֵ���ÿ��԰�ȫ�ı�����
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs)    // ֱ�Ӽ���Ը�ֵ
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
	// �������ڴ�
	auto newdata = alloc.allocate(newcapacity);
	// �����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newdata;          // ָ���������е���һ������ 
	auto elem = elements;         // ָ��������е���һ��Ԫ��
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();     // һ�������ƶ���Ԫ�ؾ��ͷž��ڴ�ռ�
	// �������ǵ����ݽṹ��ִ����Ԫ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate() {
	// ���ǽ����䵱ǰ��С�������ڴ�ռ�
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t newcapacity) {
	if (newcapacity > capacity())     // ���Ҫ�����Ŀռ�С�ڵ����ѷ���ռ䣬�����ı�
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