#include "pch.h"
#include <string>
#include <iostream>
// Boost.Tokenizer allows you to iterate over partial expressions in a string by interpreting certain characters as separators 

// Example 10.1 Iterating over partial expressions in a string with boost::tokenizer 
#include <boost/tokenizer.hpp>

// Example 10.2 Initializing boost::char_separator to adapt the iteration 


#ifdef CHYI 

int main(int argc, char* argv[]) 
{
	// Example 10.1 Iterating over partial expressions in a string with boost::tokenizer 
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer1; // which interprets spaces and punctuation marks as separators
	std::string s1 = "Boost C++ Libraries";
	tokenizer1 tok1{ s1 };
	for (tokenizer1::iterator it1 = tok1.begin(); it1 != tok1.end(); ++it1)
		std::cout << *it1 << '\n';

	// Example 10.2 Initializing boost::char_separator to adapt the iteration 
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer2;
	std::string s2 = "Boost C++ Libraries";
	boost::char_separator<char> sep2{ " " };
	tokenizer2 tok2{ s2, sep2 };
	for (const auto &t2 : tok2)
		std::cout << t2 << '\n';

	return 0;
}

#endif 