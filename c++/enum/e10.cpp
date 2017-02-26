#include <type_traits>

class {} c1;
class {} c2;

enum {} e1;
enum {} e2;

static_assert(std::is_same<decltype(c1), decltype(c2)>::value == false, "Should be different");
static_assert(std::is_same<decltype(e1), decltype(e2)>::value == false, "Should be different");




