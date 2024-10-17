#include "Point.cpp"

static float area(const Point &p1, const Point &p2, const Point &p3)
{
	return std::abs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
					 p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
					 p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) /
					2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float full_area = area(a, b, c);
	float area1 = area(point, a, b);
	float area2 = area(point, b, c);
	float area3 = area(point, a, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	else if (full_area == area1 + area2 + area3)
		return true;
	else
		return false;
}