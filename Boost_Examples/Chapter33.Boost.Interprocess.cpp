#include "pch.h"
/*
	Chapter 33. Boost.Interprocess
		Interprocess communication describes mechanisms to exchange data between programs running on the same computer.
		While Boost.Asio can be used to exchange data between processes running on the same computer.
		Boost.Interprocess usually provides better performance. 
		Boost.Interprocess calls operating system functions optimized for data exchange between processes running on the same computer and thus should be the first choice to exchange data without a network.

		Shared Memory:
			Shared memory is typically the fastest form of interprocess communication.It provides a memory area that is shared between processes.
			One process can write data to the area and another process can read it.
			each process needs to map the shared memory into its address space.

		Managed Shared Memory:
			C++ style favors creating objects of classes and hiding the specifics of where and how data is stored in memory 

		Synchronization: 
			Boost.Interprocess allows multiple processes to use shared memory concurrently.
			Boost.Interprocess provides two kinds of synchronization objects. 
				Anonymous object: directly stored in the shared memory , which makes them automatically available to all processes
				Named objects: are managed by the operating system, are not stored in the shared memory, and can be referenced from programs by name 

*/

// Example 33.1. Creating shared memory 
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>
using namespace boost::interprocess;

// Example 33.2. Mapping shared memory into the address space of a process 
#include <boost/interprocess/mapped_region.hpp>

// Example 33.3. Writing and reading a number in shared memory

// Example 33.4. Deleting shared memory 

// Example 33.6. Using managed shared memory 
#include <boost/interprocess/managed_shared_memory.hpp>

// Example 33.7. Creating arrays in managed shared memory

// Example 33.8. An exception of type boost::interprocess::bad_alloc 

// Example 33.9. Removing objects in shared memory 

// Example 33.10. Putting strings into shared memory 
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>

// Example 33.12. Using a named mutex with boost::interprocess::named_mutex 
#include <boost/interprocess/sync/named_mutex.hpp>

// Example 33.13. Using an anonymous mutex with interprocess_mutex 
#include <boost/interprocess/sync/interprocess_mutex.hpp>

#ifdef CHYI




int main(int argc, char* argv[]) {

	// Example 33.1. Creating shared memory 
	// open_or_create: will open shared memory if it already exists or create shared memory if it doesn't 
	// To uniquely identify shared memory, a name is assigned. 
	// read_write: the process has read-write access.
	shared_memory_object shdmem1{ open_or_create, "Boost", read_write };
	shdmem1.truncate(1024); // provides space for 1,024 bytes; can be called repeatedly to adjust the size of the shared memory
	std::cout << shdmem1.get_name() << '\n'; // query the name of the shared memory

	offset_t size;
	if (shdmem1.get_size(size)) // query the size of the shared memory
		std::cout << size << '\n';

	// Example 33.2. Mapping shared memory into the address space of a process 
	shared_memory_object shdmem2{ open_or_create, "Boost", read_write };
	shdmem2.truncate(1024);

	mapped_region region21{ shdmem2, read_write };
	std::cout << std::hex << region21.get_address() << '\n';	// get_address() is different for each object
	std::cout << std::dec << region21.get_size() << '\n';		// get_size() return 1024 in both cases
	
	mapped_region region22{ shdmem2, read_only };
	std::cout << std::hex << region22.get_address() << '\n';
	std::cout << std::dec << region22.get_size() << '\n';

	// Example 33.3. Writing and reading a number in shared memory
	shared_memory_object shdmem3{ open_or_create, "Boost", read_write };
	shdmem3.truncate(1024);
	// region31, region32 represent different memory areas within the process, because both memory areas access the same underlying shared memory
	mapped_region region31{ shdmem3, read_write };
	int *i1 = static_cast<int *>(region31.get_address());
	*i1 = 99;

	mapped_region region32{ shdmem3, read_only };
	int *i2 = static_cast<int*>(region32.get_address());
	std::cout << *i2 << '\n';

	// Example 33.4. Deleting shared memory 
	// If remove() is never called, the shared memory continues to exist even if the program terminates.
	bool removed4 = shared_memory_object::remove("Boost"); // static member function remove() 
	std::cout << std::boolalpha << removed4 << '\n';

	// Example 33.6. Using managed shared memory 
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm6{ open_or_create, "Boost", 1024 };

	int *i6 = managed_shm6.construct<int>("Integer")(99);
	std::cout << *i6 << '\n';
	
	std::pair<int*, std::size_t> p6 = managed_shm6.find<int>("Integer"); // returns either a pointer to the object 
	if (p6.first)
		std::cout << *p6.first << '\n';

	// Example 33.7. Creating arrays in managed shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm7{ open_or_create, "Boost", 1024 };

	int *i7 = managed_shm7.construct<int>("Integer")[10](99); // all ten elements in the array are initialized with the value 99.
	std::cout << *i7 << '\n';
	std::pair<int*, std::size_t> p7 = managed_shm7.find<int>("Integer");
	if (p7.first) {
		std::cout << *p7.first << '\n';
		std::cout << p7.second << '\n';
	}

	// Example 33.8. An exception of type boost::interprocess::bad_alloc 
	try {
		shared_memory_object::remove("Boost");
		managed_shared_memory managed_shm8{ open_or_create, "Boost", 1024 };

		int *i8 = managed_shm8.construct<int>("Integer")[4096](99);
	}
	catch (boost::interprocess::bad_alloc &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	// Example 33.9. Removing objects in shared memory 
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm9{ open_or_create, "Boost", 1024 };

	int *i9 = managed_shm9.find_or_construct<int>("Integer")(99);
	std::cout << *i9 << '\n';
	
	managed_shm9.destroy<int>("Integer");
	std::pair<int*, std::size_t> p9 = managed_shm9.find<int>("Integer");
	std::cout << p9.first << '\n';

	// Example 33.10. Putting strings into shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm10{ open_or_create, "Boost", 1024 };

	typedef allocator<char, managed_shared_memory::segment_manager> CharAllocator10;
	typedef basic_string<char, std::char_traits<char>, CharAllocator10> string;
	string *s = managed_shm10.find_or_construct<string>("String")("Hello!", managed_shm10.get_segment_manager());
	s->insert(5, ", world");
	std::cout << *s << '\n';

	// Example 33.12. Using a named mutex with boost::interprocess::named_mutex  
	managed_shared_memory managed_shm12{ open_or_create, "shm", 1024 };
	int *i12 = managed_shm12.find_or_construct<int>("Integer")();

	named_mutex named_mtx12{open_or_create, "mtx"}; 
	// To access the data in shared memory, the program needs to take ownership of the mutex by calling the member function lock().
	named_mtx12.lock();
	++(*i12); // Once a process takes ownership of a mutex, it has exclusive access to the resource the mutex guards.
	std::cout << *i12 << '\n';
	named_mtx12.unlock();

	// Example 33.13. Using an anonymous mutex with interprocess_mutex 
	managed_shared_memory managed_shm13{ open_or_create, "shm", 1024 };
	int *i13 = managed_shm13.find_or_construct<int>("Integer")();

	// anonymous mutex 
	interprocess_mutex *mtx = managed_shm13.find_or_construct<interprocess_mutex>("mtx")();
	mtx->lock();
	++(*i13);
	std::cout << *i13 << '\n';
	mtx->unlock();




	return 0;
}
#endif // CHYI