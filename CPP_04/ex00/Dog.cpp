#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << DOG << "A new Doggydoggo is among us" << DOG << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const & src)
{
	std::cout << DOG << "A new Doggydoggo is among us" << DOG << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog const & src)
{
	this->type = src.getType();
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
