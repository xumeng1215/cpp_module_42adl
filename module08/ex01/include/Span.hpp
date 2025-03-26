#pragma once

#include <iostream>

class Span
{
private:
	unsigned int _n_size;
	std::vector<int> _v;

	Span();
public:
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

	Span(unsigned int n);

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

class FullException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class NoSpanException : public std::exception
{
public:
	virtual const char *what() const throw();
};
