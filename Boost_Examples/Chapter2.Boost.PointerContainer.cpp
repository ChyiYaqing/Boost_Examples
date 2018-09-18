#include "pch.h"
#include <iostream>

// Example 2.1. Using boost::ptr_vector 
#include <boost/ptr_container/ptr_vector.hpp>

// Example 2.2. boost::ptr_set with intuitively correct order 
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <set>
#include <memory>
#include <functional>


#ifdef CHYI 
int main(int argc, char* argv[]) 
{
	// Example 2.1. Using boost::ptr_vector 
	boost::ptr_vector<int> v;
	v.push_back(new int{ 1 });
	v.push_back(new int{ 2 });
	std::cout << v.back() << '\n';	// back() return a reference to a dynamically allocated object and not a pointer.

	// Example 2.2 
	boost::ptr_set<int> s;
	s.insert(new int{ 2 });
	s.insert(new int{ 1 });
	std::cout << *s.begin() << '\n'; // boost::ptr_set the order of the elements depends on the int value

	std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v2;
	v2.insert(std::unique_ptr<int>(new int{ 2 }));
	v2.insert(std::unique_ptr<int>(new int{ 1 }));
	std::cout << **v2.begin() << '\n';

	std::cout << "Hello World!\n";
	return 0;
}
#endif