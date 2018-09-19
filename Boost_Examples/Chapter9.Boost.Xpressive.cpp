#include "pch.h"
#include <string>
#include <iostream>
// Boost.Xpressive makes it possible to write down regular expression as C++ code rather than strings

// Example 9.1. Comparing strings with boost::xpressive::regex_match 
#include <boost/xpressive/xpressive.hpp>

// Example 9.2. boost::xpressive::cregex with strings of type const char*

// Example 9.3. A regular expression with C++ code 

// Example 9.4. Linking actions to expressions.
#include <boost/xpressive/regex_actions.hpp>
#include <iterator>

using namespace boost::xpressive;

#ifdef CHYI 
int main(int argc, char* argv[]) 
{
	// Example 9.1. Comparing strings with boost::xpressive::regex_match 
	std::string s1 = "Boost Libraries";
	// there is a fundamental difference between Boost.Xpressive and Boost.Regex.The type of the regular expression in Boost.Xpressive depends on the type of the string being search
	boost::xpressive::sregex expr1 = boost::xpressive::sregex::compile("\\w+\\s\\w+");
	std::cout << std::boolalpha << boost::xpressive::regex_match(s1, expr1) << '\n';

	// Example 9.2. boost::xpressive::cregex with strings of type const char*
	const char *c2 = "Boost Libraries";
	// You must call the static member function compile() for regular expressions written as strings
	boost::xpressive::cregex expr2 = boost::xpressive::cregex::compile("\\w+\\s\\w+");
	std::cout << std::boolalpha << boost::xpressive::regex_match(c2, expr2) << '\n';

	// Example 9.3. A regular expression with C++ code 
	std::string s3 = "Boost Libraries";
	// _w is similar to "\w", _s is similar to '\s', +_w express at least one alphanumeric; "\w?" become !_w 
	boost::xpressive::sregex expr3 = +_w >> _s >> +_w;
	std::cout << std::boolalpha << boost::xpressive::regex_match(s3, expr3) << '\n';

	// Example 9.4. Linking actions to expressions.
	std::string s4 = "Boost Libraries";
	std::ostream_iterator<std::string> it4{ std::cout, "\n" };
	sregex expr4 = (+_w)[*boost::xpressive::ref(it4) = _] >> _s >> +_w;
	std::cout << std::boolalpha << regex_match(s4, expr4) << '\n';

	return 0;
}
#endif 