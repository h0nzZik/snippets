enum E{
	Val=1
};

namespace N {
	enum E{
		Val=2
	};
	void foo() {
		enum E{
			Val=3
		};
	}
}

void bar() {
	enum E{
		Val=4
	};
}

auto goo() {
	enum E{
		Val=5
	};
	E e = E::Val;
	return e;
}

