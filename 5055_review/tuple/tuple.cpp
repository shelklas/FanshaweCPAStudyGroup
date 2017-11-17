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
*			template< std::size_t I, class... Types >
*			typename std::tuple_element<I, tuple<Types...> >::type&
*				get(tuple<Types...>& t) noexcept;
*			-	Returns element by reference
*
*			template< std::size_t I, class... Types >
*			typename std::tuple_element<I, tuple<Types...> >::type&&
*				get(tuple<Types...>&& t) noexcept;
*			-	Returns an lvalue
*
*			template< std::size_t I, class... Types >
*			typename std::tuple_element<I, tuple<Types...> >::type const&
*				get(const tuple<Types...>& t) noexcept;
*			-	Returns element by const reference
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

/* CONSTRUCTORS EXAMPLES */
BOOST_AUTO_TEST_CASE(constuctors) {

}