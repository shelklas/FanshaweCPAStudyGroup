#define BOOST_TEST_MODULE tuple

#if 0
*
*		STD::TUPLE -----------------------------------------------------------------
*
*		Class template std::tuple is a fixed - size collection of heterogeneous 
*		values.It is a generalization of std::pair.
*
*		DEFINITION: ----------------------------------------------------------------
*
*		template< class... Types >
*		class tuple;
*
*
*		Types...	  -	the types of the elements that the tuple stores. Empty list 
*						is supported.
*
*		CONSTRUCTORS: --------------------------------------------------------------
*
*		1.	Default constructor. Value-initializes all elements.
*			(!) this is a defualt constructor
*
*			constexpr tuple();
*
*		2.	Direct constructor. Initializes each element of the tuple with the 
*			corresponding parameter.
*
*			explicit tuple(const Types&... args);
*
*		3.	Converting constructor. Initializes each element of the tuple with the 
*			corresponding value in std::forward<Utypes>(args).
*
*			template< class... UTypes >
*			explicit tuple(UTypes&&... args);
*
*		4.	Converting copy-constructor. For all i in sizeof...(UTypes), 
*			initializes ith element of the tuple with std::get<i>(other)
*
*			template< class... UTypes >
*			tuple(const tuple<UTypes...>& other);
*
*		5.	Converting move-constructor. For all i in sizeof...(UTypes), 
*			initializes ith element of the tuple with 
*			std::forward<Ui>(std::get<i>(other)).
*
*			template <class... UTypes>
*			tuple(tuple<UTypes...>&& other);
*
*		6.	Pair copy constructor.Constructs a 2 - element tuple with the first 
*			element constructed from p.first and the second element from p.second
*
*			template< class U1, class U2 >
*			tuple(const pair<U1, U2>& p);
*
*		7.	Pair move constructor.Constructs a 2 - element tuple with the first 
*			element constructed from std::forward<U1>(p.first) and the second 
*			element from std::forward<U2>(p.second)
*
*			template< class U1, class U2 >
*			tuple(pair<U1, U2>&& p);
*
*		8.	Implicitly-defined copy constructor. Initializes each element of 
*			the tuple with the corresponding element of other.
*
*			tuple(const tuple& other) = default;
*
*		9.	Implicitly - defined move constructor.Initializes each ith element 
*			of the tuple with std::forward<Ui>(std::get<i>(other)).
*
*			tuple(tuple&& other) = default;
*
*		(other constructors go into Alloc and we are not going there)
*
*		MEMBER FUNCTIONS: ----------------------------------------------------------
*
*		operator=			Replaces the contents of the tuple with the contents of 
*							another tuple or a pair.
*
*			tuple& operator=(const tuple& other);		copy-assignment
*			tuple& operator=(tuple&& other) noexcept();	move-assignment
*
*			template< class... UTypes >
*			tuple& operator=(const tuple<UTypes...>& other);
*			-	For all i, assigns std::get<i>(other) to std::get<i>(*this)
*
*			template< class... UTypes >
*			tuple& operator=(tuple<UTypes...>&& other);
*			-	For all i, assigns std::forward<Ui>(std::get<i>(other)) 
*				to std::get<i>(*this)
*
*			template< class U1, class U2 >
*			tuple& operator=(const pair<U1, U2>& p);
*			-	Assigns p.first to the first element of *this and p.second to the 
*				second element of *this
*
*			template< class U1, class U2 >
*			tuple& operator=(pair<U1, U2>&& p);
*			-	Assigns std::forward<U1>(p.first) to the first element of *this 
*				and std::forward<U2>(p.second) to the second element of *this
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		swap				Calls swap(which might be std::swap) for each element 
*							in *this and its corresponding element in other.
*
*			void swap(tuple& other) noexcept();
*
*		NON-MEMBER FUNCTIONS: ------------------------------------------------------
*
*		make_tuple			Creates a tuple object, deducing the target type from 
*							the types of arguments.
*
*			template< class... Types >
*			tuple<VTypes...> make_tuple(Types&&... args);
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		tie					Creates a tuple of lvalue references to its arguments
*
*			template< class... Types >
*			tuple<Types&...> tie(Types&... args) noexcept;
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		tuple_cat			Constructs a tuple that is a concatenation of all 
*							tuples in args.
*
*			template< class... Tuples >
*			std::tuple<CTypes...> tuple_cat(Tuples&&... args);
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		get					Extracts the Ith element from the tuple. I is an 
*							integer value in [0, sizeof...(Types)).
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		operator==, != , <, <= , >, >=
*
*		Compares lhs and rhs lexicographically, that is, compares the first 
*		elements, if they are equivalent, compares the second elements, if those 
*		are equivalent, compares the third elements, and so on.
*
*		lhs, rhs - tuples to compare
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		std::swap			Specializes the std::swap algorithm
*
*		HELPER CLASSES: ------------------------------------------------------------
*
*		tuple_size<std::tuple>		Provides access to the number of elements in a 
*									tuple as a compile-time constant expression.
*
*			operator std::size_t  -	onverts the object to std::size_t, returns 
*									value
*
*			template< class T >
*			class tuple_size;	  -	definition
*
*		- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*		tuple_element<std::tuple>	Provides compile-time indexed access to the 
*									types of the elements of the tuple.
*
*			type								  -	the type of Ith element of the 
*													tuple, where 
*													I is in[0, sizeof...(Types))
*
*			template< std::size_t I, class T >
*			class tuple_element;				  -	difinition
*
#endif


