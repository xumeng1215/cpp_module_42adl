#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

AForm::AForm(std::string const &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form " << this->_name << " is destructed." << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form " << this->_name << " is copied." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	std::cout << "Form sign status of " << this->_name << " is assigned." << std::endl;
	return *this;
}

std::string const &AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " with sign grade " << form.getSignGrade() << " and exec grade " << form.getExecGrade() << ".";
	return out;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}