#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#define RESET "\33[0m"
#define BRED "\33[1m\33[31m"
class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		Animal & operator=(Animal const & src);
		virtual ~Animal();
		std::string  	getType(void) const;
		void			setType(std::string type);

		virtual void	makeSound() const;
	private:

	protected:
		std::string type;
};
#endif
