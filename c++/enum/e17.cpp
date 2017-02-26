// Make this a part of c++-semantics test.
#include <type_traits>

// 7.2/2
// The type-specifier-seq of an enum-base shall name an integral type; any cv-qualification is ignored

enum F1: volatile int {

};

enum F2: const int {

};

static_assert(
		std::is_same<
			std::underlying_type_t<F1>,
			std::underlying_type_t<F2>
		>::value, "7.2/2: ...any cv-qualification is ignored");
