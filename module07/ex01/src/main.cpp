#include "2.hpp"
#include <iostream>

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print);
	std::cout << std::endl;
	std::string array2[] = {"one", "two", "three", "four", "five"};
	iter(array2, 5, print);
	std::cout << std::endl;
	return 0;

}