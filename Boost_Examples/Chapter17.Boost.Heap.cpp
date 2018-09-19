#include "pch.h"
#include <string>
#include <iostream>

// Example 17.1. Using boost::heap::priority_queue 
#include <boost/heap/priority_queue.hpp>

// Example 17.2. Using boost::heap::binomial_heap 
#include <boost/heap/binomial_heap.hpp>

// Example 17.3. Changing elements in boost::heap::binomial_heap

using namespace boost::heap;

#ifdef CHYI

int main(int argc, char* argv[])
{
	// Example 17.1. Using boost::heap::priority_queue 
	priority_queue<int> pq1;
	pq1.push(2);
	pq1.push(3);
	pq1.push(1);

	for (int i : pq1)
		std::cout << i << '\n'; // The order of elements returned in the iteration is random

	priority_queue<int> pq12;
	pq12.push(4);
	std::cout << std::boolalpha << (pq1 > pq12) << '\n'; // because pq1 has more elements than pq12

	// Example 17.2. Using boost::heap::binomial_heap 
	binomial_heap<int> bh2;
	bh2.push(2);
	bh2.push(3);
	bh2.push(1);

	binomial_heap<int> bh22;
	bh22.push(4);
	bh2.merge(bh22);

	// returns an iterator that iterates from high priority elements to low priority elements.
	for (auto it2 = bh2.ordered_begin(); it2 != bh2.ordered_end(); ++it2)
		std::cout << *it2 << '\n';

	std::cout << std::boolalpha << bh22.empty() << '\n';
	
	// Example 17.3. Changing elements in boost::heap::binomial_heap
	binomial_heap<int> bh3;
	auto headle3 = bh3.push(2);
	bh3.push(3);
	bh3.push(1);

	bh3.update(headle3, 4); // can be called to change an element

	std::cout << bh3.top() << '\n';


	return 0;
}
#endif