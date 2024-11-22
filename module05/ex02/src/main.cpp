#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("b1", 10);

	ShrubberyCreationForm s1("Home");
	RobotomyRequestForm r1("Robot");
	PresidentialPardonForm p1("Pardon");

	std::cout << "--------------test--------------" << std::endl;
	b1.signForm(s1);
	b1.executeForm(r1);

	b1.signForm(r1);
	b1.executeForm(r1);

	b1.signForm(p1);
	b1.executeForm(p1);
	std::cout << "--------------test--------------" << std::endl;
}