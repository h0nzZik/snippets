struct A {
	constexpr A() = default;
	constexpr operator int() const { return 5; }
};

enum /*class*/ E {
	X = A{} // constant-expression shall be an integral constant expression
};
