#include "pch.h"
#include <string>
#include <iostream>

// Example 15.1. Using boost::unordered_set 
#include <boost/unordered_set.hpp>

// Example 15.2. Using boost::unordered_map 
#include <boost/unordered_map.hpp>

// Example 15.3. User-defined type with Boost.Unordered 
struct animal {
	std::string name;
	int legs;
};

bool operator==(const animal &lhs, const animal &rhs) {
	return lhs.name == rhs.name && lhs.legs == rhs.legs;
}

// hash_value() is automatically called when the hash value has to be calculated for an object
std::size_t hash_value(const animal &a) {
	std::size_t seed = 0;
	boost::hash_combine(seed, a.name);
	boost::hash_combine(seed, a.legs);
	return seed;
}

#ifdef CHYI




int main(int argc, char* argv[])
{
	typedef boost::unordered_set<std::string> unordered_set1;
	unordered_set1 set1;;

	set1.emplace("cat");
	set1.emplace("shark");
	set1.emplace("spider");

	for (const std::string &s : set1)
		std::cout << s << '\n';

	std::cout << set1.size() << '\n';
	std::cout << set1.max_size() << '\n';

	std::cout << std::boolalpha << (set1.find("cat") != set1.end()) << '\n';
	std::cout << set1.count("shark") << '\n';
	
	// Example 15.2. Using boost::unordered_map 
	typedef boost::unordered_map<std::string, int> unordered_map2;
	unordered_map2 map2;

	map2.emplace("cat", 4);
	map2.emplace("shark", 0);
	map2.emplace("spider", 8);

	for (const auto &p : map2)
		std::cout << p.first << ";" << p.second << '\n';

	std::cout << map2.size() << '\n';
	std::cout << map2.max_size() << '\n';

	std::cout << std::boolalpha << (map2.find("cat") != map2.end()) << '\n';
	std::cout << map2.count("shark") << '\n';

	// Example 15.3. User-defined type with Boost.Unordered 
	typedef boost::unordered_set<animal> unordered_set3;
	unordered_set3 animals3;

	animals3.insert({ "cat", 4 });
	animals3.insert({ "shark", 0 });
	animals3.insert({ "spider", 8 });

	return 0;
}
#endif // CHYI