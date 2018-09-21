#include "pch.h"
#include <iostream>

/*
	Boost.Thread lets you create and manage your own thread. Furthermore, it provides classes to synchronize access on data which is shared by multiple threads.

	Threads have been supported by the standard library 
*/

// Example 44.1. Using boost::thread 
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream> 

void wait1(int seconds) {
	// how long the current thread should be stalled.
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void thread1() {
	for (int i = 0; i < 5; ++i) {
		wait1(1);
		std::cout << i << '\n';
	}
}

// Example 44.2. Waiting for a thread with boost::scoped_thread 
#include <boost/thread/scoped_thread.hpp>

int main(int argc, char* argv[])
{
	// Example 44.1. Using boost::thread 
	// A thread is always bound to a variable of type boost::thread in the beginning,but once created, the thread no longer depends on that variable.
	boost::thread t1{ thread1 }; // Once the variable t1 is created, the function thread1 starts immediately executing in its own thread.
	t1.join(); // To keep the programming from terminating, blocks the current thread until the thread was called has terminated.

	// Example 44.2. Waiting for a thread with boost::scoped_thread 
	boost::scoped_thread<> t2{ boost::thread{thread1} };



	return 0;
}