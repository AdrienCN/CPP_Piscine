#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << CAT << "Welcome to this new CAT" << CAT << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const & src)
{
	std::cout << CAT << "Welcome to this new CAT" << CAT << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat const & src)
{
	this->type = src.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << CAT << "The Cat left the room..." << CAT << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat says : \t Mew! Mew! (mewing noise)" << std::endl;
}
