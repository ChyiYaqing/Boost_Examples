#include "pch.h"
#include <iostream>

// Example 6.1. Using boost::lexical_cast 
#include <boost/lexical_cast.hpp>	// cast operator 

// Example 6.2. boost::bad_lexical_cast in case of an error 

#ifdef CHYI



int main(int argc, char* argv[])
{
	// Example 6.1. Using boost::lexical_cast 
	// boost::lexical_cast uses streams internally to perform the conversion.
	std::string s1 = boost::lexical_cast<std::string>(123);		// The cast operator boost::lexical_cast can convert numbers of different types
	std::cout << s1 << '\n';
	double d1 = boost::lexical_cast<double>(s1); 
	std::cout << d1 << '\n';

	// Example 6.2. boost::bad_lexical_cast in case of an error 
	try {
		int i = boost::lexical_cast<int>("abc");
		std::cout << i << '\n';
	}
	catch (const boost::bad_lexical_cast &e)
	{
		std::cerr << e.what() << '\n';
	}

	
	return 0;
}
#endif // CHYI