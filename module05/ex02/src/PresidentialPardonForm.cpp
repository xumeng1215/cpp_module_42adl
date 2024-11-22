#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is constructed." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is destructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is copied." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other._target;
	std::cout << "PresidentialPardonForm " << this->getName() << " is assigned." << std::endl;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}	