#include <boost\test\unit_test.hpp>
#include <tuple>
#include <vector>
#include <string>


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
BOOST_AUTO_TEST_CASE(constuctors) {

	{
		std::tuple<int, long, double> tuple_default;
	}

	{
		std::tuple<foo, int, std::vector<double>, bar> tuple_direct_init{ 1, 0, {1.0, -0.5, 3}, {3, 4} };
		std::tuple<size_t, size_t, size_t> tuple_direct_init_2 = { 1, 1, 1 };
	}

	{
		//init values i, d, f
		int i = 123456;
		double d = 42.99999999;
		foo f(987654);
		std::tuple<int, double, foo> tuple(std::move(i), std::move(d), std::move(f));
	}

	{
		std::tuple<long, short, double> tuple_direct_init(-1234, 543, 4.5);
		std::tuple<long long, float, double> tuple_converting_copy(tuple_direct_init);

		std::tuple<foo, int, double> tuple_converting_move(std::move(tuple_direct_init));
	}

	{
		std::pair<foo, bar> pair(123456, { 7654, -7654 });
		std::tuple<foo, bar> tuple_from_pair_copy(pair);
		std::tuple<foo, bar> tuple_from_pair_move(std::move(pair));
	}

	{
		std::tuple<int, double, foo> tuple_direct_init(1234, 543.9876543, foo(4545545));
		std::tuple<int, double, foo> tuple_copy(tuple_direct_init);
		std::tuple<int, double, foo> tuple_move(std::move(tuple_direct_init));
	}
}

/* MEMBER FUNCTIONS EXAMPLES */
BOOST_AUTO_TEST_CASE(member_functions) {

	{
		std::tuple<int, double, foo> tuple_copy_assignment;
		std::tuple<int, double, foo> tuple_move_assignment;
		std::tuple<int, double, foo> tuple(12345, 987654.987654, 876543);
		tuple_copy_assignment = tuple;
		tuple_move_assignment = std::move(tuple);
	}

	{
		std::tuple<int, double, foo> tuple_converting_copy_assignment;
		std::tuple<int, double, foo> tuple_converting_move_assignment;
		std::tuple<short, float, foo> tuple(12345, 987654.987654f, 876543);
		tuple_converting_copy_assignment = tuple;
		tuple_converting_move_assignment = std::move(tuple);
	}

	{
		std::tuple<int, foo> tuple_pair_copy_assignment;
		std::tuple<int, int> tuple_pair_move_assignment;
		std::pair<int, int> pair(12345, 876543);
		tuple_pair_copy_assignment = pair;
		tuple_pair_move_assignment = std::move(pair);
	}

	{
		std::tuple<int, double, foo> tuple(123, 123, 123);
		std::tuple<int, double, foo> other(321, 321, 321);
		tuple.swap(other);
	}
}

/* NON-MEMBER FUNCTIONS */
BOOST_AUTO_TEST_CASE(non_member_functions) {

	{
		auto tuple = std::make_tuple(12345ull, foo(743), 3.f, std::vector<bar>{ {0, 0}, {1, 5} });
	}

	{
		int i = 124;
		foo f(421);
		auto tuple = std::tie(i, f);
	}

	{
		std::tuple<char, short, int> low;
		std::tuple<long, long> mid;
		std::tuple<float, double, bool> high;

		auto tuple = std::tuple_cat(low, mid, high);
	}

	{
		std::tuple<int, char, double> tuple;
		auto e = std::get<2>(tuple);
	}

	{
		std::tuple<long, int> tuple1(12, 5432);
		std::tuple<long, int> tuple2(12, 2345);

		bool e = tuple1 == tuple2;
		bool l = tuple1 < tuple2;
		bool g = tuple1 > tuple2;
		bool le = tuple1 <= tuple2;
		bool ge = tuple1 >= tuple2;
		bool ne = tuple1 != tuple2;
	}
}

BOOST_AUTO_TEST_CASE(helper_classes) {

	{
		std::tuple_size<std::tuple<int, long>> ts;
		BOOST_CHECK_EQUAL(2, ts.value);
	}

	{
		bool f = std::is_same<std::tuple_element<1, std::tuple<float, foo>>::type, foo>::value;
		BOOST_CHECK(f);
	}
}
