#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const & src) :  AMateria(src.getType())
{
}

Ice & Ice::operator=(Ice const & src)
{
	this->_type = src.getType();
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	return (new Ice(*this)); // return (new Ice(this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
