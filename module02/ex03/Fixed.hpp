#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _frac_bits;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int num);
	Fixed(const float num);

	Fixed &operator=(const Fixed &src);

	bool operator>(const Fixed &src) const;
	bool operator>=(const Fixed &src) const;
	bool operator<(const Fixed &src) const;
	bool operator<=(const Fixed &src) const;
	bool operator==(const Fixed &src) const;
	bool operator!=(const Fixed &src) const;

	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;
	static Fixed &min(Fixed &num1, Fixed &num2);
	static const Fixed &min(const Fixed &num1, const Fixed &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &max(const Fixed &num1, const Fixed &num2);

	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};
