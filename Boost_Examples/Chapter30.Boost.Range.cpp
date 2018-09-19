#include "pch.h"

// Example 30.1. Counting with boost::count() 
#include <boost/range/algorithm.hpp>
#include <array>
#include <iostream>

// Example 30.2. Range algorithms related to algorithms from the standard library
#include <boost/range/numeric.hpp>
#include <iterator>

// Example 30.3. Range algorithms without counterparts in the standard library
#include <boost/range/algorithm_ext.hpp>
#include <deque>

// Example 30.4.Filtering a range with boost::adaptors::filter()
#include <boost/range/adaptors.hpp>

// Example 30.5. Using keys(), values() and indirect()
#include <map>
#include <utility>

// Example 30.6. boost::adaptors::tokenize() - an adaptor for strings
#include <boost/regex.h>
#include <string>

#ifdef CHYI




int main(int argc, char* argv[])
{
	// Example 30.1. Counting with boost::count() 
	std::array<int, 6> a1{ {0, 1, 0, 1, 0, 1} };
	// All algorithms from Boost.Range require the first parameter to be a range
	std::cout << boost::count(a1, 0) << '\n';

	// Example 30.2. Range algorithms related to algorithms from the standard library
	std::array<int, 6> a2{ {0, 1, 2, 3, 4, 5} };
	boost::random_shuffle(a2); // changing the order of elements in a range randomly
	boost::copy(a2, std::ostream_iterator<int>{std::cout, ","});
	std::cout << '\n' << *boost::max_element(a2) << '\n';
	std::cout << boost::accumulate(a2, 0) << '\n';

	// Example 30.3. Range algorithms without counterparts in the standard library
	std::array<int, 6> a3{ {0,1,2,3,4,5} };
	std::cout << std::boolalpha << boost::is_sorted(a3) << '\n'; // tests whether elements in a range are sorted
	std::deque<int> d3;
	boost::push_back(d3, a3);
	boost::remove_erase(d3, 2);
	boost::copy_n(d3, 3, std::ostream_iterator<int>{std::cout, ","});

	std::cout << '\n';
	// Example 30.4.Filtering a range with boost::adaptors::filter()
	std::array<int, 6> a4{ {0, 5, 2, 1, 3, 4} };
	boost::copy(boost::adaptors::filter(a4, [](int i) {return i > 2; }), // boost::adaptors::filter() does not change the range a, it returns a new range
		std::ostream_iterator<int>{std::cout, ","});

	// Example 30.5. Using keys(), values() and indirect()
	std::cout << '\n';
	std::array<int, 3> a5{ {0, 1, 2} };
	std::map<std::string, int*> m5;
	m5.insert(std::make_pair("a", &a5[0]));
	m5.insert(std::make_pair("b", &a5[1]));
	m5.insert(std::make_pair("c", &a5[2]));

	boost::copy(boost::adaptors::keys(m5),
		std::ostream_iterator<std::string>{std::cout, ","});
	// This adaptor can always be used when a range consists of pointers, but an iteration should return the values the pointers refer to.
	boost::copy(boost::adaptors::indirect(boost::adaptors::values(m5)),
		std::ostream_iterator<int>{std::cout, ","});

	// Example 30.6. boost::adaptors::tokenize() - an adaptor for strings
	std::string s6 = "The Boost C++ Libraries";
	boost::regex expr6{ "[\\w+]+" };
	boost::copy(boost::adaptors::tokenize(s6, expr6, 0, boost::regex_constants::match_default),
		std::ostream_iterator<std::string>{std::cout, ","});

	return 0;
}

#endif // CHYI