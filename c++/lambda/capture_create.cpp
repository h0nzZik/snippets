#include <cassert>
#include <utility>
#include <iostream>
#include <memory>

using namespace std;

int main() {
	unique_ptr<int> p = make_unique<int>(5);
	auto l = [f = move(p)]{
		cout << *f << endl;
	};
	assert(!p);
	l();
}
