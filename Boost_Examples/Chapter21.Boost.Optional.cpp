#include "pch.h"
#include <string>
#include <iostream>

// Example 21.1. Special values to denote optional return values
#include <cstdlib>
#include <ctime>
#include <cmath>

int get_event_random_number()
{
	int i = std::rand();
	return (i % 2 == 0) ? i : -1;
}

#ifdef CHYI

int main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int i = get_event_random_number();
	if (i != -1)
		std::cout << std::sqrt(static_cast<float>(i)) << '\n';

	return 0;
}
#endif 