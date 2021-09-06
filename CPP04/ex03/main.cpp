#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int		main(void)
{

	ICharacter *cloud = new Character("Cloud");
	IMateriaSource *src = new MateriaSource;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	cloud->equip(new Ice());
	cloud->equip(src->createMateria("fire"));
	cloud->unequip(0);

	return 0;
}
