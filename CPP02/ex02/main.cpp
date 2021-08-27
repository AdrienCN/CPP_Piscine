#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << "a =  " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "post incr a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "post incr a = " << a << std::endl;
	
	std::cout << "b is " <<  b << std::endl;

	std::cout << "Minimun between a & b = "<< Fixed::min(a, b) << std::endl;
	
	return 0;
}
