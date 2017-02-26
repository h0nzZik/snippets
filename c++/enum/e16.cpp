// error: enumerator value evaluates to 128, which cannot be narrowed to type 'signed char'
enum E : signed char {
	V = 128
};
