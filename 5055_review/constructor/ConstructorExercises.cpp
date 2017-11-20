// Kevin McLay
// C++ Primer - 5th Edition
// Ch. 7.1.4, 7.5 - Constructors
// Review & Textbook Exercises

#include <string>
#include <iostream>

// 7.1.4 Constructors

// job of constructor - initialize data members of class object 
// run whenever object of class type is created
// contain same name as class - no return type
// can have possiblty empty parameter list and possibly empty function body
// class can have multiple constructors
// must differ from each other in number or types of their parameters

// may not be declared as const
// when creating const object of class type - does not assume const until after it is initialized
// constructors can write to const objects during their construction

// default constructor - takes zero arguments - used by class for default initialization
// if class doesn't explicitly define any constructors - compiler implicitly defines default constructor
// compiler-generated constructor: synthesized default constructor
//		initializes as follows:		if in class initializer - uses to initialize member
//									otherwise - default initialize member

// Some Classes Cannot Rely on Synthesized Default Constructor
// 1) compiler generates default constructor ONLY if we do not define any other constructors for the class
//		-- basis for this rule: if class requires control to initialize object in one case - likely to require control in all cases
// 2) for some classes - synthesized default constructor does wrong thing 
//		-- basis for this rule: objects of built-in or compound type (ex. arrays & pointers) 
//			have undefined value when default initialized 
//		- should rely on synthesized default constructor ONLY if all such members have in-class initializers
//			otherwise users could create objects with members that have undefined value
// 3) compiler unable to synthesize one 
//		-- basis for this rule: if class has member that has a class type, and that class doesn't have default constructor,
//			compiler can't initialize that member - must define our own version of default consturctor




class Sales_data {

private:
	// data members
	std::string bookNo;
	unsigned units_sold;
	double revenue;

public:
	// legal but sloppy - 3-arg constructor: no initializers
	Sales_data::Sales_data(const std::string &s, unsigned count, double price) {
		bookNo = s;
		units_sold = count;
		revenue = count * price;
	}

	// defines default constructor as well as one that takes string arg
	Sales_data(std::string s = "") : bookNo(s) {}

	std::istream &read(std::istream &is, Sales_data &item) {

		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		return is;
	}

	// remaining constructors unchanged
	Sales_data(std::string s, unsigned count, double rev) : bookNo(s), units_sold(count), revenue(rev*count) {}
	// reminaing members as before

	
	// EX. 7.38
	Sales_data(std::istream &is = std::cin) { read(is, *this); }
	// uses cin as default arg

	// EX. 7.39
	// believe so - it compiles?

	// EX. 7.40
	// Employee
	// data: Full name, Number, Address, Pay, Department...
	// constructors:
	// 

};


class ConstRef {

private:
	int i;
	int const ci;
	int & ri;

public: 
	//ConstRef(int ii);

	// error: ci and ri must be initialized
	//ConstRef::ConstRef(int ii) {
	//	// assignments
	//	i = ii;		// ok
	//	ci = ii;	// error: cannot assign to a const
	//	ri = i;		// error: ri was never initialized
	//}

	// CORRECT WAY
	ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {}

};


class X {
	
private:
	int i;
	int j;

public:
	//X(int val) : j(val), i(j) {}	// undefined: i is initialized before j
	X(int val) : i(val), j(val) {}	// order doesn't matter
};


struct XX {

	int rem;
	int base;

	XX(int i, int j) : base(i), rem(base % j) {}

	// EX - 7.36
	// initializer is in error - rem variable def before base, order of initialization doesn't matter
	// rem uses uninitialized base variable
};

// EX. 7.37
Sales_data first_item(std::cin);	// uses istream constructor - read *this

int main() {

	// typically initialize variables immediately when defining, rather than assigning later on
	std::string foo = "Hello World!";	// define and initialize
	std::string bar;					// default initialized to empty string
	bar = "Hello World!";				// assign new value to bar


	// MEMBERS THAT ARE CONST OR REFERENCES MUST BE INITIALIZED
	// & members that are of class type that do not define default constructor must also be initialized
	
	// constructor initializer list - specifies only values to initialize members, not the order in which they are performed
	// members are initialized in order where they appear in class def
	// order of initializeation often doesn't matter - unless one member is initialized in terms of another

	// good idea - write constructor initializers in same order as members are declared
	// also - avoid using members to initialize other members where possible

	// write member initializers to use constructors parameters rather than another data member from same object

	//Sales_data next;						// uses 1-arg string const - default constructor as well
	Sales_data last("9-999-99999-9");		// 1-arg string constructor
	
}