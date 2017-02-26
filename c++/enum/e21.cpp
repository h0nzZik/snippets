// This is crazy

template < typename T>
struct S {
	static constexpr int value1 = T::A;
	//static constexpr int value2 = x;
};

static constexpr int x = 7;

enum E {
	A = 1,
	B = S<E>::value1,
	//C = S<E>::value2
};
