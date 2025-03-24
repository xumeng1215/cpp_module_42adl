#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(Array const &other);
	Array &operator=(Array const &other);
	T &operator[](unsigned int index);

	unsigned int size() const;

	class OutOfLimitsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"
