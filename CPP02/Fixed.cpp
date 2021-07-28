#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Constructor [VOID] called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::Fixed(Fixed const & x)
{
	std::cout << "Constructor [COPY] called" << std::endl;
	*this = x;
}

Fixed & Fixed::operator=(Fixed const & x)
{
	std::cout << "Constructor [OPERATOR =] called" << std::endl;
	this->_n = x.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << 
	return this->_n;
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}
