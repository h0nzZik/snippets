template < typename T>
struct X
{
	using type = T;
	static constexpr int B = T::A + 1;
	static auto bar(){
		return sizeof(T);
	}

	// error: invalid application of 'sizeof' to an incomplete type 'E'
	// (in instantiation of template class 'X<E>' requested in definition of 'E')
	// static constexpr int C = sizeof(T);
};

enum E {
	A = 1,
	B = X<E>::B
};


void foo()
{
	X<E>::bar();
	(void)sizeof(X<E>::type);
}
