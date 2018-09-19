#include "pch.h"
#include <string>
#include <iostream>

// Example 8.1. Comparing strings with boost::regex_match()
#include <boost/regex.hpp>

// Example 8.2. Searching string with boost::regex_search()

// Example 8.3. Replacing characters in strings with boost::regex_replace() 

// Example 8.4. Format with references to groups in regular expressions 

// Example 8.5. Flags for formats

// Example 8.6. Iterating over string with boost::regex_token_iterator 

// Example 8.7. Accessing groups with boost::regex_token_iterator 

// Example 8.8. Linking a locale to a regular expression 
#include <locale>

#ifdef CHYI




int main(int argc, char* argv[]){
	
	// Example 8.1. Comparing strings with boost::regex_match()
	std::string s1 = "Boost Libraries";
	boost::regex expr{"\\w+\\s\\w+"};
	// compares a string with a regular expression. It will return true only if the expression matches the complete string
	std::cout << std::boolalpha << boost::regex_match(s1, expr) << '\n';

	// Example 8.2. Searching string with boost::regex_search()
	std::string s2 = "Boost Libraries";
	boost::regex expr2{ "(\\w+)\\s(\\w+)" };
	boost::smatch what2;	// which is used to store the result.
	if (boost::regex_search(s2, what2, expr2))
	{
		std::cout << what2[0] << '\n'; // the first element of the container boost::smatch stores iterators referencing the string that matches the entire regular expressions
		std::cout << what2[1] << "_" << what2[2] << '\n';
	}

	// Example 8.3. Replacing characters in strings with boost::regex_replace() 
	std::string s3 = " Boost Libraries ";
	boost::regex expr3{ "\\s" }; // \s ¿Õ°××Ö·û
	std::string fmt3{ "_" };
	std::cout << boost::regex_replace(s3, expr3, fmt3) << '\n';
	
	// Example 8.4. Format with references to groups in regular expressions 
	std::string s4 = "Boost Libraries";
	boost::regex expr4{ "(\\w+)\\s(\\w+)" };
	std::string fmt4{ "\\2 \\1" };
	// The format can access substring returned by groups of the regular expression
	std::cout << boost::regex_replace(s4, expr4, fmt4) << '\n';

	// Example 8.5. Flags for formats
	std::string s5 = "Boost Libraries";
	boost::regex expr5{ "(\\w+)\\s(\\w+)" };
	std::string fmt5{ "\\2 \\1" };
	std::cout << boost::regex_replace(s5, expr5, fmt5, boost::regex_constants::format_literal) << '\n';

	// Example 8.6. Iterating over string with boost::regex_token_iterator 
	std::string s6 = "Boost Libraries";
	boost::regex expr6{ "\\w+" };
	boost::regex_token_iterator<std::string::iterator> it6{ s6.begin(), s6.end(), expr6 };
	boost::regex_token_iterator<std::string::iterator> end6;
	while (it6 != end6)
		std::cout << *it6++ << '\n';

	// Example 8.7. Accessing groups with boost::regex_token_iterator 
	std::string s7 = "Boost Libraries";
	boost::regex expr7{ "(\\w)\\w+" };
	boost::regex_token_iterator<std::string::iterator> it7{ s7.begin(), s7.end(), expr7, 1 };
	boost::regex_token_iterator<std::string::iterator> end7;
	while (it7 != end7)
		std::cout << *it7++ << '\n';

	// Example 8.8. Linking a locale to a regular expression 
	std::string s8 = "Boost k\xfct\xfcphaneleri";
	boost::basic_regex<char, boost::cpp_regex_traits<char>> expr8;
	expr8.imbue(std::locale{ "Turkish" });
	expr8 = "\\w+\\s\\w+";
	std::cout << std::boolalpha << boost::regex_match(s8, expr8) << '\n';

	return 0;
}

#endif // CHYI