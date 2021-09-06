#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator=(MateriaSource const & src);
		~MateriaSource();
		void	learnMateria(AMateria* materia);
		AMateria *createMateria(std::string const & type);
	
	private:
		AMateria*	_inventory[4];
		int			_mCount;
};
#endif
