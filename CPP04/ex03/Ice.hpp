#ifndef ICE_HPP
#define ICE_HPP

#include "IMateria.hpp"

class Ice : public AMateria
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
