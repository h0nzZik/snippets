// Unary operators

auto x = sizeof true;

// What does 5.3/3 mean?
//
// Note: a pointer to member formed from a mutable non-static data member (7.1.1) does
// not reflect the mutable specifier associated with the non-static data member
class C {
	private:
		mutable int x = 0;
	public:
		int * get_x() const { return &x; }
};

