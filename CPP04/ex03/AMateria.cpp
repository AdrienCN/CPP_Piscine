#include "AMateria.hpp"

AMateria::AMateria() : _type("none")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & src) : _type(src.getType())
{
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & src) 
{
	_type = src.getType();
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Error : AMATERIA : USE : no type materia" << std::endl;
}
