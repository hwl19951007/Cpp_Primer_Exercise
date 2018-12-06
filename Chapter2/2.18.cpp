#include <iostream>
int main()
{
	int i = 100, j = 200, *p = &i;
	p = &j;    //更改指针的值
	*p = 100;  //更改指针所指向对象的值
	return 0;
}