// Boost_Examples.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

/*
	Boost.SmartPointers smart pointers: help you manage dynamically allocated objects, 
	which are anchored in smart pointers that release the dynamically allocated objects in the destructor

	C++ 11, std::shared_ptr		std::weak_ptr 
	Boost  boost::shared_ptr		boost::weak_ptr
*/