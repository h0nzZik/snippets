// 7.2, par 2: '''The identifiers in an
// enumerator-list are declared as constants,
// and can appear wherever constants are required.'''

const int x = 5;
enum E { y = 6 };

int main()
{
	int const * p_x = &x;
	E const * p_y = &y;
}
