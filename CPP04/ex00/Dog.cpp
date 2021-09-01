#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << DOG << " (Default) A new Doggydoggo is among us" << DOG << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << DOG << "(Copy) A new Doggydoggo is among us" << DOG << std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
	this->_type = src.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << DOG << "Bye Bye Doggo, I always prefered cats anyway.." << DOG << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog says : \t Ouaf! Ouaf! (barking noise)" << std::endl;
}
