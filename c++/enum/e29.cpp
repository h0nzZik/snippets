#include <type_traits>

template < typename T >
struct S
{
	static constexpr int val = 5;

	static_assert(std::is_same<int, decltype(T::A)>::value, "");

};

enum E : int {
	A=1,
	/**
	 * When we uncomment the E::B enumerator,
	 * S<E> is instantiated earlier and the static assert does not fail.
	 */
	//B = S<E>::val
};

constexpr auto y = S<E>::val;
