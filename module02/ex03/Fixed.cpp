#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Integer constructor called." << std::endl;
	this->_value = num << this->_frac_bits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called." << std::endl;
	this->_value = static_cast<int>(roundf(num * (1 << this->_frac_bits)));
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

// >, <, >=, <=, == and !=
bool Fixed::operator>(const Fixed &src) const { return this->_value > src._value; }
bool Fixed::operator>=(const Fixed &src) const { return this->_value >= src._value; }
bool Fixed::operator<(const Fixed &src) const { return this->_value < src._value; }
bool Fixed::operator<=(const Fixed &src) const { return this->_value <= src._value; }
bool Fixed::operator==(const Fixed &src) const { return this->_value == src._value; }
bool Fixed::operator!=(const Fixed &src) const { return this->_value != src._value; }

// +, -, *, and /
Fixed Fixed::operator+(const Fixed &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}
Fixed Fixed::operator-(const Fixed &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}
Fixed Fixed::operator*(const Fixed &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}
Fixed Fixed::operator/(const Fixed &src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

// pre-increment and post-increment, pre-decrement and post-decrement
Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value--;
	return temp;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _frac_bits;
}

float Fixed::toFloat(void) const
{
	// std::cout << "Calling toFloat() this value is " << this->_value << std::endl;
	return static_cast<float>(_value) / (1 << _frac_bits);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	return ((num1._value < num2._value) ? num1 : num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return ((num1._value < num2._value) ? num1 : num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	return ((num1._value > num2._value) ? num1 : num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return ((num1._value > num2._value) ? num1 : num2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
