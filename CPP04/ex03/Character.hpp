#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character: virtual public ICharacter
{
	public:
	Character();
	Character(std::string const & name);
	Character(Character const & src);
	Character & operator=(Character const & src);
	~Character();

	std::string const & getName() const;
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, ICharacter& target);

	protected:
	AMateria*	_inventory[4];
	int			_materia;
	std::string _name;

	private:

};
#endif
