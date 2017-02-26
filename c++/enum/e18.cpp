// 7.2/3 An opaque-enum-declaration is either a redeclaration of an enumeration
// in the current scope...
enum E : int {
	X,Y,Z
};

enum E : int;

// 7.2/3 ... or a declaration of a new enumeration.

enum class F;

// [ Note: An enumeration declared by an opaque-enum-declaration has fixed underlying
// type and is a complete type. The list of enumerators can be provided in a later redeclaration with an enum-
// specifier. — end note ]

F f;

enum class F {
	A,B,C
};

void foo() { f = F::C; }
