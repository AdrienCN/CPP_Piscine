#include <iostream>

class Fixed{
	public:
			Fixed();
			Fixed(Fixed const & src);
			Fixed(const int src);
			Fixed(const float src);
	Fixed &	operator=(Fixed const & src);
			~Fixed();
	
	Fixed 	operator+(Fixed const & src);
	Fixed 	operator-(Fixed const & src);
	Fixed 	operator*(Fixed const & src);
	Fixed 	operator/(Fixed const & src);

	bool	operator>(Fixed const & src) const;
	bool	operator<(Fixed const & src) const;
	bool	operator>=(Fixed const & src) const;
	bool	operator<=(Fixed const & src) const;
	bool	operator==(Fixed const & src) const;
	bool	operator!=(Fixed const & src) const;

	Fixed & operator++(void);
	Fixed & operator--(void);

	Fixed	operator--(int);
	Fixed	operator++(int);

	static Fixed const & min(Fixed const & a, Fixed const & b);
	static Fixed const & max(Fixed const & a, Fixed const & b);

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
