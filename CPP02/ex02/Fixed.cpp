#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Assignation constructor called" << std::endl;
	this->_n = src.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const & src)
{
	Fixed res(this->toFloat() + src.toFloat());
	return (res);
}

Fixed	Fixed::operator-(Fixed const & src)
{
	Fixed res(this->toFloat() - src.toFloat());
	return (res);
}

Fixed	Fixed::operator*(Fixed const & src)
{
	Fixed res(this->toFloat() * src.toFloat());
	return (res);
}

Fixed	Fixed::operator/(Fixed const & src)
{
	Fixed res(this->toFloat() / src.toFloat());
	return (res);
}

bool 	Fixed::operator<(Fixed const & src) const
{
	if (this->_n < src.getRawBits())
		return (true);
	else
		return (false);
}

bool 	Fixed::operator<=(Fixed const & src) const
{
	if (this->_n <= src.getRawBits())
		return (true);
	else
		return (false);
}

bool 	Fixed::operator>(Fixed const & src) const
{
	if (this->_n > src.getRawBits())
		return (true);
	else
		return (false);
}

bool 	Fixed::operator>=(Fixed const & src) const
{
	if (this->_n >= src.getRawBits())
		return (true);
	else
		return (false);
}

bool 	Fixed::operator==(Fixed const & src) const
{
	if (this->_n == src.getRawBits())
		return (true);
	else
		return (false);
}

bool 	Fixed::operator!=(Fixed const & src) const
{
	if (this->_n != src.getRawBits())
		return (true);
	else
		return (false);
}

Fixed & Fixed::operator++(void)
{
	this->_n += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_n += 1;
	return tmp;
}	

int		Fixed::toInt(void) const
{
	return this->_n >> Fixed::_bits;
}


float	Fixed::toFloat(void) const
{
	return (float)this->_n / (1 << Fixed::_bits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b)
		return (a);
	else 
		return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
