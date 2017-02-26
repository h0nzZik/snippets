struct X {
	enum direction { left='l', right='r' };
	int f(int i) { return i==left ? 0 : i==right ? 1 : 2; }
};

int main()
{
	X x;
	X::direction d1 = X::left;
	X::direction d2 = x.right;
}
