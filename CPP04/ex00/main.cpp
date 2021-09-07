#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal 	*dog = new Dog();
	Animal	*cat = new Cat();
	WrongAnimal *wronganimal = new WrongCat();

	std::cout << std::endl;
	
	dog->makeSound();
	dog->getType();
	
	std::cout << std::endl;
	
	cat->getType();
	cat->makeSound();
	
	std::cout << std::endl;

	wronganimal->makeSound();
	wronganimal->getType();
	

	std::cout << std::endl;
	
	delete dog;
	delete cat;
	delete wronganimal;
	return (0);
}
