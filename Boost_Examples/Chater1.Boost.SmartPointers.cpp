// Boost_Examples.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <boost/scoped_ptr.hpp>		// is a smart pointer that is the sole owner of a dynamically allocated object
#include <boost/scoped_array.hpp>	// boost::scoped_array uses the operator delete[] to release the contained object 
#include <boost/shared_ptr.hpp>		// Ownership can be shared with other smart pointers of type


int main()
{
	// the member functions get() and reset() are provided to retrieve and reinitialize the address of the contained object.
	boost::scoped_ptr<int> p{ new int{1} };
	std::cout << *p << '\n';
	p.reset(new int{ 2 });
	std::cout << *p.get() << '\n';	// get() return the address of the object ianchored in the smart pointer.
	p.reset(); // 
	std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

	// boost::scoped_array must be initialized with the address of a dynamically allocated array.
	boost::scoped_array<int> p_array{ new int[2] };
	*p_array.get() = 1;
	p_array[1] = 2;
	p.reset(new int[3]);

	// Shared Ownership 
	boost::shared_ptr<int> p_share{ new int{1} };
	std::cout << *p_share << '\n';
	boost::shared_ptr<int> p_share2{ p_share };
	p_share.reset(new int{ 2 });
	std::cout << *p_share.get() << '\n';
	p_share.reset();
	std::cout << std::boolalpha << static_cast<bool>(p_share2) << '\n';

	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

/*
	Boost.SmartPointers smart pointers: help you manage dynamically allocated objects, 
	which are anchored in smart pointers that release the dynamically allocated objects in the destructor

	C++ 11, std::shared_ptr		std::weak_ptr 
	Boost  boost::shared_ptr		boost::weak_ptr
*/