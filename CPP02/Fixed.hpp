

class Fixed{
	public:
			Fixed();
			Fixed(Fixed const & x);
	Fixed &	operator=(Fixed const & x);
			~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private:
		int		_n;
		static const int _bits = 8;
};

//const int	Fixed::_bits = 8;
