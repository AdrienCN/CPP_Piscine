#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << WRONG << "A WRONG_CAT is here " << WRONG << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
	std::cout << WRONG << "A WRONG_CAT is here" << WRONG << std::endl;
	//*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
	this->_type = src.getType();
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
