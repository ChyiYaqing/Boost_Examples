//#include "pch.h"
#include <iostream>
// Boost.Format offers a replacement for the function std::printf() allows formatted data output
// Boost.Format provides a type-safe and extensible alternative 

// Example 7.1. Formatted output with boost::format 
#include <boost/format.hpp>

// Example 7.2. Numbered placeholder with boost::format 

// Exmaple 7.3. Using manipulators with boost::io::group 

// Example 7.4. Placehodlers with special characters 

// Example 7.5. boost::io::format_error in case of an error 

// Example 7.6. Placeholder without numbers 

// Example 7.7. boost::format with the syntax used from std::printf() 

// Example 7.8. boost::format with seemingly invalid placeholders 

// Example 7.9. boost::format with user-defined type 

struct animal{
	std::string name;
	int legs;
};
// stream operator is overloaded 
std::ostream &operator<<(std::ostream &os, const animal &a){
	return os << a.name << ',' << a.legs;
}

int main(int argc, char* argv[])
{
	// Example 7.1. Formatted output with boost::format 
	// The Boost.Format format string uses numbers placed between two percent signs as placeholders for the actual data
	std::cout << boost::format{ "%1%.%2%.%3%" } % 9 % 18 % 2018 << '\n';

	// Example 7.2. Numbered placeholder with boost::format 
	std::cout << boost::format{ "%2%/%1%/%3%" } % 18 % 9 % 2018 << '\n';

	// Exmaple 7.3. Using manipulators with boost::io::group 
	std::cout << boost::format{"%1% %2% %1%"} % boost::io::group(std::showpos, 1) % 2 << '\n';
	
	// Example 7.4. Placehodlers with special characters 
	std::cout << boost::format{"%|1$+| %2% %1%"} % 1 % 2 << '\n';

	// Example 7.5. boost::io::format_error in case of an error 
	try{
		std::cout << boost::format{"%|+| %2% %1%"} %1 %2 << '\n';
	} 
	catch (boost::io::format_error &ex)
	{
		std::cout << ex.what() << '\n';
	}
	
	// Example 7.6. Placeholder without numbers 
	std::cout << boost::format{"%|+| %|| %||"} % 1 % 2 % 1 << '\n';
	
	// Example 7.7. boost::format with the syntax used from std::printf() 
	std::cout << boost::format{"%+d %d %d"} % 1 % 2 % 1 << '\n'; // The letter "d" within the format string does not indicate the output of a number.
	
	// Example 7.8. boost::format with seemingly invalid placeholders 
	std::cout << boost::format{"%+s %s %s"} %1 %2 %1 << '\n';
	
	// Example 7.9. boost::format with user-defined type 
	animal a{"cat", 4};
	std::cout << boost::format{"%1%"} %a << '\n';


	return 0;
}
