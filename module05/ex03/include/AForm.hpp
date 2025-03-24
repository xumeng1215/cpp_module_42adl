#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	int _signGrade;
	int _execGrade;

public:
	AForm();
	AForm(std::string const &name, int signGrade, int execGrade);
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	std::string const &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);