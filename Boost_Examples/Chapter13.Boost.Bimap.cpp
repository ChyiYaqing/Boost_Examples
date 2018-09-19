#include "pch.h"
#include <string>
#include <iostream>
// The library Boost.BitMap is based on Boost.MultiIndex and provides a container that can be used immediately without being defined first

// Example 13.1. Using boost::bimap 
#include <boost/bimap.hpp>

// Example 13.2 Accessing relations 

// Example 13.3. Using boost::bimaps::set_of explicitly 

#ifdef CHYI


int main(int argc, char* argv[]) {
	
	// Example 13.1. Using boost::bimap 
	typedef boost::bimap<std::string, int> bimap;
	bimap animals;

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spider", 8 });
	// left uses keys of type std::string to access the container, and right uses keys of type int.
	std::cout << animals.left.count("cat") << '\n';
	std::cout << animals.right.count(8) << '\n';

	return 0;
}

#endif // CHYI