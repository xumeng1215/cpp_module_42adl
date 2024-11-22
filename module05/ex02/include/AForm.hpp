#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Aform
{
private:
	const std::string _name;
	bool _signed;
	int _signGrade;
	int _execGrade;

public:
	Aform();
	Aform(std::string const &name, int signGrade, int execGrade);
	~Aform();
	Aform(const Aform &other);
	Aform &operator=(const Aform &other);

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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form is not signed.";
		};
	};

	friend std::ostream &operator<<(std::ostream &out, const Aform &form);

	virtual void execute(Bureaucrat const &executor) const = 0;
};