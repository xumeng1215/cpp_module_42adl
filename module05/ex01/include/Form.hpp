#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	Form();
	Form(std::string const &name, int signGrade, int execGrade);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	std::string const &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too high.";
		};
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too low.";
		};
	};

	friend std::ostream &operator<<(std::ostream &out, const Form &form);
};
