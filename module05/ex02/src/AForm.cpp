#include "AForm.hpp"
#include "Bureaucrat.hpp"

Aform::Aform() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

Aform::Aform(std::string const &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Aform::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Aform::GradeTooLowException();
	std::cout << "Form " << this->_name << " is constructed." << std::endl;
}

Aform::~Aform()
{
	std::cout << "Form " << this->_name << " is destructed." << std::endl;
}

Aform::Aform(const Aform &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form " << this->_name << " is copied." << std::endl;
}

Aform &Aform::operator=(const Aform &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	std::cout << "Form sign status of " << this->_name << " is assigned." << std::endl;
	return *this;
}

std::string const &Aform::getName() const
{
	return this->_name;
}

bool Aform::getSigned() const
{
	return this->_signed;
}

int Aform::getSignGrade() const
{
	return this->_signGrade;
}

int Aform::getExecGrade() const
{
	return this->_execGrade;
}

std::ostream &operator<<(std::ostream &out, const Aform &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " with sign grade " << form.getSignGrade() << " and exec grade " << form.getExecGrade() << ".";
	return out;
}

void Aform::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Aform::GradeTooLowException();
	this->_signed = true;
}