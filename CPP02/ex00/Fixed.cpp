#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Constructor [VOID] called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Constructor [COPY] called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = src << Fixed::_bits; // src * 2^8
	return ;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = (roundf(src * (1 << Fixed::_bits))); // (src * (1 * 2^8);
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Constructor [OPERATOR =] called" << std::endl;
	this->_n = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	return this->_n;
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << rhs.toFloat();
	return o;
}
