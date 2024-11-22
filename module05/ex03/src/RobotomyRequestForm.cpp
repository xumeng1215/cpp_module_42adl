#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is constructed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
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
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "*make some drilling noises*" << std::endl;
	srand(time(NULL));
	// int i = rand() % 2;
	// std::cout << "i is " << i << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully....." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}
