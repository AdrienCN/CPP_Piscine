#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const & src) :  AMateria(src.getType())
{
}

Cure & Cure::operator=(Cure const & src)
{
	this->_type = src.getType();
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure(*this)); // return (new Cure(this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds*" <<  std::endl;
}
