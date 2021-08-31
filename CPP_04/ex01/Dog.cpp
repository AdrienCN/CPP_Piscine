#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << DOG << " (Default) A new Doggydoggo is among us" << DOG << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src), _brain(new Brain(*src._brain))
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
	delete _brain;
	std::cout << DOG << "Bye Bye Doggo, I always prefered cats anyway.." << DOG << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog says : \t Ouaf! Ouaf! (barking noise)" << std::endl;
}
