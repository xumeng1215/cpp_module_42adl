#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Aform
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(Bureaucrat const &executor) const;

};