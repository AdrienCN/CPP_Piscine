#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "... A  new WRONG_Animal appeared ..." << std::endl;
	this->type = "none";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "... A  new WRONG_Animal appeared ..." << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
	this->type = src.getType();
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "... A  WRONG_Animal died ..." << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << BRED << "I am a Wrong_Animal...." << RESET << std::endl;
}

void	WrongAnimal::setType(std::string src)
{
	this->type = src;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
