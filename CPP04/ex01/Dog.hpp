#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define DOG "\U0001F436"
class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & src);
		Dog & operator=(Dog const & src);
		~Dog();

		void	makeSound() const;
		void			printBrain() const;

	private:
		Brain *_brain;

	protected:

};
#endif
