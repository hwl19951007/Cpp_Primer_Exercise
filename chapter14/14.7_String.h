#ifndef String_h
#define String_h

#include <memory>
#include <algorithm>
#include <iostream>

class String {
public:
	String() : String("") {}    // ί�й��캯��
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&)noexcept;    // �ƶ����캯��
	String& operator=(String&&)noexcept;    // �ƶ���ֵ�����
	~String();
private:
	char *elements;
	char *end;
	static std::allocator<char> alloc;

	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
	void print();

	friend std::ostream& operator<<(std::ostream &os, const String  &str);
};

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b,e,data) };
}

String::String(const char* c) {
	auto e = c;
	while (*e != '\0') e++;    // �ҵ��ַ����ĳ���
	e++;
	auto data = alloc_n_copy(c, e);
	elements = data.first;
	end = data.second;
	print();
}

String::String(const String &rhs) {
	auto data = alloc_n_copy(rhs.elements, rhs.end);
	elements = data.first;
	end = data.second;
	print();
}

void String::free() {
	if (elements) {
		std::for_each(elements, end, [](char &c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}

String& String::operator=(const String &rhs) {
	auto data = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = data.first;
	end = data.second;
	return *this;
}

String::~String() { free(); }

String::String(String &&rhs) noexcept : elements(rhs.elements), end(rhs.end) {
	rhs.elements = rhs.end = nullptr;    // ���Ҳ������Ϊ��������״̬
}

String& String::operator=(String &&rhs) noexcept {
	if (this != &rhs) {    // ����Ը�ֵ
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}
void String::print() {
	std::cout << "This is a String." << std::endl;
}

std::ostream& operator<<(std::ostream &os, const String  &str) {
	for (char* p = str.elements; p != str.end; p++)
		os << *p;
	return os;
}
#endif // !StrVec_h