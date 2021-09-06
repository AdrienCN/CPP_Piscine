#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_mCount = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (_mCount == 4)
	{
		std::cout << "This MateriaSource is full" << std::endl;
		return;
	}
	_inventory[_mCount] =  materia;
	std::cout << "Learnt new materia [" << _inventory[_mCount]->getType() << "] in slot [" << _mCount << "]" << std::endl;
	_mCount++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _mCount; i++)
	{
		if (type.compare(_inventory[i]->getType()) == 0)
		{
			std::cout << "Cloning [" << _inventory[i]->getType() << "] materia" << std::endl;
			return (_inventory[i]->clone());
		}
	}
	std::cout << "Unknown type of materia" << std::endl;
	return (0);
}