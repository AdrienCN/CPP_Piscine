#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

Character::Character() : _materia(0), _name("No_name") 
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _materia(0), _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;

}

Character::Character(Character const & src) 
{
	int i;

	i = 0;
	while (i < _materia)
		delete  _inventory[i];

	this->_name = src._name;
	this->_materia = src._materia;
	for (i = 0; i < src._materia; i++)
			_inventory[i] = src._inventory[i]->clone();
	while (i < 4)
		_inventory[i] = NULL;
}

Character &  Character::operator=(Character const & src)
{
	int i;
	
	i = 0;
	while (i < _materia)
			delete	_inventory[i];

	this->_name = src._name;
	this->_materia = src._materia;
	for (i = 0; i < src._materia; i++)
		_inventory[i] = src._inventory[i]->clone();
	while (i <  4)
	   _inventory[i] = NULL;	
	return *this;
}

Character::~Character()
{
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Error : EQUIP : Materia does not exists" << std::endl;
		return;
	}
	if (_materia == 4)
	{
			std::cout << "Error : EQUIP : Inventory is full" << std::endl;
			return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "EQUIP : materia [" << m->getType() << "] ";
			std::cout << "succesfully equiped in slot ["<< i << "]" << std::endl;
			break;
		}
	}
	_materia++;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error : UNEQUIP : Slot [" << idx << "] does not exists. Enter a value between [0-3]" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
		std::cout << "Error : UNEQUIP : This materia slot [" << idx << "] is already empty" << std::endl;
	else
	{
		std::cout << "succesfully unequiped [" << _inventory[idx]->getType() << "] in slot ["<< idx << "]" << std::endl;
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
		std::cout << "Error : USE : Slot [" << idx << "] does not exists. Enter a value between [0-3]" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Error : USE : This materia slot [" << idx << "] is empty" << std::endl;
	}
	else
		_inventory[idx]->use(target);
}
