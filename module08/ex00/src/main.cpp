#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i);

	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}