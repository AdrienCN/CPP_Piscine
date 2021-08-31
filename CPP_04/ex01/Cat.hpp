#ifndef CAT_HPP 
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define CAT "\U0001F63A" 
class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		Cat &  operator=(Cat const & src);
		~Cat();

		virtual void makeSound(void) const;
	
	private:
		Brain *_brain;

	protected:

};
#endif
