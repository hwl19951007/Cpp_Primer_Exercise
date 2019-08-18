#ifndef Message_h
#define Message_h

#include <set>
class Folder;

class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	// folder ����ʽ��ʼ��Ϊ�ռ���
	explicit Message(const std::string &str = "") : contents(str) {}  
	// �������Ƴ�Ա����������ָ��Message��ָ��
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	// �Ӹ���Folder���������/ɾ����Message
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;    // ������Message��Folder
	// �������Ƴ�Ա��ʹ�õĵĹ��ߺ���
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

class Folder { 
	friend class Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;
	// �������Ƴ�Ա
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder&);
	void remove_from_Message();
	void addMsg(Message *m) { msgs.insert(m); };
	void remMsg(Message *m) { msgs.erase(m); };
};

void Message::save(Folder &f) {
	folders.insert(&f);    // ������Folder��ӵ����ǵ�Folder�б���
	f.addMsg(this);    // ����Message��ӵ�f��Message������
}

void Message::remove(Folder &f) {
	folders.erase(&f);    // ������Folder�����ǵ�Folder�б���ɾ��
	f.remMsg(this);    // ����Message��f��Message������ɾ��
}
// ����Message��ӵ�ָ��m��Floder��
void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders)    // ��ÿ������m��Folder
		f->addMsg(this);    // ���Folder���һ��ָ��Message��ָ��
}

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);    // ������Ϣ��ӵ�ָ��M��Folder��
}

void Message::remove_from_Folders() {
	for (auto f : folders)    // ��folders��ÿ��ָ��
		f->remMsg(this);    // �Ӹ�Folder��ɾ����Message
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
	// ͨ����ɾ������ָ���ٲ��������������Ը�ֵ���
	remove_from_Folders();    // ��������Folder
	contents = rhs.contents;    // ��rhs������Ϣ��Folderָ��
	folders = rhs.folders;
	add_to_Folders(rhs);    // ����Message��ӵ���ЩFolder��
	return *this;
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	// ��ÿ����Ϣ��ָ�������ԭ�������ڵ�Folder��ɾ��
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// ����contents��Folderָ��set
	swap(lhs.folders, rhs.folders);    // ʹ��swap(set&, set&)
	swap(lhs.contents, rhs.contents);    // ʹ��swap(string&, string&)
	// ��ÿ��Message��ָ����ӵ����ģ��£�Folder��
	lhs.add_to_Folders(lhs);    // ʹ�ù��ߺ�����������ظ�
	rhs.add_to_Folders(rhs);
}
// ��������ӵ�����Folder�е�Message��Folder����
void Folder::add_to_Message(const Folder &f) {
	for (auto m : f.msgs)
		m->addFldr(this);
}
// ������������Message������ɾ��
void Folder::remove_from_Message() {
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
	add_to_Message(f);
}

Folder::~Folder() {
	remove_from_Message();
}

Folder& Folder::operator=(const Folder&f) {
	remove_from_Message();    // �����Ը�ֵ
	msgs = f.msgs;
	add_to_Message(f);
	return *this;
}

void swap(Folder &lhs, Folder &rhs) {
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

#endif // !Message_h
