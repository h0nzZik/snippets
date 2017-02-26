#include <iostream>

using namespace std;

enum class E1{A};
enum class E2{B};

int foo(E1)
{
	return 1;
}

int foo(E2)
{
	return 2;
}

struct C1 {
	static int bar(E1) { return 1; }
	static int moo(int) { return 1; }
};

struct C2 : public C1 {
	using C1::moo;
	using C1::bar;

	static int bar(E2) { return 2; }
	static int moo(void *) { return 2; }
	
	static int hoo(E1) { return 1; }
	static int hoo(E2) { return 2; }

	void goo();
};

void C2::goo()
{
	cout << hoo(E1::A) << '\n';
	cout << hoo(E2::B) << '\n';

	cout << moo(2) << '\n';
	cout << moo(nullptr) << '\n';

	cout << bar(E1::A) << '\n';
	cout << bar(E2::B) << '\n';
}

int main()
{
	cout << foo(E1::A) << endl;
	cout << foo(E2::B) << endl;

	C2 c2;
	c2.goo();
}
