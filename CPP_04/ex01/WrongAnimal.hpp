#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#define RESET "\33[0m"
#define BRED "\33[1m\33[31m"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const & src);
		WrongAnimal & operator=(WrongAnimal const & src);
		virtual ~WrongAnimal();
		std::string  	getType(void) const;
		void			setType(std::string type);

		virtual void	makeSound() const;
	private:

	protected:
		std::string _type;
};
#endif
