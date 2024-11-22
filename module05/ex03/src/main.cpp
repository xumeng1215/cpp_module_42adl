#include "Bureaucrat.hpp"
#include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Intern intern;

	// AForm *f1 = intern.makeForm("ShrubberyCreationForm", "Home");
	// AForm *f1 = intern.makeForm("RobotomyRequestForm", "Robot");
	AForm *f1 = intern.makeForm("PresidentialPardonForm", "Pardon");

	std::cout << "--------------test--------------" << std::endl;
	b1.signForm(*f1);
	b1.executeForm(*f1);
	std::cout << "--------------test--------------" << std::endl;
}