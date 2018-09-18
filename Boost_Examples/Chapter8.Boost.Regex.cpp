#include <string>
#include <iostream>

// Example 8.1. Comparing strings with boost::regex_match()
#include <boost/regex.hpp>


int main(int argc, char* argv[]){
	
	// Example 8.1. Comparing strings with boost::regex_match()
	std::string s1 = "Boost Libraries";
	boost::regex expr{"\\w+\\s\\w+"};
	std::cout << std::boolalpha << boost::regex_match(s1, expr) << '\n';


	return 0;
}
