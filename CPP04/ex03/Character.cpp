#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

Character::Character() : _materia(0), _name("No_name") 
{
}

Character::Character(std::string const & name) : _materia(0), _name(name)
{
}

Character::Character(Character const & src) 
{
	this->_name = src._name;
	this->_materia = src._materia;
	for (int i = 0; i < src._materia; i++)
			_inventory[i] = src._inventory[i]->clone();
}

Character &  Character::operator=(Character const & src)
{
	this->_name = src._name;
	this->_materia = src._materia;
	for (int i = 0; i < src._materia; i++)
		_inventory[i] = src._inventory[i]->clone();
	return *this;
}

Character::~Character()
{
}

void	Character::equip(AMateria* m)
{
	if (this->_materia < 4)
	{
		this->_inventory[_materia] = m;
		_materia++;
	}
	else
		std::cout << "Error : Can't do that : Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error : UNEQUIP : Slot [" << idx << "] does not exists val [0-3]" << std::endl;
		return;
	}
	if (idx > _materia) // ou juste if (_inventory[idx == NULL] ??? 
		std::cout << "Error : UNEQUIP : This materia slot [" << idx << "] is already empty" << std::endl;
	else
	{
		_inventory[idx] = NULL;
		_materia--;
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error : USE : Slot [" << idx << "] does not exists val [0-3]" << std::endl;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Error : UNEQUIP : This materia slot [" << idx << "] is already empty" << std::endl;
	}
	else
		_inventory[idx]->use(target);
}
