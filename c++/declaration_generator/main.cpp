#include <memory> // unique_ptr
#include <utility> // move
#include <iostream>
#include <string>


enum class Precedence {
	Primitive,
	Pointer,
	Array
};

class Type {
	public:
		Type() = default;
		virtual ~Type() = default;
		virtual void print(std::ostream & o) const = 0;
		virtual void print_pre(std::ostream & o) const = 0;
		virtual void print_post(std::ostream & o) const = 0;
		virtual Precedence precedence() const = 0;
};

class PrimitiveType : public Type {
	public:
		PrimitiveType() = default;
		~PrimitiveType() = default;

		void print(std::ostream & o) const override {
			o << " int ";
		}

		virtual void print_pre(std::ostream & o) const override {
			o << " int ";
		}

		virtual void print_post(std::ostream & /*o*/) const override {
			;
		}

		Precedence precedence() const override {
			return Precedence::Primitive;
		}
};

class PointerType : public Type {
	public:
		explicit PointerType(std::unique_ptr<Type> nested_type) :
			nested_type(std::move(nested_type)) {
				;
			}


		void print(std::ostream & o) const override {
			print_pre(o);
		}

		virtual void print_pre(std::ostream & o) const override {
			nested_type->print_pre(o);
			bool const p = precedence() < nested_type->precedence();
			if (p)
				o << "(";
			o << "*";
		}

		virtual void print_post(std::ostream & o) const override {
			bool const p = precedence() < nested_type->precedence();
			if (p)
				o << ")";
			nested_type->print_post(o);
		}

		Precedence precedence() const override {
			return Precedence::Pointer;
		}

	private:
		std::unique_ptr<Type> nested_type;
};

class ArrayType : public Type {
	public:
		explicit ArrayType(std::unique_ptr<Type> nested_type) :
			nested_type(std::move(nested_type)) {
				;
			}


		void print(std::ostream & o) const override {
			print_pre(o);
			print_post(o);
		}

		virtual void print_pre(std::ostream & o) const override {
			nested_type->print_pre(o);
		}

		virtual void print_post(std::ostream & o) const override {
			o << "[3]";
			nested_type->print_post(o);
		}


		Precedence precedence() const override {
			return Precedence::Array;
		}

	private:
		std::unique_ptr<Type> nested_type;
};

struct SimpleDeclaration {
	std::string name;
	std::unique_ptr<Type> type;
	void print(std::ostream & o) {
		type->print_pre(o);
		o << name;
		type->print_post(o);
		o << ";";
	}
};

void test_pointer_to_int() {
	std::cout << "Pointer to int: ";
	SimpleDeclaration decl {
		"a",
		std::make_unique<PointerType>(
			std::make_unique<PrimitiveType>()
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_pointer_to_pointer_to_int() {
	std::cout << "Pointer to pointer to int: ";
	SimpleDeclaration decl {
		"b",
		std::make_unique<PointerType>(
			std::make_unique<PointerType>(
				std::make_unique<PrimitiveType>()
			)
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_array_of_ints() {
	std::cout << "Array of ints: ";
	SimpleDeclaration decl {
		"c",
		std::make_unique<ArrayType>(
			std::make_unique<PrimitiveType>()
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_array_of_pointers_to_int() {
	std::cout << "Array of pointers to int: ";
	SimpleDeclaration decl {
		"d",
		std::make_unique<ArrayType>(
			std::make_unique<PointerType>(
				std::make_unique<PrimitiveType>()
			)
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_pointer_to_array_of_ints() {
	std::cout << "Pointer to array of ints: ";
	SimpleDeclaration decl {
		"e",
		std::make_unique<PointerType>(
			std::make_unique<ArrayType>(
				std::make_unique<PrimitiveType>()
			)
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_pointer_to_array_of_pointers_to_int() {
	std::cout << "Pointer to array of pointers to int: ";
	SimpleDeclaration decl {
		"f",
		std::make_unique<PointerType>(
			std::make_unique<ArrayType>(
				std::make_unique<PointerType>(
					std::make_unique<PrimitiveType>()
				)
			)
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}

void test_array_of_pointers_to_array_of_ints() {
	std::cout << "Array of pointers to array of ints: ";
	SimpleDeclaration decl {
		"g",
		std::make_unique<ArrayType>(
			std::make_unique<PointerType>(
				std::make_unique<ArrayType>(
					std::make_unique<PrimitiveType>()
				)
			)
		)
	};
	decl.print(std::cout);
	std::cout << std::endl;
}


int main() {
	test_pointer_to_int();
	test_pointer_to_pointer_to_int();
	test_array_of_ints();
	test_array_of_pointers_to_int();
	test_pointer_to_array_of_ints();
	test_pointer_to_array_of_pointers_to_int();
	test_array_of_pointers_to_array_of_ints();
}

// int * a;
// int * b[3];
// int (*c)[3];
