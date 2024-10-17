#pragma once
#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const float num1, const float num2);
	Point(const Point &copy);
	Point &operator=(const Point &src);
	~Point();
	const Fixed &getX(void) const;
	const Fixed &getY(void) const;
};
