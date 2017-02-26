// When the type starts to exist?

// < Works >
struct C1 {
	using T = int;
};

enum E1 : C1::T {

};

// </Works>
// < DoesNotWork>
template < typename >
struct C2 {
	using T = int;
};


// error: use of undeclared identifier 'E'
enum E2 : C2<E>::T {

};

// </DoesNotWork>
