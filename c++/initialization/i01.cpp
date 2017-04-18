// based on http://stackoverflow.com/q/29765961/6209703

#include <iostream>
using namespace std;

struct A { int m; };


void test_1() {
	char buf[200];

	/* Default initialization, only compiler generated default constructor.
	 * Leaves A::m uninitialized.
	 */

	for (char & b : buf)
		b = 0x55;

	A * a = new(buf) A;
	cout << "a->m: " << a->m << '\n';
	a->~A();

	/* Value initialization, which performs zero initialization.
	 * A::m is set to zero.
	 */


	for (char & b : buf)
		b = 0x55;
	
	a = new (buf) A();
	cout << "a->m: " << a->m << '\n';
	a->~A();
}

#if 1
struct B { B(); int m; };
B::B() = default;
#else
struct B { B(){} int m; };
#endif
void test_2() {
	/* For B, zero initialization does not happen, because it has a constructor.
	 * However, if B::B was explicitly defaulted _in the declaration_, it would be
	 * zero-initialized.
	 */
	char buf[200];

	for (char & b : buf)
		b = 0x55;

	B * b = new(buf) B;
	cout << "b->m: " << b->m << '\n';
	b->~B();

	for (char & b : buf)
		b = 0x55;
	
	b = new (buf) B();
	cout << "b->m: " << b->m << '\n';
	b->~B();

}

int main() {
	test_1();
	test_2();
}
