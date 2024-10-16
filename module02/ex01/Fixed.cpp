#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

Fixed::Fixed(const int num)
{
	std::cout << "Integer constructor called." << std::endl;
	this->_value = num << this->_frac_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called." << std::endl;
	this->_value = static_cast<int>(roundf(num * (1 << this->_frac_bits)));
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const
{
}

const int Fixed::_frac_bits = 8;
