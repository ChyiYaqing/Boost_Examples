#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

// Example 5.1. Converting strings to uppercase 
#include <boost/algorithm/string.hpp>	// common header including all other headers files for convernience

// Example 5.2. Converting a string to uppercase with a locale 
#include <locale>

// Example 5.3. Algorithms to remove characters from a string

// Example 5.4. Searching for substring with boost::algorithm::find_first()

// Example 5.5. Concatenating strings with boost::algorithm::join() 

// Example 5.6. Algorithms to replace characters in a string 

// Example 5.7. Algorithms to trim strings 

// Example 5.8. Creating predicates with boost::algorithm::is_any_of() 

// Example 5.9. Creating predicates with boost::algorithm::is_digit() 

// Example 5.10. Algorithms to compare strings with others 

// Example 5.11. Splitting strings with boost::algorithm::split()

// Example 5.12. Searching strings with boost::algorthm::find_regex() 
#include <boost/algorithm/string/regex.hpp>


#ifdef CHYI



int main(int argc, char* argv[]) 
{
	// Example 5.1 
	std::string s = "Boost C++ Libraries";
	std::cout << boost::algorithm::to_upper_copy(s) << '\n';	// converts a string to uppercase
	std::cout << boost::algorithm::to_lower_copy(s) << '\n';	// converts a string to lowercase

	// Example 5.2 Converting a string to uppercase with a locale 
	std::string s2 = "Boost C++ k\xfct\xfcphaneleri";
	std::locale::global(std::locale{ "Turkish" });
	std::cout << boost::algorithm::to_upper_copy(s2) << '\n'; // uses the global locate
	std::cout << boost::algorithm::to_upper_copy(s2, std::locale{ "Turkish" }) << '\n';

	// Example 5.3. Algorithms to remove characters from a string
	std::string s3 = "Boost C++ Libraries";
	std::cout << boost::algorithm::erase_first_copy(s3, "s") << '\n';	// will remove only the first occurrence of the character
	std::cout << boost::algorithm::erase_nth_copy(s3, "s", 0) << '\n';
	std::cout << boost::algorithm::erase_last_copy(s3, "s") << '\n';
	std::cout << boost::algorithm::erase_all_copy(s3, "s") << '\n';		// will remove all occurrences of a particular character from a string.
	std::cout << boost::algorithm::erase_head_copy(s3, 5) << '\n';
	std::cout << boost::algorithm::erase_tail_copy(s3, 9) << '\n';

	// Example 5.4. Searching for substring with boost::algorithm::find_first()
	std::string s4 = "Boost C++ Libraries";
	// All of these functions return a pair of iterator µü´úÆ÷ of type boost::iterator_range.
	boost::iterator_range<std::string::iterator> r = boost::algorithm::find_first(s4, "C++");
	std::cout << r << '\n';
	r = boost::algorithm::find_first(s4, "xyz");
	std::cout << r << '\n';

	// Example 5.5. Concatenating strings with boost::algorithm::join() 
	std::vector<std::string> v{ "Boost","C++","Libraries" };
	std::cout << boost::algorithm::join(v, " ") << '\n';	// A container of string is passed as the first parameter to the function, 
	// which concatenates them separated by the second parameter

	// Example 5.6. Algorithms to replace characters in a string 
	std::string s5 = "Boost C++ Libraries";
	std::cout << boost::algorithm::replace_first_copy(s5, "+","-") << '\n';
	std::cout << boost::algorithm::replace_nth_copy(s5, "+", 0, "-") << '\n';
	std::cout << boost::algorithm::replace_last_copy(s5, "+", "-") << '\n';
	std::cout << boost::algorithm::replace_all_copy(s5, "+", "-") << '\n';
	std::cout << boost::algorithm::replace_head_copy(s5, 5, "BOOST") << '\n';
	std::cout << boost::algorithm::replace_tail_copy(s5, 9, "LIBRARIES") << '\n';

	// Example 5.7. Algorithms to trim strings 
	std::string s6 = "\t Boost C++ Libraries \t";
	// To remove spaces on either end of a string
	std::cout << "_" << boost::algorithm::trim_left_copy(s6) << "_\n";
	std::cout << "_" << boost::algorithm::trim_right_copy(s6) << "_\n";
	std::cout << "_" << boost::algorithm::trim_copy(s6) << "_\n";

	// Example 5.8. Creating predicates with boost::algorithm::is_any_of() 
	std::string s7 = "--Boost C++ Libraries--";
	// which is a helper function to create a predicate that checks whether whether a certain character 
	std::cout << boost::algorithm::trim_left_copy_if(s7, boost::algorithm::is_any_of("-")) << '\n';
	std::cout << boost::algorithm::trim_right_copy_if(s7, boost::algorithm::is_any_of("-")) << '\n';
	std::cout << boost::algorithm::trim_copy_if(s7, boost::algorithm::is_any_of("-")) << '\n';

	// Example 5.9. Creating predicates with boost::algorithm::is_digit() 
	std::string s8 = "1234567890Boost C++ Libraries1234567890";
	// is used to removes digits from the string s 
	std::cout << boost::algorithm::trim_left_copy_if(s8, boost::algorithm::is_digit()) << '\n';
	std::cout << boost::algorithm::trim_right_copy_if(s8, boost::algorithm::is_digit()) << '\n';
	std::cout << boost::algorithm::trim_copy_if(s8, boost::algorithm::is_digit()) << '\n';

	// Example 5.10. Algorithms to compare strings with others 
	std::string s10 = "Boost C++ Libraries";
	std::cout.setf(std::ios::boolalpha);
	std::cout << boost::algorithm::starts_with(s10, "Boost") << '\n';
	std::cout << boost::algorithm::ends_with(s10, "Libraries") << '\n';
	std::cout << boost::algorithm::contains(s10, "C++") << '\n';
	std::cout << boost::algorithm::lexicographical_compare(s10, "Boost") << '\n'; // functions compare two individuals strings

	// Example 5.11. Splitting strings with boost::algorithm::split()
	std::string s11 = "Boost C++ Libraries";
	std::vector<std::string> v11;
	boost::algorithm::split(v11, s11, boost::algorithm::is_space()); // given string can be split based on a delimiter, the substrings are stored in container
	std::cout << v11.size() << '\n';

	// Example 5.12. Searching strings with boost::algorthm::find_regex() 
	std::string s12 = "Boost C++ Libraries";
	boost::iterator_range<std::string::iterator> r12 = boost::algorithm::find_regex(s12, boost::regex{ "\\w\\+\\+" });
	std::cout << r12 << '\n';

	return 0;
}
#endif // CHYI