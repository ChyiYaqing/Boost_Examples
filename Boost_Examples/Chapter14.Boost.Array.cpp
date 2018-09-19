#include "pch.h"
#include <string>
#include <iostream>

// Example 14.1. Various member functions of boost::array
#include <boost/array.hpp>

#ifdef CHYI



int main(int argc, char* argv[])
{
	// Example 14.1. Various member functions of boost::array
	typedef boost::array<std::string, 3> array1;
	array1 a1;

	a1[0] = "cat";
	a1.at(1) = "shark";
	*a1.rbegin() = "spider";

	std::sort(a1.begin(), a1.end());

	for (const std::string &s : a1)
		std::cout << s << '\n';

	std::cout << a1.size() << '\n';
	std::cout << a1.max_size() << '\n';

	return 0;
}
#endif // CHYI