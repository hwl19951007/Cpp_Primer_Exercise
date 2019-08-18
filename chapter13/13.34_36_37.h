#ifndef Message_h
#define Message_h

#include <set>
class Folder;

class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	// folder 被隐式初始化为空集合
	explicit Message(const std::string &str = "") : contents(str) {}  
	// 拷贝控制成员，用来管理指向本Message的指针
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	// 从给定Folder集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;    // 包含本Message的Folder
	// 拷贝控制成员所使用的的工具函数
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
	// 拷贝控制成员
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
	folders.insert(&f);    // 将给定Folder添加到我们的Folder列表中
	f.addMsg(this);    // 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f) {
	folders.erase(&f);    // 将给定Folder从我们的Folder列表中删除
	f.remMsg(this);    // 将本Message从f的Message集合中删除
}
// 将本Message添加到指向m的Floder中
void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders)    // 对每个包含m的Folder
		f->addMsg(this);    // 向改Folder添加一个指向本Message的指针
}

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);    // 将本消息添加到指向M的Folder中
}

void Message::remove_from_Folders() {
	for (auto f : folders)    // 对folders中每个指针
		f->remMsg(this);    // 从该Folder中删除本Message
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
	// 通过先删除自身指针再插入它们来处理自赋值情况
	remove_from_Folders();    // 更新已有Folder
	contents = rhs.contents;    // 从rhs拷贝消息和Folder指针
	folders = rhs.folders;
	add_to_Folders(rhs);    // 将本Message添加到那些Folder中
	return *this;
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	// 将每个消息的指针从它（原来）所在的Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// 交换contents和Folder指针set
	swap(lhs.folders, rhs.folders);    // 使用swap(set&, set&)
	swap(lhs.contents, rhs.contents);    // 使用swap(string&, string&)
	// 将每个Message的指针添加到它的（新）Folder中
	lhs.add_to_Folders(lhs);    // 使用工具函数避免代码重复
	rhs.add_to_Folders(rhs);
}
// 将自身添加到参数Folder中的Message的Folder集合
void Folder::add_to_Message(const Folder &f) {
	for (auto m : f.msgs)
		m->addFldr(this);
}
// 将自身从自身的Message集合中删除
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
	remove_from_Message();    // 避免自赋值
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
