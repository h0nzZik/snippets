#include <iostream>
// An expression e can be explicitly converted to a type T using a static_cast of the form static_cast<T>(e)
// if the declaration T t(e); is well-formed, for some invented temporary variable t

enum E1 : int { A = 5 };
enum class E2 : int { B = 5 };


int main()
{
	int x(E1::A);
// error: cannot initialize a variable of type 'int' with an rvalue of type 'E2'
	int y(E2::B);

	std::cout << x << ", " << y << std::endl
}
