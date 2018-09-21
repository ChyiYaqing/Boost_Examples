#include "pch.h"
#include <iostream>
/*
	Boost.Timer provides clocks to measure code performance.
*/

// Example 38.1. Measuring time with boost::timer::cpu_timer 
#include <boost/timer/timer.hpp>
#include <cmath>

using namespace boost::timer;

// Example 38.2. Stopping and resuming timers. 

// Example 38.3. Getting wall and CPU time as a tuple 

// Example 38.4. Measuring times automatically with boost::timer::auto_cpu_timer


#ifdef CHYI

int main(int argc, char* argv[])
{
	// Example 38.1. Measuring time with boost::timer::cpu_timer 
	cpu_timer timer1; // Measurement starts when boost::timer::cpu_timer is instantiated. 
	
	for (int i = 0; i < 1000000; ++i) {
		std::pow(1.234, i);
	}
	// The wall time is the time which passes according to a wall clock.
	// The CPU time says how much time the program spent executing code.
	// CPU time is divided between time spent in user space, kernel space. The amount of time spent in kernel space depends on the operating system functions called and how much time
	std::cout << timer1.format() << '\n'; // format() at any point to get the elapsed time.

	// Example 38.2. Stopping and resuming timers. 
	cpu_timer timer2;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer2.format() << '\n';

	timer2.stop();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer2.format() << '\n';

	timer2.resume(); // start() , the timer restarts from zero. 

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer2.format() << '\n'; // format() return the measured wall and CPU time as a string 

	// Example 38.3. Getting wall and CPU time as a tuple 
	cpu_timer timer3;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);

	cpu_times times3 = timer3.elapsed(); // returns a tuple of type 
	std::cout << times3.wall << '\n'; // wall times in nonoseconds 
	std::cout << times3.user << '\n'; // CPU times in nanoseconds
	std::cout << times3.system << '\n';

	// Example 38.4. Measuring times automatically with boost::timer::auto_cpu_timer
	auto_cpu_timer timer4;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);

	return 0;
}
#endif // CHYI