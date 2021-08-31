#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "🧬  A  new Animal appeared 🧬 " << std::endl;
	this->type = "none";
}

Animal::Animal(Animal const & src)
{
	std::cout << "🧬  A  new Animal appeared 🧬 " << std::endl;
	*this = src;
}

Animal & Animal::operator=(Animal const & src)
{
	this->type = src.getType();
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "🧬  An Animal has gone extinct 🧬 " << std::endl;
}

void Animal::makeSound(void)
{
	std::cout << BRED << "what noise should I make I have NO TYPE ?!?!?!\" " << RESET << std::endl;
}

void	Animal::setType(std::string src)
{
	this->type = src;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
