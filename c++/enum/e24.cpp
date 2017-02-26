// What happens on overflow?

enum E : unsigned short {};

int main()
{
	int x = (unsigned short)65536;
	E y = (E)65536;
}
