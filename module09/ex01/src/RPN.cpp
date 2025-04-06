#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		// If the token is a number, push it onto the stack
		if (isNumber(token))
			_stack.push(std::stoi(token));

		// If the token is an operator, perform the operation
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("insufficient operands for operation");
			performOperation(token[0]);
		}
		else
			throw std::runtime_error("invalid token in expression");
	}

	// After processing all tokens, there should be exactly one value on the stack
	if (_stack.size() != 1)
		throw std::runtime_error("invalid RPN expression");

	std::cout << "Result: " << _stack.top() << std::endl;
	_stack.pop();
}

// operators: +, -, *, /
bool RPN::isOperator(std::string token) const
{
	return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

// numbers should be integers, or with a leading '-'
bool RPN::isNumber(std::string token) const
{
	if (token.empty())
		return false;

	size_t i = 0;
	if (token[0] == '-')
		i++;

	while (i < token.size())
	{
		if (!std::isdigit(token[i]))
			return false;
		i++;
	}

	return true;
}

void RPN::performOperation(char op)
{
	int b = _stack.top();
	_stack.pop();
	int a = _stack.top();
	_stack.pop();

	int result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0)
			throw std::runtime_error("division by zero");
		result = a / b;
		break;
	default:
		throw std::runtime_error("unknown operator"); // should never happen
	}

	_stack.push(result);
}