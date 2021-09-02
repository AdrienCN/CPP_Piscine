#ifndef WRONGCAT_HPP 
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#define WRONG "\U0001F47E" 

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & src);
		WrongCat &  operator=(WrongCat const & src);
		~WrongCat();

		virtual void makeSound(void) const;
	private:

	protected:

};
#endif
