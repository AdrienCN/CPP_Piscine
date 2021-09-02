#ifndef FIRE_HPP
#define FIRE_HPP

#include "IMateria.hpp"

class Fire : public AMateria
{
	public:
		Materia();
		Materia(Materia const & src);
		Materia & operator=(Materia const & src);
		~Materia();

		AMateria* clone();
		void		use(ICharacter& target);

	protected:

	private:

};
#endif
