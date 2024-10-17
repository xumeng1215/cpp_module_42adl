#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::~Point()
{
}

const Fixed &Point::getX(void) const
{
	return this->_x;
}

const Fixed &Point::getY(void) const
{
	return this->_y;
}

Point::Point(const float num1, const float num2) : _x(num1), _y(num2)
{
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
}

Point &Point::operator=(const Point &src)
{
	(void)src;
	return *this;
}
