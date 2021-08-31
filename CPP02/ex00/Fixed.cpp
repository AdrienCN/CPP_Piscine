#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Constructor [DEFAULT] called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Constructor [COPY] called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Operator assignation [=] called" << std::endl;
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
	std::cout << "getRawBits function called" << std::endl;
	return this->_n;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	this->_n = raw;
}
