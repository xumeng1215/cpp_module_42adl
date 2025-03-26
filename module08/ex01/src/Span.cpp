#include "Span.hpp"

Span::Span() : _n_size(0)
{
}

Span::Span(unsigned int n) : _n_size(n)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_n_size = other._n_size;
		_v = other._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n_size)
		throw FullException();
	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n_size)
		throw FullException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::sort(_v.begin(), _v.end());
	int min = INT_MAX;
	for (size_t i = 1; i < _v.size(); i++)
	{
		if (_v[i] - _v[i - 1] < min)
			min = _v[i] - _v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::sort(_v.begin(), _v.end());
	return _v.back() - _v.front();
}

const char *FullException::what() const throw()
{
	return "The container is full";
}

const char *NoSpanException::what() const throw()
{
	return "There is no span to find";
}

