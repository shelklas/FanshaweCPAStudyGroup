#define BOOST_TEST_MODULE stl_stack

#if 0
 *
 *		STD::STACK -----------------------------------------------------------------
 *
 *		The std::stack class is a container adapter that gives the programmer 
 *		the functionality of a stack - specifically, a FILO (first-in, last-out) 
 *		data structure.
 *
 *		The class template acts as a wrapper to the underlying container - only 
 *		a specific set of functions is provided. The stack pushes and pops the
 *		element from the back of the underlying container, known as 
 *		the top of the stack.
 *
 *		DEFINITION: ----------------------------------------------------------------
 *		
 *		template<class T, class Container = std::deque<T>> 
 *		class stack;
 *		
 *		T			- type of stored elements
 *		Container	- underlying container (deque of type T by default)
 *		
 *		!!! T has to match type of underlying continer
 *
 *		MEMBER TYPES: --------------------------------------------------------------
 *
 *		container_type		= Container
 *		value_type			= Container::value_type (!!!)
 *		size_type			= Container::size_type
 *		reference			= Container::reference
 *		const_reference		= Container::const_reference
 *
 *		CONSTRUCTORS: --------------------------------------------------------------
 *
 *		1.	Copy-constructs the underlying container c with the contents of cont.
 *			(!) this is a defualt constructor
 *
 *			explicit stack( const Container& cont = Container() );
 *			explicit stack( const Container& cont );
 *
 *		2.	Move-constructs the underlying container c with std::move(cont)
 *			(!) this is a defualt constructor
 *			
 *			explicit stack( Container&& cont = Container() );
 *		
 *		3.	Copy constructor. The adaptor is copy-constructed with the contents of 
 *			other.c
 *
 *			stack( const stack& other );
 *
 *		4.	Move constructor. The adaptor is constructed with std::move(other.c)
 *
 *			stack( stack&& other );
 *
 *		(other constructors goes into Alloc and we are not going there)
 *
 *		DESTRUCTOR: ----------------------------------------------------------------
 *
 *		Destructs the container adaptor. The destructors of the elements are called
 *		and the used storage is deallocated. 
 *		Note, that if the elements are pointers, the pointed-to objects are not 
 *		destroyed.
 *
 *		~stack()
 *
 *		MEMBER FUNCTIONS: ----------------------------------------------------------
 *
 *		operator=			Replaces the contents of the container adaptor with 
 *							those of other.
 *
 *			stack& operator=( const stack& other );		copy-assignment
 *			stack& operator=( stack&& other );			move-assignment
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 *		top					Returns reference to the top element in the stack. 
 *							This is the most recently pushed element. This element 
 *							will be removed on a call to pop().
 *
 *			reference top();
 *			const_reference top() const;
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		empty				Checks if the underlying container has no elements.
 *
 *			bool empty() const;
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		size				Returns the number of elements in the underlying 
 *							container
 *
 *			size_type size() const;
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		push				Pushes the given element value to the top of the stack.
 *
 *			void push(const value_type& value);	
 *			void push(value_type&& value);
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		pop					Removes the top element from the stack.
 *
 *			void pop();
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		emplace				Pushes a new element on top of the stack.The element is 
 *							constructed in - place, i.e.no copy or move operations 
 *							are performed.The constructor of the element is called 
 *							with exactly the same arguments as supplied to the 
 *							function.
 *
 *			template< class... Args >
 *			void emplace(Args&&... args);
 *
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		swap				Exchanges the contents of the container adaptor with 
 *							those of other.
 *
 *			void swap(stack& other) noexcept();
 *
 *		MEMEBER OBJECTS: -----------------------------------------------------------
 *
 *		Container c			the underlying container (protected member object)
 *
 *		NON-MEMBER FUNCTIONS: ------------------------------------------------------
 *
 *		operator==, != , <, <= , >, >=
 *
 *		Compares the contents of the underlying containers of two container 
 *		adaptors.The comparison is done by applying the corresponding operator 
 *		to the underlying containers.
 *
 *		lhs, rhs - container adaptors whose contents to compare
 *	
 *		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
 *		std::swap			Specializes the std::swap algorithm for std::stack. 
 *							Swaps the contents of lhs and rhs.
 *
 *
