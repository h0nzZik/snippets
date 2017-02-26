struct A {};
struct C{};

enum E : int {
	A,
	AA = A + 2,
	B = 10
};

struct B{char x[20];};

enum class F : int{
	C = B + 3, // here B refers to E::B
	D = sizeof(B), // and here it refers to 'struct ::B'
	E = sizeof(D)
};

// 'struct A' is hidden by E::A
// A x;
struct A x;
C y;

static_assert(int(F::E) == sizeof(F), "");
static_assert(int(F::C) == E::B + 3, "");
static_assert(int(F::D) == 10, "");
