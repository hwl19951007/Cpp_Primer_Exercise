class Employee {
public:
	Employee() { id = unique++; };
	Employee(const std::string& str) : name(str) { id = unique++; };
private:
	std::string name;
	int id;
	static int unique;
};
int static unique = 0;