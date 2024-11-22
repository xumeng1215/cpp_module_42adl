#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Aform
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void execute(Bureaucrat const &executor) const;
};