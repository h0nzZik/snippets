#include <iostream>

using namespace std;

static constexpr int x = 7;

enum class E {
	x = 2,
	y = x + 2
};

enum class F {
	x = x + 1
};

// $3.4.1, par. 12
// During the lookup of a name used in the constant-expression of an enumerator-definition, previously declared
// enumerators of the enumeration are visible and hide the names of entities declared in the block, class, or
// namespace scopes containing the enum-specifier.
int main()
{
	// output: 7
	cout << "x=" << x << endl;

	// output: 4
	cout << "E::y=" << int(E::y) << endl;

	// output: 8
	cout << "F::x=" << int(F::x) << endl;
}
