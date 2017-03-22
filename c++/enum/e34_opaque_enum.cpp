#include <iostream>
using namespace std;

enum E : int;

int main()
{
	E e = (E)5;
	cout << "e: " << (int)e << endl;
}
