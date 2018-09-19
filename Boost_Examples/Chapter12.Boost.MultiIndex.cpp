#include "pch.h"
#include <string>
#include <iostream>
/*
	Boost.MultiIndex makes it possible to define containers that support an arbitrary number of interfaces.
	std::vector provides an interface that supports direct access to elements with a index 
	std::set provides an interface that sorts elements.
*/

// Example 12.1. Using boost::multi_index::multi_index_container
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>


using namespace boost::multi_index;

struct animal {
	std::string name;
	int legs;
};

typedef multi_index_container<	// used for every container definition.
	animal,	// The first parameter is the type of elements the container should store.
	indexed_by<
	hashed_non_unique<
	member< // to access a member variable
	animal, std::string, &animal::name
	>
	>,
	hashed_non_unique<
	member<
	animal, int, &animal::legs
	>
	>
	>
> animal_multi;

#ifdef CHYI


int main(int argc, char* argv[]) 
{
	// Example 12.1. Using boost::multi_index::multi_index_container
	animal_multi animals;
	// If you directly access the object animals using insert() or count(), the first interface is used.
	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ " spider", 8 });

	std::cout << animals.count("cat") << '\n';
	
	// call the member function get() and pass in the index of the desired interface as the template parameter.
	const animal_multi::nth_index<1>::type &legs_index = animals.get<1>();
	std::cout << legs_index.count(8) << '\n';

	return 0;
}
#endif // CHYI