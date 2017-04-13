/**
 * Demonstrates that operator* can be overloaded as a non-member function.
 */

struct C {};

int operator*(C const &) { return 5; }


