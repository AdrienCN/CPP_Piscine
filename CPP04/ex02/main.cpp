#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	Dog dog;
	Animal *other = new Dog();

	std::cout << "\t***********Showing DEEP_COPY **************" << std::endl;	
	std::cout << "(" << &dog << ")";
	dog.printBrain();
	std::cout << "(" << &other << ")";
	other->printBrain();
	other->makeSound();
	delete other;
	std::cout << std::endl << "\t ****************************" << std::endl << std::endl;
	
	Cat cat;
	other = new Cat(cat);
	std::cout << "(" << &other << ")";
	other->printBrain();
	std::cout << "(" << &cat << ")";
	cat.printBrain();
	std::cout << std::endl;
	std::cout << "\t***********Showing ARRAY **************" << std::endl;
	delete other;
	Animal *array[6];
	for (int i = 0; i < 6; i ++)
	{
		if (i < 6 / 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << "(" << i  << ") ";
		array[i]->makeSound();
		std::cout << "(" << i  << ") ";
		array[i]->printBrain();
		std::cout << std::endl;
	}
	for (int i = 0; i < 6; i ++)
	{
		std::cout << "(" << i  << ") ";
		delete array[i];
		std::cout << std::endl;
	}
	return 0;
}
