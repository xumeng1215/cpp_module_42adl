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

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};
