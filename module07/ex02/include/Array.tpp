#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw OutOfLimitsException();
	}
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
	return "Index out of limits.";
}

