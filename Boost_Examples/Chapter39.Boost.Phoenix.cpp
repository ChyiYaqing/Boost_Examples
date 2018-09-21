#include "pch.h"
#include <iostream>
/*
	Functional Programming  º¯Êý±à³Ì
		In the functional programming model, functions are objects.
		can be passed as parameters to functions or stored in containers.

		Boost.Phoenix is the most extensive and, It replaces the library Boost.Lambda, which is introduced breifly, but only for completeness.
		Boost.Function provides a class the makes it easy to define a function pointer without using the syntax that originated with the C programming language.
		Boost.Bind is an adapter that lets you pass functions as parameters to other functions even if the actual signature is differnt from the expected signature.
		Boost.Ref can be used to pass a reference to an object.even if a function passes the parameters by copy 
		Boost.Lambda could be called a predecessor of Boost.Phoenix.

	Boost.Phoenix is the most important Boost library for functional programming. 
		In functional programming, functions are objects and can be processed like objects. it is possible for a function to return another function as a result.
		It is also possible to pass a function as a parameter to another function.
		Accessing a function isn't equal to executing it.


*/

// Example 39.1. Preficates as global function, lambda function, and Phoenix function 
#include <boost/phoenix/phoenix.hpp>
#include <vector>
#include <algorithm>

// check if number is odd ÆæÊý
bool is_odd(int i) { return i & 2 == 1; }

// Example 39.2. Phoenix function versus lambda function 


#ifdef CHYI

int main(int argc, char* argv[])
{
	// Example 39.1. Preficates as global function, lambda function, and Phoenix function 
	std::vector<int> v1{ 1, 2, 3, 4, 5 };
	std::cout << std::count_if(v1.begin(), v1.end(), is_odd) << '\n'; // 

	auto lambda1 = [](int i) {return i % 2 == 1; };
	std::cout << std::count_if(v1.begin(), v1.end(), lambda1) << '\n';

	using namespace boost::phoenix::placeholders;
	auto phoenix1 = arg1 % 2 == 1; // arg1 is global instance of a function object 
	std::cout << std::count_if(v1.begin(), v1.end(), phoenix1) << '\n';

	// Example 39.2. Phoenix function versus lambda function 
	std::vector<int> v2{ 1, 2, 3, 4, 5 };
	
	auto lambda2 = [](int i) {return i % 2 == 1; };
	std::cout << std::count_if(v2.begin(), v2.end(), lambda2) << '\n';

	std::vector<long> v22;
	v22.insert(v22.begin(), v2.begin(), v2.end());

	using namespace boost::phoenix::placeholders;
	auto phoenix2 = arg1 % 2 == 1;

	std::cout << std::count_if(v2.begin(), v2.end(), phoenix2) << '\n';
	std::cout << std::count_if(v22.begin(), v22.end(), phoenix2) << '\n';

	return 0;
}

#endif // CHYI