#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called." << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called." << std::endl; }

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

bool Fixed::operator>(const Fixed &src) const { return this->_value > src._value; }
bool Fixed::operator>=(const Fixed &src) const { return this->_value >= src._value; }
bool Fixed::operator<(const Fixed &src) const { return this->_value < src._value; }
bool Fixed::operator<=(const Fixed &src) const { return this->_value <= src._value; }
bool Fixed::operator==(const Fixed &src) const { return this->_value == src._value; }
bool Fixed::operator!=(const Fixed &src) const { return this->_value != src._value; }

Fixed Fixed::operator+(const Fixed &src) const { return Fixed(this->_value + src._value); }
Fixed Fixed::operator-(const Fixed &src) const { return Fixed(this->_value - src._value); }
Fixed Fixed::operator*(const Fixed &src) const { return Fixed((this->_value * src._value) >> this->_frac_bits); }
Fixed Fixed::operator/(const Fixed &src) const { return Fixed((this->_value << this->_frac_bits) / src._value); }


int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called." << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called." << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _frac_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _frac_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

const int Fixed::_frac_bits = 8;
