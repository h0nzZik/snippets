/*
 *
 * An expression e can be explicitly converted to a type T using a static_cast of the form static_cast<T>(e)
if the declaration T t(e); is well-formed, for some invented temporary variable t (8.5). The effect of such an
explicit conversion is the same as performing the declaration and initialization and then using the temporary
variable as the result of the conversion. The expression e is used as a glvalue if and only if the initialization
uses it as a glvalue.
*/

enum E { U=0, V=3 };

int main()
{
	E e1 = static_cast<E>(2);
	E e2 = (E)2;
	E e3(3);
}
