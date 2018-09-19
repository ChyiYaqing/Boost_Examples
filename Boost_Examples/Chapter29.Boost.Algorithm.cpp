#include "pch.h"

// Example 29.1. Testing for exactly one value with boost::algorithm::one_of_equal() 
#include <boost/algorithm/cxx11/one_of.hpp>
#include <array>
#include <iostream>

// Example 29.2. More variants of C++ 11 algorithms 
#include <boost/algorithm/cxx11/iota.hpp> // This function generates sequentially increasing numbers.
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>
#include <vector>

// Example 29.3. C++14 algorithms from Boost.Algorithm
#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>

// Example 29.4. Using boost::algorithm::hex() and boost::algorithm::unhex()
#include <boost/algorithm/hex.hpp>
#include <iterator>

using namespace boost::algorithm;

#ifdef CHYI



int main(int argc, char* argv[])
{
	// Example 29.1. Testing for exactly one value with boost::algorithm::one_of_equal() 
	std::array<int, 6> a1{ {0, 5, 2, 1, 4, 3} };
	auto predicate1 = [](int i) {return i == 4; };
	std::cout.setf(std::ios::boolalpha);
	std::cout << one_of(a1.begin(), a1.end(), predicate1) << '\n'; // tests whether a condition is met exactly once
	std::cout << one_of_equal(a1.begin(), a1.end(), 4) << '\n';

	// Example 29.2. More variants of C++ 11 algorithms 
	std::vector<int> v2;
	iota_n(std::back_inserter(v2), 10, 5);
	std::cout.setf(std::ios::boolalpha);
	std::cout << is_increasing(v2) << '\n'; // checks that values are in increasing order.
	std::ostream_iterator<int> out{ std::cout, "," };
	copy_until(v2, out, [](int i) {return i > 12; });

	// Example 29.3. C++14 algorithms from Boost.Algorithm
	std::vector<int> v3{ 1,2 };
	std::vector<int> w3{ 1,2,3 };
	std::cout.setf(std::ios::boolalpha);
	std::cout << boost::algorithm::equal(v3.begin(), v3.end(), w3.begin(), w3.end()) << '\n'; // returns a bool
	auto pair3 = boost::algorithm::mismatch(v3.begin(), v3.end(), w3.begin(), w3.end()); // std::pair.first and second refere to the elements in the first and second sequence 
	if (pair3.first != v3.end())
		std::cout << *pair3.first << '\n';
	if (pair3.second != w3.end())
		std::cout << *pair3.second << '\n';

	// Example 29.4. Using boost::algorithm::hex() and boost::algorithm::unhex()
	std::vector<char> v4{ 'C', '+' , '+' };
	hex(v4, std::ostream_iterator<char>{std::cout, ""}); // convert characters to hexadecimal values
	std::cout << '\n';

	std::string s4 = "C++";
	std::cout << hex(s4) << '\n';

	std::vector<char> w4{ '4', '3', '2', 'b' ,'2', 'b' };
	unhex(w4, std::ostream_iterator<char>{std::cout, ""}); // hexadecimal values to characters
	std::cout << '\n';

	std::string t4 = "432b2b";
	std::cout << unhex(t4) << '\n';

	return 0;
}
#endif // CHYI