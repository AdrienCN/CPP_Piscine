#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal 	typeless;
	Dog		didier;

	didier.getType();
	didier.makeSound();
	typeless.makeSound();
	std::cout << typeless.getType() << std::endl;
	typeless.setType("BullFrog");
	std::cout << typeless.getType() << std::endl;
	return (0);
}
