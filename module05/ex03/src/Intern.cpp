#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern()
{
}

static AForm *makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(*formCreators[3])(const std::string &target) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " now." << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Intern can not create a form called " << formName << std::endl;
	return NULL;
}