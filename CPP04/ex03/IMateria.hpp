#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp" 

class AMateria 
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & AMateria);
		AMateria & operator=(AMateria const & AMateria);
		~AMateria();

		std::string const & getType();

		virtual			AMateria* clone() const = 0;
		virtual void	use(ICharacter& target);

	private:

	protected:
		std::string _type;

};
#endif
