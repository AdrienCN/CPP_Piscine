#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CAT << " (Default) Welcome to this new CAT" << CAT << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << CAT << " (Copy) Welcome to this new CAT" << CAT << std::endl;
	//*this = src;
}

Cat & Cat::operator=(Cat const & src)
{
	this->_type = src.getType();
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
