#include <iostream>
enum E { A, B, C};
struct S {
	E e1 : 2,
	  e2 : 2,
	  e3 : 2,
	  e4 : 2;
}__attribute__((packed));

S s;

int main()
{
	std::cout << "size: " << sizeof(S) << std::endl;
}
