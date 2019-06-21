class Tree
{
private:
	std::string Name;
	unsigned Age = 0;
	double Height = 0;
public:
	Tree() = default;
	Tree(const std::string &n, unsigned a, double h)
		: Name(n), Age(a), Height(h)
};