#include <iostream>
#include <type_traits>
using namespace std;


template < typename T > struct S{};

using SInt = S<int>;

template < typename T >
using U = S<T>;

template <template <typename...> class, template<typename...> class> 
struct is_same_template : std::false_type{};

template <template <typename...> class T>
struct is_same_template<T,T> : std::true_type{};
string tf(bool b) {
	return b? "true" : "false";
}

int main() {
	cout << "SInt == S<int>: " << tf(is_same<SInt, S<int>>::value) << endl;
	cout << "U<int> == S<int>: " << tf(is_same<U<int>, S<int>>::value) << endl;
	cout << "U == S: " << tf(is_same_template<U, S>::value) << endl;
}

