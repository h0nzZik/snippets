#include <type_traits>

// 7.2/5 '''If the underlying type is fixed, the type of each enumerator
// prior to the closing brace is the underlying type
// and the constant-expression in the enumerator-definition
// shall be a converted constant expression of the
// underlying type (5.19)'''
//
//
// But this seems to be in conflict with 5.1.1/11
// '''A nested-name-specifier that denotes an enumeration (7.2),
// followed by the name of an enumerator of that enumeration,
// is a qualified-id that refers to the enumerator. The result
// is the enumerator. The type of the result is the type
// of the enumeration. The result is a prvalue.'''

template < typename T1, typename T2 >
struct fail_if_not_same {
	static_assert(std::is_same<T1, T2>::value, "Fail!");
	static constexpr int value = 0;
};

enum class E : short {
	A,
	B = A + 1,
	C = fail_if_not_same<decltype(B), short>::value,
	D = fail_if_not_same<decltype(E::B), short>::value
};
