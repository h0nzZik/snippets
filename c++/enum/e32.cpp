enum E { A=0, B=2 };

constexpr E e0 = E(0);
constexpr E e1 = E(1);
constexpr E e2 = E(2);
constexpr E e3 = E(3);

// I though this is an undefined behaviour, so the constexpr should fail.
// But it doesnot.
constexpr E e4 = E(4);

static_assert(int(e4) == 4, "But why?");

