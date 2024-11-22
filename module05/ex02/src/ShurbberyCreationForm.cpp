#include "ShurbberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Aform("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Aform("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is constructed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is destructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Aform(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is copied." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	this->_target = other._target;
	std::cout << "ShrubberyCreationForm " << this->getName() << " is assigned." << std::endl;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Aform::GradeTooLowException();
	if(!this->getSigned())
		throw Aform::FormNotSignedException();
	std::ofstream file(this->_target + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("File open failed.");
	file << "ASCII trees?" << std::endl;
	file.close();
}