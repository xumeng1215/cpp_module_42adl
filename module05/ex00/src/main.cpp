#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("bigman", 150);
	std::cout << *bureaucrat << std::endl;
	bureaucrat->incrementGrade();
	std::cout << *bureaucrat << std::endl;
	bureaucrat->decrementGrade();
	std::cout << *bureaucrat << std::endl;
	try
	{
		bureaucrat->decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	delete bureaucrat;
	return 0;
}