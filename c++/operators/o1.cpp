#include <iostream>
using namespace std;

struct C {
	int x;
	C(int x) : x(x) {}

	operator int() const { return x/2; }
};
/*
 *
 *2
Overload resolution selects the function to call in seven distinct contexts within the language:
(2.1) — invocation of a function named in the function call syntax (13.3.1.1.1);
(2.2) — invocation of a function call operator, a pointer-to-function conversion function, a reference-to-pointer-
to-function conversion function, or a reference-to-function conversion function on a class object named
in the function call syntax (13.3.1.1.2);
(2.3) — invocation of the operator referenced in an expression (13.3.1.2);
(2.4) — invocation of a constructor for default- or direct-initialization (8.5) of a class object (13.3.1.3);
(2.5) — invocation of a user-defined conversion for copy-initialization (8.5) of a class object (13.3.1.4);
(2.6) — invocation of a conversion function for initialization of an object of a nonclass type from an expression
of class type (13.3.1.5); and
(2.7) — invocation of a conversion function for conversion to a glvalue or class prvalue to which a reference (8.5.3) will be directly bound (13.3.1.6).
 *
 */

/* Case 1: named function */
// invocation of a function named in the function call syntax (13.3.1.1.1);

void named_function(int) {
	cout << "named_function(int)" << endl;
}

void named_function(char const *) {
	cout << "named_function(char const *)" << endl;
}

void test_1() {
	cout << "\nCase 1\n------\n";
	named_function(3);
	named_function("hello");
}

// TODO: do the subcase in elipsis
// invocation of a function call operator (...) on a class object named
// in the function call syntax

struct Test2 {
	void operator()(int) { cout << "Test2::operator()(int)" << endl; }
	void operator()(char const *) { cout << "Test2::operator()(char const *)" << endl; }
};


void test_2() {
	cout << "\nCase 2\n------\n";

	Test2 t;
	t(3);
	t("hello");
}

// invocation of the operator referenced in an expression

struct Test3 {
	bool operator==(int) { cout << "Test3::operator==(int)" << endl; return false; }
	bool operator==(char const *) { cout << "Test3::operator==(char const *)" << endl; return false; }
};

void test_3() {
	cout << "\nCase 3\n------\n";

	Test3 t;
	(void)(t == 3);
	(void)(t == "hello");
}


// invocation of a constructor for default- or direct-initialization (8.5) of a class object (13.3.1.3);
//
// I do not understand onverloading on default constructor...?
// TODO: check how it behaves on copy-initialization

struct Test4 {
	explicit Test4(int) { cout << "Test4::Test4(int)" << endl; }
	explicit Test4(char const *) { cout << "Test4::Test4(char const *)" << endl; }
};

void test_4() {
	cout << "\nCase 4\n------\n";

	// This is _not_ a direct-initialization
	// Test4 t1 = 5;

	Test4 t1{5};
	Test4 t2{"ahoj"};
}

// invocation of a user-defined conversion for copy-initialization (8.5) of a class object (13.3.1.4);
// TODO: check again how it behaves on direct-initialization

struct T5A {};
struct T5B {};
struct T5C {
	operator T5A() const { cout << "T5C::operator T5A() const" << endl; return T5A{}; }
	operator T5B() const { cout << "T5C::operator T5B() const" << endl; return T5B{}; }
};

void test_5() {
	cout << "\nCase 5\n------\n";
	T5C c;
	T5A a = c;
	T5B b = c;

	// g++: error: too many initializers for ‘T5A’
	// clang: error: excess elements in struct initializer 
	// T5A a2{c};
}

//invocation of a conversion function for initialization of an object of a nonclass type from an expression
// of class type 

struct T6{ operator int() const { return 5; } operator char const *() const { return "leleksenelek"; } };

void test_6() {
	cout << "\nCase 6\n------\n";

	T6 t;
	int x = t;
	cout << "x : " << x;
	const char *c {t};
	cout << " c: " << c << endl;
}

// invocation of a conversion function for conversion to a glvalue or class prvalue to which a reference (8.5.3) will be directly bound (13.3.1.6).

void test_7() {
	cout << "\nCase 7\n------\n";
	// TODO
}


int main() {
	cout << (C(4) == C(5)) << endl;

	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
}

