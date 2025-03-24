#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

Form::Form(std::string const &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " is destructed." << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form " << this->_name << " is copied." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	std::cout << "Form sign status of " << this->_name << " is assigned." << std::endl;
	return *this;
}

std::string const &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed.";
	return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}