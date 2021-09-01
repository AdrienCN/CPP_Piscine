#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal(void) : _type("none")
{
	std::cout << "🧬  (Default) A new Animal (" << this->_type << ") appeared 🧬 " << std::endl;
}

Animal::Animal(Animal const & src) : _type(src.getType())
{
	//*this = src;
	std::cout << "🧬  (Copy) A new Animal (" << this->_type << ") appeared 🧬 " << std::endl;
}

Animal::Animal(std::string const & src) : _type(src)
{
	std::cout << "🧬  (String) A new Animal (" << this->_type << ") appeared 🧬 " << std::endl;
}

Animal & Animal::operator=(Animal const & src)
{
	this->_type = src.getType();
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "🧬  An Animal  (" << this->_type << ") has gone extinct 🧬 " << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << BRED << "Animal("<< this->_type << ") says: \t Wtf have you done Darwin?  I have NO type ?!?!?!\" " << RESET << std::endl;
}

void	Animal::setType(std::string src)
{
	this->_type = src;
}

void	Animal::printBrain() const
{
	std::cout << "This is never meant to be printed" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
