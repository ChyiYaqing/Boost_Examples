#include "pch.h"
#include <iostream>
// Boost.Format offers a replacement for the function std::printf() allows formatted data output
// Boost.Format provides a type-safe and extensible alternative 

// Example 7.1. Formatted output with boost::format 
#include <boost/format.hpp>

// Example 7.2. Numbered placeholder with boost::format 

// Exmaple 7.3. Using manipulators with boost::io::group 

int main(int argc, char* argv[])
{
	// Example 7.1. Formatted output with boost::format 
	// The Boost.Format format string uses numbers placed between two percent signs as placeholders for the actual data
	std::cout << boost::format{ "%1%.%2%.%3%" } % 9 % 18 % 2018 << '\n';

	// Example 7.2. Numbered placeholder with boost::format 
	std::cout << boost::format{ "%2%/%1%/%3%" } % 18 % 9 % 2018 << '\n';

	return 0;
}