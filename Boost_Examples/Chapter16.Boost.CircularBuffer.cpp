#include "pch.h"
#include <string>
#include <iostream>
/*
	Boost.CircularBuffer: provides a circular buffer, which is a container with the following
		If the maxiumum size has been reached and the circular buffer is full, elements are overwritten
	A circular buffer makes sense when the amount of available memory is limited.
*/

// Example 16.1. Using boost::circular_buffer
#include <boost/circular_buffer.hpp>

// Example 16.2. Various member functions of boost::circular_buffer 

#ifdef CHYI



int main(int argc, char* argv[])
{
	// Example 16.1. Using boost::circular_buffer
	typedef boost::circular_buffer<int> circular_buffer1; // boost::circular_buffer is a template and must be instantiated with a type
	circular_buffer1 cb1{ 3 };

	std::cout << cb1.capacity() << '\n';	// The capacity of a circular buffer
	std::cout << cb1.size() << '\n';

	cb1.push_back(0);
	cb1.push_back(1);
	cb1.push_back(2);

	std::cout << cb1.size() << '\n';

	cb1.push_back(3);
	cb1.push_back(4);
	cb1.push_back(5);

	std::cout << cb1.size() << '\n';

	for (int i : cb1)
		std::cout << i << '\n';

	// Example 16.2. Various member functions of boost::circular_buffer 
	typedef boost::circular_buffer<int> circular_buffer2;
	circular_buffer2 cb2{ 3 };

	cb2.push_back(0);
	cb2.push_back(1);
	cb2.push_back(2);
	cb2.push_back(3); // overwrite the number 0 with the number 3, The beginning element with the number 1

	// The member function is_linearized() returns true if the beginning of the circular buffer is at the lowest memory address.
	std::cout << std::boolalpha << cb2.is_linearized() << '\n';

	circular_buffer2::array_range ar21, ar22;

	ar21 = cb2.array_one(); // accesses the array at the beginning of the circular buffer.
	ar22 = cb2.array_two(); // accesses the array at the end of the buffer 
	std::cout << ar21.second << ';' << ar22.second << '\n';

	for (int i : cb2)
		std::cout << i << '\n';

	cb2.linearize(); // force a rearrangement of the elements by calling linearize() 

	ar21 = cb2.array_one();
	ar22 = cb2.array_two();
	std::cout << ar21.second << ';' << ar22.second << '\n';

	return 0;
}

#endif // CHYI