#endif

#include <boost\test\unit_test.hpp>
#include <deque>
#include <stack>
#include <vector>

struct foo {
	int attr_;

	foo(int a = 0) : attr_(a) {};
};

 struct bar
 {
	int attr1_, attr2_;

	bar(std::pair<int, int> p = { 0, 0 }) : attr1_(p.first), attr2_(p.second) {};
	bar(int a1, int a2) : attr1_(a1), attr2_(a2) {};
 };

/* CONSTRUCTORS EXAMPLES */
BOOST_AUTO_TEST_CASE(constructors) {

	{
		std::stack<int> stack_default;
	}

	{
		std::deque<int> deque_from_init_list{ 1, 3, 10, 654, -56789 };
		std::stack<int> stack_from_deque_copy(deque_from_init_list);
		std::stack<int, std::deque<int>> stack_from_deque_copy_2(deque_from_init_list);

		std::vector<int> vector_from_init_list{ 10, 20, 699, 996, -78 };
		std::stack<int, std::vector<int>> stack_from_vector_copy(vector_from_init_list);
	}

	{
		std::deque<foo> deque_from_init_list{ 123456, 54, -666, 69, 0 };
		std::stack<foo> stack_from_deque_move(std::move(deque_from_init_list));

		std::deque<foo> deque_from_init_list_2{ 123456, 54, -666, 69, 0 };
		std::stack<foo, std::deque<foo>> stack_from_deque_move_2(std::move(deque_from_init_list_2));
	}

	{
		std::vector<bar> vector_from_init_list{ 
			bar(std::make_pair(0, 1)), 
			bar(std::make_pair(-12345, 98765)), 
			bar(std::make_pair(1917, 1991)), 
			bar(std::make_pair(69, 42)) };
		std::stack<bar, std::vector<bar>> stack_from_vector(vector_from_init_list);
		std::stack<bar, std::vector<bar>> stack_from_stack_copy(stack_from_vector);
		std::stack<bar, std::vector<bar>> stack_from_stack_move(std::move(stack_from_vector));
	}
 }

/* MEMBER FUNCTIONS EXAMPLES */
BOOST_AUTO_TEST_CASE(member_functions) {

	{
		std::deque<double> deque_from_init_list{ 2.5, 55.6, -0.99999, 3 };
		std::stack<double> stack_from_deque(deque_from_init_list);

		std::stack<double> stack_default;
		stack_default = stack_from_deque;

		std::stack<double> stack_default_2;
		stack_default_2 = std::move(stack_from_deque);
	}

	{
		std::deque<foo> deque{ 2, 55, -0, 3 };
		std::stack<foo> stack(deque);

		stack.top().attr_ = 1;

		std::stack<foo> const const_stack(deque);
		// can't do this -> const_stack.top().attr_ = 1;
	}

	{
		std::stack<bar> stack;
		stack.empty();

		std::stack<bar> const const_stack;
		const_stack.empty();
	}

	{
		std::stack<unsigned> stack;
		stack.size();

		std::stack<bar> const const_stack;
		const_stack.size();
	}

	{
		std::stack<foo> stack;
		foo push_me(918273645);
		stack.push(push_me);
		stack.push(std::move(push_me));
	}

	{
		std::stack<long> stack;
		stack.push(1234567);

		stack.pop();
	}

	{
		std::stack<bar> stack;
		stack.emplace(13, 18);
	}
	
	{
		std::stack<long long> stack1;
		std::stack<long long> stack2;
		std::swap(stack1, stack2);
		stack1.swap(stack2);
	}
}

/* NON-MEMBER FUNCTIONS */
BOOST_AUTO_TEST_CASE(non_memeber_functions) {

	{
		std::stack<long long> stack1;
		std::stack<long long> stack2;

		bool e = stack1 == stack2;
		bool l = stack1 < stack2;
		bool g = stack1 > stack2;
		bool le = stack1 <= stack2;
		bool ge = stack1 >= stack2;
		bool ne = stack1 != stack2;
	}
}
