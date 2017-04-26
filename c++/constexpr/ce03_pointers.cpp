#include <iostream>

using namespace std;

/*constexpr*/ int x = 7;
// error: cannot initialize a variable of type 'int *const'
// with an rvalue of type 'const int *'
//constexpr int * p1_x = &x;
constexpr int const * p2_x = &x;

int main() {
	constexpr int y = 8;

	// error: cannot initialize a variable of type 'int *const'
	// with an rvalue of type 'const int *'
	// constexpr int * p1_y = &x;
	
	// constexpr variable 'p2_y' must be initialized by a constant
    // expression
	// constexpr const int * p2_y = &y;
	

	static constexpr int z = 9;
	// error: cannot initialize a variable of type 'int *const'
	// with an rvalue of type 'const int *'
	// constexpr int * p1_z = &z;
	constexpr int const * p2_z = &z;
}

