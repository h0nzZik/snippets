#include <iostream>

using namespace std;

struct A {
	int x = 0;
	A() = default;
	A(A const &a) : x{a.x+1} {
		;
	}
	void print() const {
		cout << "x: " << x << endl;
	}
	void doit() {
		print();
		[*this] {
			print();
		}();
		print();
	}
};

int main() {
	A a;
	a.doit();
}

