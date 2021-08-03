#include <iostream>

class Fixed{
	public:
			Fixed();
			Fixed(Fixed const & src);
			Fixed(const int src);
			Fixed(const float src);
	Fixed &	operator=(Fixed const & src);
			~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	private:
		int		_n;
		static const int _bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);
//const int	Fixed::_bits = 8;
