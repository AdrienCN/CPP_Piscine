#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"

int main(void)
{
	Dog dog;
	Animal *other = new Dog(dog);

	(void)dog;
	(void)other;
	delete other;
	return 0;
}
