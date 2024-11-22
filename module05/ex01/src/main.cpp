#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	
	Form *form = new Form("form", 1, 20);
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->signForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}


	delete bureaucrat;
	return 0;
}