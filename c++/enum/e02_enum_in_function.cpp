// Enums in block scope

int foo()
{
	enum E {
		A = 5,
		B = 6
	};
}

// Cannot do this
int bar(enum {A,B} f) {}

