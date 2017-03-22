enum class E{};

constexpr bool operator==(E, E) { return false; }
constexpr bool operator!=(E l, E r) { return !(l == r); }

static_assert(E{} != E{}, "Overloading");

constexpr E operator&(E x) { return x; }



