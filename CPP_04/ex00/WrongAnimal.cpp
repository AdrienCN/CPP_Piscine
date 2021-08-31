#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("none_wrong")
{
	std::cout << "(Default) A new WRONG_Animal (" << this->_type << ")  appeared ..." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) : _type(src.getType())
{
	std::cout << "(Copy) A new WRONG_Animal (" << this->_type << ")  appeared ..." << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & src) : _type(src)
{
	std::cout << "(String) A new WRONG_Animal (" << this->_type << ")  appeared ..." << std::endl;

}
WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
	this->_type = src.getType();
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "... A  WRONG_Animal ("<< this->_type << ") died ..." << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << BRED << "WrongAnimal says: I am a Wrong_Animal...." << RESET << std::endl;
}

void	WrongAnimal::setType(std::string src)
{
	this->_type = src;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}
