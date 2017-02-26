#include <type_traits>

template < typename T1, typename T2 >
struct fail_if_not_same {
	static_assert(std::is_same<T1, T2>::value, "Fail!");
	static constexpr int value = 0;
};

enum E {
	A = char(127),
	_A = fail_if_not_same<decltype(A), decltype(char(127))>::value,
	B = 10 * 10 - (8 * 42 + 3), // == 100 - 336 - 3 == -239
	_B = fail_if_not_same<decltype(B), decltype(10 * 10 - (8 * 42 + 3))>::value,
};

enum F : int {
	C = char(127),
	_C = fail_if_not_same<decltype(C), int>::value,
	D = 10 * 10 - (8 * 42 + 3), // == 100 - 336 - 3 == -239
	_D = fail_if_not_same<decltype(D), int>::value,
};
