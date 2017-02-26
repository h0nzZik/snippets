constexpr int x = 5;
int const & r1 = x;
int const * p1 = &x;

enum E {
	A
};

int const & r2 = E::A;
// error: cannot take the address of an rvalue of type 'E'
// int const * p2 = &E::A;

int const & r3 = (x);
int const * p3 = &(x);

int const & r4 = (6);
int const * p4 = &(6);


