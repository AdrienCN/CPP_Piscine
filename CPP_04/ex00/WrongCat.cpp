#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << WRONG << "A WRONG_CAT is here " << WRONG << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << WRONG << "A WRONG_CAT is here" << WRONG << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
	this->type = src.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << WRONG << "The WRONG_CAT is gone..." << WRONG << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat says : \t Ouaf! Ouaf! (what is wrong with this guy?)" << std::endl;
}
