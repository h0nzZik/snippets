// An enumerator-definition
// without an initializer gives the enumerator the value obtained by increasing the value of the previous enu-
// merator by one.

template < typename T1, typename T2>
struct err_if_not_same {
	static_assert(std::is_same<T1, T2>::value, "Error");
};

enum E {
	A = char(1),
	B,
};
