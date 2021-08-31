#include <iostream>

class Fixed{
	public:
			Fixed();
			Fixed(Fixed const & src);
	Fixed &	operator=(Fixed const & src);
			~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
		int		_n;
		static const int _bits = 8;
};
