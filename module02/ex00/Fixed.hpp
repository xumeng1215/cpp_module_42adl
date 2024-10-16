#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _frac_bits;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &src);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
