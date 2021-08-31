#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal 	animal;
	Dog		dog;
	Cat		cat;

	WrongAnimal wronganimal;
	WrongCat wrongcat;
	
	std::cout << animal.getType() << std::endl;
	animal.makeSound();
	std::cout << dog.getType() << std::endl;
	dog.makeSound();
	std::cout << cat.getType() << std::endl;
	cat.makeSound();
	std::cout << wronganimal.getType() << std::endl;
	wronganimal.makeSound();
	std::cout << wrongcat.getType() << std::endl;
	wrongcat.makeSound();

	return (0);
}
