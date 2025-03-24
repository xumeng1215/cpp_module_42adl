#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
private:
	const std::string _name;
	int _grade; // 1 to 150
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	
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
	
	void signForm(AForm &form);
	
	void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);