#include <type_traits>

class Base{};
class Derived1 : public Base {

};

class Derived2 : private Base {

};

static_assert(std::is_base_of<Base, Derived1>::value, "");

// It works even for private inheritance.
static_assert(std::is_base_of<Base, Derived2>::value, "");
