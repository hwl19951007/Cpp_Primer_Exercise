using namespace std;
int main()
{
	const char ca1[] = "Hello";
	const char ca2[] = " world!";
	char ca3[13];
	strcpy(ca3, ca1);
	strcat(ca3, ca2);
	cout << ca3 << endl;
}