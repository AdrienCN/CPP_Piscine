#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	Dog dog;
	Animal *other = new Dog(dog);
	
	std::cout << "(" << &dog << ")";
	dog.printBrain();
	std::cout << "(" << &other << ")";
	other->printBrain();
	delete other;
	std::cout << std::endl << "\t ****************************" << std::endl << std::endl;
	
	Cat cat;
	other = new Cat(cat);
	std::cout << "(" << &other << ")";
	other->printBrain();
	std::cout << "(" << &cat << ")";
	cat.printBrain();

	return 0;
}
