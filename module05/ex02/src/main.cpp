#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("bigman", 150);
	std::cout << *bureaucrat << std::endl;

	ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("HOME");
	std::cout << *shrubbery << std::endl;
	try
	{
		bureaucrat->signForm(*shrubbery);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bureaucrat->executeForm(*shrubbery);
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