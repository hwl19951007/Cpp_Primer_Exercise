class Employee {
public:
	Employee() { id = unique++; };
	Employee(const std::string& str) : name(str) { id = unique++; };
	Employee(const Employee&) = delete;
	Employee& operator = (const Employee&) = delete;
private:
	std::string name;
	int id;
	static int unique;
};