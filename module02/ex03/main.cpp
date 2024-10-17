// #include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point p1(5.0f, 5.0f);
	Point p2(10.0f, 10.0f);
	Point p3(0.0f, 0.0f);
	Point p4(5.0f, 0.0f);

	std::cout << "Is p1 inside the triangle? " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
	std::cout << "Is p2 inside the triangle? " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;
	std::cout << "Is p3 inside the triangle? " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;
	std::cout << "Is p4 inside the triangle? " << (bsp(a, b, c, p4) ? "Yes" : "No") << std::endl;

	return 0;
}