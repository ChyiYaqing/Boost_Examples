#include "pch.h"
#include <iostream>
/*
	Boost.Chrono provides a variety of clocks.
*/

// Example 37.1. All clocks from Boost.Chrono 
#include <boost/chrono.hpp>

using namespace boost::chrono;

// Example 37.2. Adding and subtracting durations using Boost.Chrono 


#ifdef CHYI



int main(int argc, char* argv[])
{
	// Example 37.1. All clocks from Boost.Chrono 
	// returns the system time 
	std::cout << system_clock::now() << '\n'; // now() returns a timepoint. uses epoch is 1 January 1970.
#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY  // is not supported on all platforms, The clock is only available if the macro BOOST_CHRONO_HAS_CLOCK_STEADY is define.
	std::cout << steady_clock::now() << '\n'; // measures the time elapsed since the last boot.
#endif

	std::cout << high_resolution_clock::now() << '\n';

#ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
	std::cout << process_real_cpu_clock::now() << '\n'; // is based on std::clock() 
	std::cout << process_user_cpu_clock::now() << '\n';
	std::cout << process_system_cpu_clock::now() << '\n';
	std::cout << process_cpu_clock::now() << '\n';
#endif 

#ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
	std::cout << thread_clock::now() << '\n';
#endif 

	// Example 37.2. Adding and subtracting durations using Boost.Chrono 
	process_real_cpu_clock::time_point p2 = process_real_cpu_clock::now();
	std::cout << p2 << '\n';
	std::cout << p2 - nanoseconds{ 1 } << '\n';
	std::cout << p2 + milliseconds{ 1 } << '\n';
	std::cout << p2 + seconds{ 1 } << '\n';
	std::cout << p2 + minutes{ 1 } << '\n';
	std::cout << p2 + hours{ 1 } << '\n';

	return 0;
}

#endif // CHYI