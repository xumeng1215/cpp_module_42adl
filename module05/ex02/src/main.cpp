#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShurbberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("b1", 10);

	ShrubberyCreationForm s1("Home");
	RobotomyRequestForm r1("Robot");
	PresidentialPardonForm p1("Pardon");

	std::cout<< "--------------test--------------" << std::endl;
	try
	{
		b1.signForm(s1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b1.executeForm(r1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<< "--------------test--------------" << std::endl;
}