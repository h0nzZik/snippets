enum class E : int;

E x;

enum class E : int {
	A = 8
};

void foo()
{
	x = E::A;
}
