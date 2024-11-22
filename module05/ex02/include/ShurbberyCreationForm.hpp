#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void execute(Bureaucrat const &executor) const;
};