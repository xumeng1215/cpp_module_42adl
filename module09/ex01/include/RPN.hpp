#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	void calculate(const std::string &expression);

private:
	std::stack<int> _stack;

	bool isOperator(std::string token) const;
	bool isNumber(std::string token) const;
	void performOperation(char op);
};