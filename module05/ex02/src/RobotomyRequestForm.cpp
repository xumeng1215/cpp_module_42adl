#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Aform("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Aform("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is constructed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Aform(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is copied." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other._target;
	std::cout << "RobotomyRequestForm " << this->getName() << " is assigned." << std::endl;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Aform::GradeTooLowException();
	if (!this->getSigned())
		throw Aform::FormNotSignedException();
	std::cout << "*make some drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}
